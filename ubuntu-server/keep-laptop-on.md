You can run your **Ubuntu Server 24.04** laptop with the screen closed. However, by default, most laptops are set to suspend or hibernate when the lid is closed. To prevent this, you need to configure the system settings.

### **Steps to Keep Ubuntu Server Running with the Lid Closed**

#### **1. Modify the logind.conf File**
Ubuntu uses **logind** (systemd-logind) to handle power events like lid closing. To disable sleep/suspend when closing the lid:

1. Open the logind configuration file:
   ```bash
   sudo nano /etc/systemd/logind.conf
   ```

2. Find the following line:
   ```bash
   #HandleLidSwitch=suspend
   ```
   Change it to:
   ```bash
   HandleLidSwitch=ignore
   ```

3. If your laptop has an external monitor and you want it to work even with the lid closed, also modify:
   ```bash
   HandleLidSwitchExternalPower=ignore
   ```

4. Save the file (`CTRL + X`, then `Y`, then `ENTER`).

5. Restart the **logind** service to apply the changes:
   ```bash
   sudo systemctl restart systemd-logind
   ```

#### **2. Disable Laptop Lid Switch in Udev (Optional)**
If the above method does not work, try disabling the lid switch in **udev**.

1. Create a new rules file:
   ```bash
   sudo nano /etc/udev/rules.d/10-lid.rules
   ```

2. Add the following line:
   ```bash
   ACTION=="change", SUBSYSTEM=="power_supply", ATTR{status}=="Discharging", RUN+="/bin/sh -c 'echo ignore > /proc/acpi/button/lid/LID0/state'"
   ```

3. Save and reload udev rules:
   ```bash
   sudo udevadm control --reload-rules
   sudo udevadm trigger
   ```

#### **3. Verify the Changes**
Close the lid and try accessing the server via SSH from another computer. If it works, your system is now running with the lid closed.

Would you like to automate this setup across multiple laptops? 🚀
