
// Polling for work completion

int ibv_poll_cq(struct ibv_cq *cq, int num_entries, struct ibv_wc *wc);

//Work Completion for each entry

struct ibv_wc {
	uint64_t wr_id;                // Private context that was posted in the corresponding Work Request
	enum ibv_wc_status status;     // The status of the Work Completion
	enum ibv_wc_opcode opcode;     // The opcode of the Work Completion
	uint32_t vendor_err;           // Vendor specific error syndrome
	uint32_t byte_len;             // Number of bytes that were received
	uint32_t imm_data;             // Immediate data, in network order, if the flags indicate that such exists
	uint32_t qp_num;               // The local QP number that this Work Completion ended in
	uint32_t src_qp;               // The remote QP number
	int wc_flags;                  // Work Completion flags. Or of the following flags:

     /* IBV_WC_GRH – Indicator that the first 40 bytes of the receive buffer(s) contain a valid GRH
      IBV_WC_WITH_IMM – Indicator that the received message contains immediate data */

	uint16_t pkey_index;
	uint16_t slid;                                // For UD QP: the source LID
	uint8_t sl;                                     // For UD QP: the source Service Level
	uint8_t dlid_path_bits;                      // For UD QP: the destination LID path bits
};


// typical completion statuses

IBV_WC_SUCCESS – Operation completed successfully
IBV_WC_LOC_LEN_ERR – Local length error when processing SR or RR
IBV_WC_LOC_PROT_ERR – Local Protection error; S/G entries doesn’t point to a valid MR
IBV_WC_WR_FLUSH_ERR – Work Request flush error; it was processed when the QP was in Error state

IBV_WC_RETRY_EXC_ERR – Retry exceeded; the remote QP didn’t send any ACK/NACK, even after
            message retransmission                                                                            

IBV_WC_RNR_RETRY_EXC_ERR – Receiver Not Ready; a message that requires a Receive Request
           was sent, but isn’t any RR in the remote QP, even after message retransmission
