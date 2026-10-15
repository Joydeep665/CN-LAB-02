import socket

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address and port
server_address = ("localhost", 9998)

# Bind socket
server_socket.bind(server_address)

print("UDP Server started...")
print("Server is waiting for client...")

while True:

    # Receive data from client
    data, client_address = server_socket.recvfrom(1024)

    message = data.decode()

    # Separate choice and message
    choice, message = message.split("|", 1)

    print("\nClient connected from:", client_address)
    print("Message received:", message)

    # Perform operation
    if choice == "1":
        result = message.lower()

    elif choice == "2":
        result = message.upper()

    elif choice == "3":
        result = message[::-1]

    else:
        result = "Invalid choice"

    # Send result back to client
    server_socket.sendto(result.encode(), client_address)

    print("Response sent:", result)