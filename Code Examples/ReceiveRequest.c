

//Post Receive Request

int ibv_post_recv(struct ibv_qp *qp, struct ibv_recv_wr *wr,
                  struct ibv_recv_wr **bad_wr);

//Post Send Request

int ibv_post_send(struct ibv_qp *qp, struct ibv_send_wr *wr,
                  struct ibv_send_wr **bad_wr);                  

/* Warning: bad_wr is mandatory; It will be assigned with the address of 
the Receive Request that its posting failed */

struct ibv_recv_wr {
	uint64_t wr_id;           // Private context, available in the corresponding Work Completion
	struct ibv_recv_wr *next; // Address of the next Receive Request. NULL in the last Request
	struct ibv_sge *sg_list;  // Array of scatter elements
	int num_sge;              // Number of elements in sg_list
};
