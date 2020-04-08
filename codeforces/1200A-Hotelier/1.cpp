#include<iostream>
#include<string>
int main(){
	int n;
	bool rooms[10] = {0};
	int cl = 0, cr = 9, l;
	scanf("%d", &n);
	char c;
	for(int i = 0; i < n; ++i ){
		std::cin >> c;
		if ( c == 'R') {
			while (rooms[cr]) cr--;
			rooms[cr] = true;
		} else if ( c == 'L') {
			while (rooms[cl]) cl++;
			rooms[cl] = true;
		} else  {
			l = (int)c - 48;
			rooms[l] = false;
			if(l>cr) cr = l;
			if(l<cl) cl = l;
		}
	
}

	for(int i = 0; i < 10; ++i){
		printf("%d", rooms[i]);
	}	printf("\n");
	return 0;
}
