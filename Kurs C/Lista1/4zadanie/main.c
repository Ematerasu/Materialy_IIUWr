#include <stdio.h>
#include <stdlib.h>

void kwadratliczb(int &x)
{
    int s = 0;
    int k;
    while(x>0)
    {
    	k = x%10;
    	s += k*k;
    	x = x/10;
	}
    x = s;
}

bool Wesola(int x)
{
	vector<int> vec;
	while(x!=1)
	{
		vec.push_back(x);
		kwadratliczb(x);

		if(x==1) return true;

		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]==x) return false;
		}
	}
	return true;



}

int main()
{

    int Liczby[10];
    int Liczba;

    printf("Podaj liczbe: ");
    scanf("&d",Liczba);

    bool ok=true;

	for(int i=Liczba;i<Liczba+10;i++)
	{

    	if(Wesola(i))
    	{
    		cout<<i;
    		ok=false;
    		break;
		}

	}
	if(ok) cout<<"BRAK";


    return 0;
}
