To install Docker and Docker Compose on an Ubuntu server, follow these steps:

### **1. Install Docker**

1. **Update the package list**:
   ```bash
   sudo apt-get update
   ```

2. **Install required dependencies**:
   ```bash
   sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common
   ```

3. **Add Docker's official GPG key**:
   ```bash
   curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
   ```

4. **Set up the stable Docker repository**:
   ```bash
   sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
   ```

5. **Update the package index again**:
   ```bash
   sudo apt-get update
   ```

6. **Install Docker CE (Community Edition)**:
   ```bash
   sudo apt-get install -y docker-ce
   ```

7. **Start Docker service**:
   ```bash
   sudo systemctl start docker
   ```

8. **Enable Docker to start on boot**:
   ```bash
   sudo systemctl enable docker
   ```

9. **Verify Docker installation**:
   Run the following to check the version of Docker:
   ```bash
   docker --version
   ```

### **2. Install Docker Compose**

1. **Download the latest version of Docker Compose**:
   Use `curl` to get the latest stable release:
   ```bash
   VERSION=$(curl -s https://api.github.com/repos/docker/compose/releases/latest | jq -r .tag_name)
   sudo curl -L "https://github.com/docker/compose/releases/download/${VERSION}/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
   ```

2. **Apply executable permissions**:
   ```bash
   sudo chmod +x /usr/local/bin/docker-compose
   ```

3. **Verify Docker Compose installation**:
   Run this to check the installed version:
   ```bash
   docker-compose --version
   ```

### **3. Optional: Manage Docker as a non-root user**

By default, Docker requires root privileges. You can run Docker as a non-root user (without `sudo`) by adding your user to the `docker` group:

1. **Add your user to the Docker group**:
   ```bash
   sudo usermod -aG docker $USER
   ```

2. **Log out and log back in**, or run the following to apply the group change immediately:
   ```bash
   newgrp docker
   ```

Now Docker and Docker Compose should be installed and running on your Ubuntu server. Let me know if you need any further assistance!
