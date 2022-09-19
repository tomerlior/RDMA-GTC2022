#define size_t int 
#define uint64_t int
#define uint32_t int
struct ibv_pd *pd;
struct ibv_mr *mr;

//Scatter Gather Entry

struct ibv_sge {
	uint64_t addr; // Start address of the memory buffer (registered memory)
	uint32_t length; // Size (in bytes) of the memory buffer
	uint32_t lkey;   // lkey of Memory Region associated with this memory buffer
};












//Post Send

int ibv_post_send(struct ibv_qp *qp, struct ibv_send_wr *wr,
                  struct ibv_send_wr **bad_wr);
struct ibv_send_wr {
	uint64_t wr_id;            // Private context that will be available in the corresponding Work Completion
	struct ibv_send_wr *next;  // Address of the next Send Request. NULL in the last Send Request
	struct ibv_sge *sg_list;   // Array of scatter/gather elements
	int num_sge;               // Number of elements in sg_list
	enum ibv_wr_opcode opcode; // The opcode to be used
	int send_flags;            // Send flags. Or of the following flags:

    /* IBV_SEND_FENCE – Prevent process this Send Request until the processing of previous RDMA 
    //                   Read and Atomic operations were completed.
    //IBV_SEND_SIGNALED – Generate a Work Completion after processing of this Send Request ends
    //IBV_SEND_SOLICITED – Generate Solicited event for this message in remote side
    IBV_SEND_INLINE  - allow the low-level driver to read the gather buffers*/

	uint32_t imm_data;  // Send message with immediate data (for supported opcodes)
union {
	 struct {                           // Attributes for RDMA Read and write opcodes
		uint64_t remote_addr;      // Remote start address (the message size is according to the S/G entries)
		uint32_t rkey;             // rkey of Memory Region that is associated with remote memory buffer
	 } rdma;
	 struct {                           // Attributes for Atomic opcodes 
		uint64_t remote_addr;      // Remote start address (the message size is according to the S/G entries)
		uint64_t compare_add;      // Value to compare/add (depends on opcode)
		uint64_t swap;             // Value to swap if the comparison passed
		uint32_t rkey;             // rkey of Memory Region that is associated with remote memory buffer
	} atomic;
//…
}
};

