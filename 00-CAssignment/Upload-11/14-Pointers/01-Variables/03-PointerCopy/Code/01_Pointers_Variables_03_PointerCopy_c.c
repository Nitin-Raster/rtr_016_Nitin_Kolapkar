#include <stdio.h>

int main(void)
{
	int num_nkk;
	int *ptr_nkk;
	int *copy_ptr_nkk;

	 //code
	num_nkk = 5;
	ptr_nkk = &num_nkk;

	printf("\n\n");
	printf("******** BEFORE copy_ptr = ptr ********\n\n");
	printf(" num_nkk			= %d\n", num_nkk);
	printf(" &num_nkk			= %p\n", &num_nkk);
	printf(" *(&num_nkk)			= %d\n", *(&num_nkk));
	printf(" ptr				= %p\n", ptr_nkk);
	printf(" *ptr				= %d\n", *ptr_nkk);

	//'ptr_nkk' is an integer variable... that it can hold the address  of any integer variable only
	//'copy_ptr_nkk' is another integer pointer variable
	//If ptr_nkk = &num_nkk ... 'ptr' will contain address of integer variable 'num_nkk'
	//If 'ptr_nkk' is assigned to 'copy_ptr_nkk', 'copy_ptr_nkk' will also contain address of integer variable 'num_nkk'
	//Hence, now, both 'ptr_nkk' and 'copy_ptr_ckk' will point to 'num'....

	copy_ptr_nkk = ptr_nkk; // copy_ptr_nkk = &num

	printf("\n\n");
	printf("******** AFTER copy_ptr_nkk = ptr_nkk ********\n\n");
	printf(" num_nkk			= %d\n", num_nkk);
	printf(" &num_nkk			= %p\n", &num_nkk);
	printf(" *(&num_nkk)			= %d\n", *(&num_nkk));
	printf(" ptr				= %p\n", ptr_nkk);
	printf(" *ptr				= %d\n", *ptr_nkk);
	printf(" copy_ptr			= %p\n", copy_ptr_nkk);
	printf(" *copy_ptr			= %d\n", *copy_ptr_nkk);

	return(0);
}
