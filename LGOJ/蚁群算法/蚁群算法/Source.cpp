/* #include "stdafx.h" */
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int	N_ANT_COUNT = 60;           /* 蚂蚁数量，一般取值原则为：城市数量 / 蚂蚁数量 = 1.5左右 */
const int	N_CITY_COUNT = 92;           /* 城市数量 */
const int	N_IT_COUNT = 10000;        /* 迭代次数，就是搜索次数 */


const double	DB_Q = 100;          /* 总的信息素 */
const double	DB_ALPHA = 1;            /* 信息素重要程度 */
const double	DB_BETA = 3;            /* 这个数越大，则蚂蚁往信息素大的地方走的概率就越大 */

const double DB_ROU = 0.5;                      /* 环境信息素挥发速度 */


int besttour[N_CITY_COUNT];                     /* 最佳路径列表 */

												/* 获得指定范围内的一个随机数 */
double rnd(int low, double uper)
{
	double p = (rand() / (double)RAND_MAX) * ((uper)-(low)) + (low);
	return(p);
};

/* 获得指定上限范围内的一个随机数 */
int rnd(int uper)
{
	return(rand() % uper);
};

/* tsp地图信息，包含了信息素，城市距离，和信息素变化矩阵 */
class GInfo
{
public:
	double	m_dDeltTrial[N_CITY_COUNT][N_CITY_COUNT];       /* 临时保存信息素，更新环境信息素的时候使用，每只蚂蚁周游完各个城市后开始计算 */
	double	m_dTrial[N_CITY_COUNT][N_CITY_COUNT];           /* 城市间的信息素，就是环境信息素 */
	double	distance[N_CITY_COUNT][N_CITY_COUNT];           /* 城市间距离 */
};


GInfo Map;

/* 定义蚂蚁类 */
class ant
{
private:
	int ChooseNextCity();                   /*选择下一个城市 */


	double	prob[N_CITY_COUNT];             /* 临时变量数组，选择下一个城市的时候，保存各个城市被选中的概率值 */
	int	m_nCityCount;                   /* 记录蚂蚁已经走过的城市数目 */
	int	AllowedCity[N_CITY_COUNT];      /* 没有走过的城市，数组索引对应城市编号 */
public:
	double	m_dLength;
	double	m_dShortest;
	int	tabu[N_CITY_COUNT];             /* 记录走过的城市，里面存的是城市的编号，数组索引表示走的顺序。 */
public:
	ant();
	void addcity(int city);


	void Clear();


	void UpdateResult();


	void move();


	void move2last();
};

/* 只剩下一个城市没走过时才调用，直接移动到最后一个城市 */
void ant::move2last()
{
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		if (AllowedCity[i] == 1)
		{
			addcity(i);
			break;
		}
	}
}


/* 清空数据，蚂蚁周游完各个城市后，要重新开始周游各个城市时调用 */
void ant::Clear()
{
	m_dLength = 0;
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		prob[i] = 0;
		AllowedCity[i] = 1;
	}

	int i = tabu[N_CITY_COUNT - 1]; /* 用最后一个城市作为出发城市 */
	m_nCityCount = 0;
	addcity(i);
}


/* 初始化 */
ant::ant()
{
	m_dLength = m_dShortest = 0;
	m_nCityCount = 0;

	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		AllowedCity[i] = 1;
		prob[i] = 0;
	}
}


/* 增加一个城市到走过的城市数组中，并改变没走过的城市数组中的标志 */
void ant::addcity(int city)
{
	/* add city to tabu; */
	tabu[m_nCityCount] = city;
	m_nCityCount++;
	AllowedCity[city] = 0;
}


int ant::ChooseNextCity()
{
	/*
	* Update the probability of path selection
	* select a path from tabu[m_nCityCount-1] to next
	*/

	int	j = 10000;
	double	temp = 0.0;

	int curCity = tabu[m_nCityCount - 1]; /* 当前走到那个城市了 */

										  /* 先计算当前城市和没有走过的城市，两两之间的信息素的总和 */
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		if (AllowedCity[i] == 1)
		{
			temp = temp + pow((1.0 / Map.distance[curCity][i]), DB_BETA) * pow((Map.m_dTrial[curCity][i]), DB_ALPHA);
		}
	}

	/* 计算没有走过的城市被选中的概率 */
	double sel = 0;
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		if (AllowedCity[i] == 1)
		{
			prob[i] = pow((1.0 / Map.distance[curCity][i]), DB_BETA) * pow((Map.m_dTrial[curCity][i]), DB_ALPHA) / temp;
			sel += prob[i];
		}
		else {
			prob[i] = 0;
		}
	}


	/*下面的操作实际上就是遗传算法中的轮盘选择 */
	double	mRate = rnd(0, sel);
	double	mSelect = 0;
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		if (AllowedCity[i] == 1)
		{
			mSelect += prob[i];
		}

		if (mSelect >= mRate)
		{
			j = i;
			break;
		}
	}


	/* 这种情况只有在temp=0.0的时候才会出现 */
	if (j == 10000)
	{
		for (int i = 0; i < N_CITY_COUNT; i++)
		{
			if (AllowedCity[i] == 1)
			{
				j = i;
				break;
			}
		}
	}

	return(j);
}


/* 计算周游完城市后，走过的路径长度 */
void ant::UpdateResult()
{
	/* Update the length of tour */
	for (int i = 0; i < N_CITY_COUNT - 1; i++)
	{
		m_dLength += Map.distance[tabu[i]][tabu[i + 1]];
	}

	m_dLength += Map.distance[tabu[N_CITY_COUNT - 1]][tabu[0]]; /* 最后城市和开始城市间的距离 */
}


/* 移动到下一个城市 */
void ant::move()
{
	/* the ant move to next town and add town ID to tabu. */
	int n = ChooseNextCity();
	addcity(n);
}


class project
{
public:

	double	m_dLength;
	ant	ants[N_ANT_COUNT];


public:
	project();

	void UpdateTrial();


	void initmap();


	void GetAnt();


	void StartSearch();
};


/*
* 更新环境信息素
* 这里采用的是 ANT-CYCLE 模式，即每只蚂蚁周游完城市后才更新
* 还有其他方式为蚂蚁每走一个城市就更新一次，经过试验表明，周游完后才更新比较好
*/
void project::UpdateTrial()
{
	/* calculate the changes of trial information */
	int	m = 0;
	int	n = 0;

	for (int i = 0; i < N_ANT_COUNT; i++)                 /* 计算每只蚂蚁在两两城市间留下的信息素，蚂蚁走过的路径越短，留下的信息素数值越大 */
	{
		for (int j = 0; j < N_CITY_COUNT - 1; j++)    /* 计算两两城市间的信息素 */
		{
			m = ants[i].tabu[j];
			n = ants[i].tabu[j + 1];

			Map.m_dDeltTrial[m][n] += DB_Q / ants[i].m_dLength;
			Map.m_dDeltTrial[n][m] += DB_Q / ants[i].m_dLength;
		}

		/* 最后城市到开始城市间的信息素 */
		m = ants[i].tabu[N_CITY_COUNT - 1];
		n = ants[i].tabu[0];

		Map.m_dDeltTrial[m][n] += DB_Q / ants[i].m_dLength;
		Map.m_dDeltTrial[n][m] += DB_Q / ants[i].m_dLength;
	}


	/* 最新的环境信息素 = 消失掉的信息素 +  新留下的信息素 */
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			Map.m_dTrial[i][j] = (DB_ROU * Map.m_dTrial[i][j] + Map.m_dDeltTrial[i][j]);
			Map.m_dDeltTrial[i][j] = 0;
		}
	}
}


/* 初始化 */
void project::initmap()
{
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			Map.m_dTrial[i][j] = 1;
			Map.m_dDeltTrial[i][j] = 0;
		}
	}
}


project::project()
{
	/* initial map */
	initmap();
	m_dLength = 10e9;

	struct city
	{
		int	num;
		double	x;
		double	y;
	} cc[N_CITY_COUNT];

	/* 北京-天津城市坐标，数据来自百度地图 */
	double x_Ary[92] =
	{
		116.403438, 116.417003, 116.274870, 116.016033, 116.227731, 116.392931, 116.400494, 116.698904, 116.078663, 116.335107,
		116.372616, 116.196307, 116.406274, 116.406274, 116.376972, 116.334877, 117.262423, 117.152828, 117.319770, 117.256029,
		117.173805, 116.631465, 116.682471, 116.694698, 117.284599, 116.834458, 116.817818, 116.912755, 116.015528, 116.044506,
		116.256924, 116.988837, 116.419671, 116.407951, 116.447234, 116.433796, 116.400582, 116.417003, 116.395480, 116.343376,
		116.347634, 116.403092, 116.348822, 116.388222, 116.501591, 116.404928, 116.398488, 116.532576, 116.409248, 116.488036,
		116.554850, 116.304980, 116.214833, 116.200407, 116.313710, 116.324710, 116.326379, 116.103331, 116.293700, 116.158462,
		116.127118, 116.358986, 116.232484, 116.192635, 116.215484, 116.037320, 116.093809, 115.781250, 115.952929, 115.940343,
		115.606468, 115.706057, 117.466929, 117.017184, 117.017184, 117.448210, 117.410073, 117.519154, 117.188130, 117.172324,
		117.101021, 117.193571, 117.668900, 117.204471, 117.221004, 117.716281, 117.547861, 117.481279, 117.200692, 117.831600,
		117.199567, 117.286958
	};

	double y_Ary[92] =
	{
		39.924455, 39.886474, 39.998475, 40.364233, 40.255906, 39.941975, 39.999603, 40.187838, 40.299791, 40.320998,
		40.191595, 40.236241, 40.187238, 40.187238, 40.110177, 39.502581, 40.222785, 40.086212, 40.189006, 40.266759,
		40.249042, 40.381134, 40.401514, 40.459545, 40.66035,  40.559149, 40.550312, 40.385444, 40.554295, 40.344582,
		40.666794, 40.270992, 39.953084, 39.906181, 39.884502, 39.907267, 39.916702, 39.886474, 39.932909, 39.947735,
		39.950257, 39.932079, 39.912174, 39.880237, 39.874106, 40.012344, 39.989306, 39.916648, 39.982398, 39.950229,
		40.02567,  40.018229, 40.007659, 40.001879, 39.925473, 39.948412, 39.922649, 40.11507,	39.816754, 39.800961,
		39.869091, 39.841958, 39.857906, 39.960973, 39.917498, 39.911474, 39.875627, 39.615459, 39.801902, 39.69431,
		39.644162, 39.847687, 39.02545,	 39.1409,   39.162205, 40.246643, 40.050992, 39.292482, 39.098637, 39.098374,
		39.14468,  39.160001, 39.01517,	 39.140409, 39.175574, 38.98334,  40.192761, 39.192409, 39.110526, 39.014349,
		39.147345, 40.100119
	};

	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		cc[i].x = x_Ary[i];
		cc[i].y = y_Ary[i];
		cc[i].num = i;
	}


	/*
	* 计算两两城市间距离,一纬度间距111km，一经度间距111*cosαkm 天津-北京地区α取40°
	* 最短路径约为
	*/
	for (int i = 0; i < N_CITY_COUNT; i++)
	{
		for (int j = 0; j < N_CITY_COUNT; j++)
		{
			Map.distance[i][j] = (double)(sqrt(pow((cc[i].x - cc[j].x) * 111 * 0.766, 2) + pow((cc[i].y - cc[j].y) * 111, 2)) + 0.5);
		}
	}
}


void project::GetAnt()
{
	/* 初始化随机种子 */
	srand((unsigned)time(NULL));

	/* 为每只蚂蚁随机分配一个出发城市 */
	int city = 0;
	for (int i = 0; i < N_ANT_COUNT; i++)
	{
		city = rnd(N_CITY_COUNT);
		ants[i].addcity(city);
	}
}


void project::StartSearch()
{
	/* begin to find best solution */
	int	max = 0; /* every ant tours times */
	double	temp;
	int	temptour[N_CITY_COUNT];

	double dbMin = 0.0;

	while (max < N_IT_COUNT)
	{
		dbMin = 100000000.0; /* 本次叠迭中的最小路径长度 */

		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			for (int i = 0; i < N_CITY_COUNT - 1; i++)
			{
				ants[j].move();
			}
		}

		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			ants[j].move2last();
			ants[j].UpdateResult(); /* 计算路径总长度 */
		}

		/* find out the best solution of the step and put it into temp */
		temp = ants[0].m_dLength;
		for (int t = 0; t < N_CITY_COUNT; t++)
		{
			temptour[t] = ants[0].tabu[t];
		}

		for (int j = 0; j < N_ANT_COUNT; j++)
		{
			if (temp > ants[j].m_dLength)
			{
				temp = ants[j].m_dLength;
				for (int t = 0; t < N_CITY_COUNT; t++)
				{
					temptour[t] = ants[j].tabu[t];
				}
			}

			if (dbMin > ants[j].m_dLength)
			{
				dbMin = ants[j].m_dLength;
			}
		}

		if (temp < m_dLength)
		{
			m_dLength = temp;
			for (int t = 0; t < N_CITY_COUNT; t++)
			{
				besttour[t] = temptour[t];
			}
		}

		printf("%d : %.0f\n", max, m_dLength);

		UpdateTrial();                          /* 全部蚂蚁遍历各个城市后，更新环境信息素 */

		for (int j = 0; j < N_ANT_COUNT; j++) /* 再搜索一次 */
		{
			ants[j].Clear();
		}

		max++;
	}

	printf("The shortest toure is : %f\n", m_dLength);

	for (int t = 0; t < N_CITY_COUNT; t++)
	{
		printf(" %d ", besttour[t] + 1); /*输出数字为表格中对应序列*/
	}
}


/* 主程序入口 */
int main()
{
	project TSP;
	TSP.GetAnt();
	TSP.StartSearch();

	getchar();
	system("pause");
	return(0);
}


