#include <stdint.h>
#include <mongoose.h>



//--------------------------------------------------
// Support functions
//--------------------------------------------------

/**
 * Returns if the needle is in the haystack
 * @param needle The integer we are looking for
 * @param haystack The array of integers to search in
 * @param haystack_length The length of the integer array
 */
static bool in_array(uint8_t needle, uint8_t haystack[], uint8_t haystack_length);



//--------------------------------------------------
// Bluetooth functions
//--------------------------------------------------

/**
 * Setup method for the peripheral.
 */
static void peripheral_setup(void);

/**
 * Used to send data to the peripheral.
 * @param modifier The modifier to send (ALT/CTRL, etc.)
 * @param keycode The keycode in ASCII to send to the peripheral.
 */
static void peripheral_send(uint8_t modifier, uint8_t keycode);

/**
 * Handles received bluetooth packets (callback function).
 * @param packet_type The type of packet we received.
 * @param channel On which channeld did we receive it.
 * @param packet The actual packet.
 * @param size The size of the received packet.
 */
static void peripheral_packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size);



//--------------------------------------------------
// Websocket functions
//--------------------------------------------------

/**
 * Setup method for the websocket server
 */
static void websocket_setup(void);

/**
 * Event handler function, is called when a static file is requested, a client joins, a client sends a message and when a client disconnects.
 * @param mg_connection The connection initiating the event
 * @param ev The event ID
 * @param ev_data The data of the event
 */
static void websocket_event_handler(struct mg_connection *nc, int ev, void *ev_data);

/**
 * Broadcast a message to all connected clients. This is mainly used for debug logging.
 * @param mg_connection The connection initiating the broadcast
 * @param mg_str The message we want to broadcast
 */
static void websocket_broadcast(struct mg_connection *nc, const struct mg_str msg);

/**
 * Destructor for the websocket server
 */
static void websocket_teardown(void);