#include <iostream>
#include <vector>
#include <string>
//git test2
usingnamespace std;

int main()
{
//输入（n 是变量数加一，m是限制条件数加一；）
	int m,n;
	cout << "Read me" << endl;
	cout << "Before using this program, you should make sure that the problem is 'maximum' form and all the constrains are equation form.One line one contraint.And the last line of the coefficient matrix is belong to objective function."<<endl;

	cout << "Please input the number of constraints : m = " << endl;
	cin>>m;
	cout << "m = " << m << endl;
	m++;
	cout << "Please input the number of variables : n = " << endl;
	cin >> n;
	cout << "n = " << n << endl;
	n++;
	float array[m][n] = {0};
	cout << "Please input the matrix of coefficients" << endl;
	for (int i = 0; i < m;i++){
		for (int j = 0; j < n;j++){
			cin >> array[i][j];
		}
	}
	//选出基变量与非基变量（基变量有m个）选出M个基变量；
	//需要注意的是，最后一行是判别数对应的行；
    int bv_sub[m-1]={0};      //基变量的下标集；
	cout << "Please input the subscript of basic variables:";
	for (int i = 0;i < m - 1; i++){
		cin >> bv_sub[i];
		bv_sub[i]--;
	}
	float win,fun, b[n] = {0};
	float sp = 20200412;
	while(1){
//将基变量对应的矩阵进行单位化；


//进行高斯消去：
for (int i = 0; i < m - 1; i++)
{
	//1. 采用GAUSS方法；先保证对角元素非零，如果是0，就进行初等行变换；
	if (array[i][bv_sub[i]] == 0)
	{
		//flag = 0;
		//s=-s;
		for (int j = 1; j < m - i - 1; j++)
		{

			if (array[i + j][bv_sub[i]] != 0)
			{
				//flag = 1;
				//	printf("%d\n",flag);
					for(int k=0;k<n;k++){
						b[k]=array[i][k];
						array[i][k]=array[i+j][k];
						array[i+j][k]=b[k];
					} 
					
					//为了节省时间，找到一个交换数值就可以停止了；
				break;
				}
				//if(flag==0) {
					//printf("矩阵不可逆\n");
					//return 0;
					//}
			}
		}

		  //2. 正式进行消去；
		win = array[i][bv_sub[i]];
		for (int k = 0; k < n; k++)
		{
			//cout << i << ' ' << bv_sub[i] << ' ' << array[i][k] << ' ' << array[i][bv_sub[i]] << endl;
			array[i][k] = array[i][k] / win; 	
			   }
	   	    for (int j=-i;j<m-i;j++){
	   	    	if(j==0){
	   	    		continue;
				   }
			   //t=array[i+j][bv_sub[i]/array[i][bv_sub[i];
				   fun = array[i + j][bv_sub[i]];
				   for (int k = 0; k < n; k++)
				   {
					   //sp = array[i][k] * array[i + j][k];
					   // cout << i+j<<' ' <<k <<' '<<sp << endl;
					   array[i + j][k] = array[i + j][k] - array[i][k] * fun;
	   		     	
			   }
			   //printf(" 计算乘数：%.2f\n",t);
	   			    	
		                 printf("\n");
	   		
		   } 
		   
	  }
	for (int i1=0;i1<m;i1++){
		                	for (int j1=0;j1<n;j1++){
	                 			printf("%.1f ",array[i1][j1]);
	                			if (j1==n-1) printf("\n");
	                    	}
	                     }
	for (int i = 0; i < m - 1;i++){
		  cout <<"x"<<bv_sub[i] +1<<" = "<<array[i][n-1] <<endl;
	  }

// 选出晋级变量；
        int min = 0, p = -1;
    for (int i = 0; i < 6;i++)
    {
        if(array[m-1][i] < min ){
            min = array[m-1][i];
            p = i;//p就是晋级变量的下标；
        }
        //cout << array[0][i] << endl;  
}
    if(p == -1) {
        cout << "Already optimal" << endl;
		return 0;
    }

//找出离基变量；
    float f_min;
    int q = -1;
    for (int i = 0; i < m-1 ;i++){
        if(array[i][p]>0){
            f_min = array[i][n-1] / array[i][p];
			q = i;
            break;
        }
    }
    for (int i = 0; i < m-1;i++){
        if(array[i][p]>0){
            if(f_min>(array[i][n-1] / array[i][p])){
                f_min = array[i][n-1] / array[i][p];
                q = i;//q就是离基变量下标；
            }
        }
    }
    if(q==-1){
        cout<<"Without boundary"<<endl;
		return 0;
    } 
//进行替换：把bv_sub[]中的q——>p
	bv_sub[q] = p;
	
	
	  }
	
		  
}

