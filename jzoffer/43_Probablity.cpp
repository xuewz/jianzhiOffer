//n个骰子的点数
//输入骰子的个数n，打印出点数之和s可能出现的概率
//s可以这样理解：第n个骰子出现的数与前面

/********************第一种，递归************/
int maxValue=6;
//总共original个骰子，还有current个没有加，当前已经加完的和为sum，骰子最大点数为maxValue,当current=1的时候，sum已经加完，
//所以对和为sum的pProbablity[sum-original]累加，即和从n~6n，对应下标从n-n~6n-n
void probablity(int original,int current,int sum,int* pProbablity){
	if(current==1)
		pProbablity[sum-original]++;
	else
	{
		for(int i=1;i<maxValue;++i)
			probablity(original,current-1,sum+i,pProbablity);
	}
}

//给sum赋初值，求每种点数和出现的次数
void probablity(int num,int* pProbablity){
	for(int i=1;i<maxValue;++i)
		probablity(num,num,i,pProbablity);
}

//有num个点数为maxValue的骰子
vector<double> printProbablity(int num){
	if(num<1)
		return;
	
	int maxSum=num*maxValue;
	int *pProbablity=new int[maxSum-num+1];
	
	for(int i=num;i<=maxValue;++i)
		pProbablity[i-num]=0;
	
	probablity(num,pProbablity);
	
	int total=pow((dobule)maxValue,num);
	vector<double> ratio;
	for(int j=num,j<=maxSum;++j)
		ratio.push_back(pProbablity[j-num]/total);
	
	delete []pProbablity;
	
	return ratio;
}

/*****************第二种循环****************/
//在一次循环中，第一个数组中的第n个数字表示穀子和为n出现的次数。在下一次循环中，我们加上一个新的穀子，此时和为n个穀子出现的次数应该等于上一次循环中穀子点数和为n-1，n-2.....n-6的次数的总和，所以我们把另一个数组的第n个数字设为前一个数组对应的第n-1，n-2.....n-6之和
vector<double> printProbablity1(int num){
	if(num<1)
		return ;
	
	int *pProbablity[2];
	pProbablity[0]=new int[maxValue*num+1];
	pProbablity[1]=new int[maxValue*num+1];
	
	for(int i=0;i<maxValue*num+1;+=i){
		pProbablity[0][i]=0;
		pProbablity[1][i]=0;
	}
	
	int flag=0;
	//对只有一个骰子的情况进行初始化
	for(int i=1;i<=maxValue;++i)
		pProbablity[flag][i]=1;
	
	//对其他n-1个骰子处理
	for(int k=2;k<=num;++k){
		for(int i=0;i<k;++i)
			pProbablity[1-flag][i]=0;
		
		for(int i=k;i<=maxValue*k;++i){
			pProbablity[1-flag][i]=0;
			for(int j=1;j<=i && j<=maxValue;++j)
				pProbablity[1-flag][i]+=pProbablity[flag][i-j];
		}
		
		flag=1-flag;
	}
	
	double total=pow((double)maxValue,num);
	vecor<double> ans;
	for(int m=num;m<=maxValue*num;++m){
		double ratio=(double)pProbablity[flag][i]/total;
		ans.push_back(ratio);
	}
	
	delete []pProbablity[0];
	delete []pProbablity[1];
	return ans;
}