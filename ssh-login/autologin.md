## SSH Auto Login

```
ssh-keygen -t rsa -b 4096
cat ~/.ssh/id_rsa.pub | ssh one@192.168.1.101 "mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys"
cat ~/.ssh/id_rsa.pub | ssh two@192.168.1.102 "mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys"
cat ~/.ssh/id_rsa.pub | ssh three@192.168.1.103 "mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys"
cat ~/.ssh/id_rsa.pub | ssh four@192.168.1.104 "mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys"
```
