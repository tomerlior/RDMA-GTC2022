#define size_t int 
struct ibv_pd *pd;
struct ibv_mr *mr;



// Memory Reg Example

struct ibv_mr *ibv_reg_mr(struct ibv_pd *pd,
					    void *addr, size_t length,
					    enum ibv_access_flags access); 

/* Notice the following fields in struct ibv_mr:
rkey  - The remote key of this MR
lkey  - The local key of this MR
addr – The start address of the memory buffer that this MR registered
length – The size of the memory buffer that was registered
*/

//Deregister a Memory Region

int ibv_dereg_mr(struct ibv_mr *mr); 




/*
This verb should be called if there is no outstanding 
Send Request or Receive Request that points to it
*/