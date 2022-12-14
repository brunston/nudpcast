#ifndef STATISTICS_H
#define STATISTICS_H

#ifndef UDPCAST_CONFIG_H
# define UDPCAST_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

typedef struct receiver_stats *receiver_stats_t;
typedef struct sender_stats *sender_stats_t;

#define allocReadStats udpc_allocReadStats
#define receiverStatsStartTimer udpc_receiverStatsStartTimer
#define receiverStatsAddBytes udpc_receiverStatsAddBytes
#define displayReceiverStats udpc_displayReceiverStats

receiver_stats_t udpc_allocReadStats(int fd, long statPeriod,
				     int printUncompressedPos,
				     int noProgress);
void udpc_receiverStatsStartTimer(receiver_stats_t);
void udpc_receiverStatsAddBytes(receiver_stats_t, unsigned long bytes);
void udpc_displayReceiverStats(receiver_stats_t, int isFinal);

#define allocSenderStats udpc_allocSenderStats
#define senderStatsAddBytes udpc_senderStatsAddBytes
#define senderStatsAddRetransmissions udpc_senderStatsAddRetransmissions
#define displaySenderStats udpc_displaySenderStats
#define senderSetAnswered udpc_senderSetAnswered

sender_stats_t udpc_allocSenderStats(int fd, FILE *logfile, long bwPeriod,
				     long statPeriod, int printUncompressedPos,
				     int noProgress);
void udpc_senderStatsAddBytes(sender_stats_t, unsigned long bytes);
void udpc_senderStatsAddRetransmissions(sender_stats_t ss, 
					unsigned int retransmissions);
void udpc_displaySenderStats(sender_stats_t,
			     unsigned int blockSize, unsigned int sliceSize,
			     int isFinal);
void udpc_senderSetAnswered(sender_stats_t ss, uint32_t clNo);


#endif
