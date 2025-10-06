# 🧩 **VMware `vmrun` Command Summary**

`vmrun` হলো VMware-এর CLI (Command Line Interface) টুল, যা VMware Workstation, Fusion, এবং ESXi হোস্টে ভার্চুয়াল মেশিন (VM) নিয়ন্ত্রণ করতে ব্যবহৃত হয়।
এটি GUI ছাড়াই VM **start, stop, suspend, pause, snapshot, run program** ইত্যাদি করতে দেয়।

---

## ⚙️ **Basic Syntax**

```bash
vmrun [OPTIONS] COMMAND <.vmx file> [arguments...]
```

* `<.vmx file>` → আপনার ভার্চুয়াল মেশিনের কনফিগ ফাইলের পাথ (যেমন `~/vmware/redhat/redhat.vmx`)
* Common option: `-T ws` (Workstation), `-T fusion`, `-T player`, `-T server`

---

## 🟢 **1. Power Management Commands**

| Command   | Description                            | Example                                        |
| --------- | -------------------------------------- | ---------------------------------------------- |
| `start`   | VM চালু করে                            | `vmrun start ~/vmware/redhat/redhat.vmx nogui` |
| `stop`    | VM বন্ধ করে (soft বা hard)             | `vmrun stop ~/vmware/redhat/redhat.vmx soft`   |
| `reset`   | VM রিবুট করে                           | `vmrun reset ~/vmware/redhat/redhat.vmx soft`  |
| `suspend` | VM suspend করে (RAM state সংরক্ষণ করে) | `vmrun suspend ~/vmware/redhat/redhat.vmx`     |
| `pause`   | VM execution থামিয়ে রাখে               | `vmrun pause ~/vmware/redhat/redhat.vmx`       |
| `unpause` | Pause করা VM আবার resume করে           | `vmrun unpause ~/vmware/redhat/redhat.vmx`     |

### 🧠 Notes:

* `soft` = guest OS-এর মধ্যে graceful shutdown।
* `hard` = instant power-off, যেমন plug খুলে ফেলা।

---

## 🌐 **2. Networking Commands**

| Command                   | Description                                                | Example                                                    |
| ------------------------- | ---------------------------------------------------------- | ---------------------------------------------------------- |
| `getGuestIPAddress`       | Guest OS-এর IP address দেখায় (VMware Tools চালু থাকতে হবে) | `vmrun getGuestIPAddress ~/vmware/redhat/redhat.vmx`       |
| `getGuestIPAddress -wait` | IP address পাওয়া পর্যন্ত অপেক্ষা করে                       | `vmrun getGuestIPAddress ~/vmware/redhat/redhat.vmx -wait` |

**Tip:**
যদি `Error: VMware Tools are not running` দেখায় → `vmtoolsd` সার্ভিস enable করতে হবে:

```bash
sudo systemctl enable --now vmtoolsd.service
```

---

## 📦 **3. File & Program Operations (Inside Guest OS)**

*(Requires VMware Tools installed in guest)*

| Command                   | Description                             | Example                                                                                       |
| ------------------------- | --------------------------------------- | --------------------------------------------------------------------------------------------- |
| `runProgramInGuest`       | Guest OS-এর ভিতরে কোনো প্রোগ্রাম চালানো | `vmrun -gu amran -gp pass runProgramInGuest redhat.vmx /usr/bin/uptime`                       |
| `copyFileFromHostToGuest` | হোস্ট থেকে গেস্টে ফাইল কপি করা          | `vmrun -gu amran -gp pass copyFileFromHostToGuest redhat.vmx ./file.txt /home/amran/file.txt` |
| `copyFileFromGuestToHost` | গেস্ট থেকে হোস্টে ফাইল কপি করা          | `vmrun -gu amran -gp pass copyFileFromGuestToHost redhat.vmx /etc/hosts ./hosts_copy`         |
| `deleteFileInGuest`       | গেস্টের ফাইল মুছে ফেলা                  | `vmrun -gu amran -gp pass deleteFileInGuest redhat.vmx /tmp/test.txt`                         |
| `createDirectoryInGuest`  | গেস্টে ফোল্ডার তৈরি করা                 | `vmrun -gu amran -gp pass createDirectoryInGuest redhat.vmx /home/amran/testdir`              |

---

## 🧰 **4. Snapshot Management**

| Command            | Description           | Example                                        |
| ------------------ | --------------------- | ---------------------------------------------- |
| `snapshot`         | একটি snapshot নেয়     | `vmrun snapshot redhat.vmx pre_update`         |
| `deleteSnapshot`   | snapshot মুছে ফেলে    | `vmrun deleteSnapshot redhat.vmx pre_update`   |
| `revertToSnapshot` | snapshot-এ revert করে | `vmrun revertToSnapshot redhat.vmx pre_update` |
| `listSnapshots`    | সব snapshot লিস্ট করে | `vmrun listSnapshots redhat.vmx`               |

**Tip:** Snapshot = VM-এর নির্দিষ্ট সময়ের “restore point।”

---

## 🧩 **5. Guest Process & File Listing**

| Command                | Description                     | Example                                                                |
| ---------------------- | ------------------------------- | ---------------------------------------------------------------------- |
| `listProcessesInGuest` | Guest-এ চলমান প্রক্রিয়া দেখায়   | `vmrun -gu amran -gp pass listProcessesInGuest redhat.vmx`             |
| `killProcessInGuest`   | Guest-এর কোনো process বন্ধ করে  | `vmrun -gu amran -gp pass killProcessInGuest redhat.vmx 1234`          |
| `listDirectoryInGuest` | Guest-এর ফোল্ডার কন্টেন্ট দেখায় | `vmrun -gu amran -gp pass listDirectoryInGuest redhat.vmx /home/amran` |

---

## 🧠 **6. VM Inventory Commands**

| Command      | Description                           | Example                       |
| ------------ | ------------------------------------- | ----------------------------- |
| `list`       | বর্তমানে চালু থাকা সব VM-এর লিস্ট দেয় | `vmrun list`                  |
| `register`   | VM inventory-তে যোগ করে               | `vmrun register redhat.vmx`   |
| `unregister` | inventory থেকে সরায়                   | `vmrun unregister redhat.vmx` |

---

## ⚡ **7. Advanced / Misc Commands**

| Command                                        | Description                          | Example                                 |
| ---------------------------------------------- | ------------------------------------ | --------------------------------------- |
| `clone`                                        | কোনো VM ক্লোন করে                    | `vmrun clone base.vmx clone.vmx linked` |
| `upgradeVM`                                    | VM-এর হার্ডওয়্যার ভার্সন আপগ্রেড করে | `vmrun upgradeVM redhat.vmx`            |
| `enableSharedFolders` / `disableSharedFolders` | VM-এর shared folder ফিচার অন/অফ করে  | `vmrun enableSharedFolders redhat.vmx`  |
| `listSharedFolders`                            | শেয়ার্ড ফোল্ডারের লিস্ট দেখায়        | `vmrun listSharedFolders redhat.vmx`    |

---

## 🔐 **8. Authentication Options**

যখন Guest-এ কমান্ড চালাতে হয়:

```bash
vmrun -gu <username> -gp <password> COMMAND <vmx_path> [args...]
```

উদাহরণ:

```bash
vmrun -gu amran -gp nopass runProgramInGuest redhat.vmx /usr/bin/uptime
```

---

## 🧭 **9. Example Full Workflow**

```bash
# VM চালু করো
vmrun start ~/vmware/redhat/redhat.vmx nogui

# IP address বের করো
vmrun getGuestIPAddress ~/vmware/redhat/redhat.vmx -wait

# Guest-এ কমান্ড চালাও
vmrun -gu amran -gp nopass runProgramInGuest ~/vmware/redhat/redhat.vmx /usr/bin/uptime

# Snapshot নাও
vmrun snapshot ~/vmware/redhat/redhat.vmx before_update

# VM বন্ধ করো
vmrun stop ~/vmware/redhat/redhat.vmx soft
```

---

## ⚠️ **Common Troubleshooting Tips**

| Problem                                        | Solution                                                    |
| ---------------------------------------------- | ----------------------------------------------------------- |
| `VMware Tools are not running`                 | গেস্টে `sudo systemctl enable --now vmtoolsd` চালাও         |
| `Error: The virtual machine is not powered on` | আগে `vmrun start` দিয়ে চালু করো                             |
| `Permission denied`                            | `sudo` ব্যবহার করো বা ইউজার পারমিশন ঠিক করো                 |
| `Invalid .vmx path`                            | পূর্ণ পাথ ব্যবহার করো (`/home/amran/dev/redhat/redhat.vmx`) |

