 #include <stdio.h>
 #include <stdlib.h>
 
 struct node{
 	char nama[15];
 	int nrp;
 	struct node *link;
 };
 
 	struct node *head;
	int l;
	struct node *appear;
	struct node *temp; 
 	
struct node *alloc_memory(){
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		return NULL;
	}else{
		ptr->link=NULL;
		return ptr;
	}
}

 void print(){
 	appear = head;
 	while(appear!=NULL){
 		printf("\nNama :%s\n",appear->nama);
 		printf("NRP  :%d\n\n",appear->nrp);
 		appear=appear->link;
	 }
 }
 

 
int main(){
	char pilihan;
	do{
		head=alloc_memory();
		printf("Nama :");
		scanf("%s",&head->nama);
		printf("NRP :");
		scanf("%d",&head->nrp);
		if(l==0){
			head->link=NULL;
			temp=head;
			l++;
		}else{
			head->link=temp;
			temp=head;
			l++;
		}
		
	printf("Lanjut Isi[Y/T]:");
	scanf("%s",&pilihan);
	}while(pilihan=='y'||pilihan=='Y');
	print();

	fflush(stdin);
	printf("\n\nPress enter to exit");
	getchar();
}

