# Multipath OVS

This modified version of Open vSwitch adds two features:

- Multipath Select GROUP
Used to do packet-scheduling over different paths. It uses rules pushed by the controller to perform packet decisions over a set of actions (which can be a simple output or a IP rewrite for routing). It can use multiple scheduling algorithms, but we focus on weighted round-robin. It reuses Openflow Select GROUP Feature. 

- TCP Reordering GROUP
Used to reorder TCP packets incoming from multiple ports. Flows can be channeled to this group, which will perform reordering of the TCP packets and output them as per group output rules.
It adds a GROUP to the OpenFlow specifications with id: 4

## Installation instructions

This project has been built on Ubuntu Linux 14 - 16. If you want to use other Linux distributions, make sure to install the matching dependencies.
The installation procedure is exactly the same for normal OVS. In short:

```
sudo apt-get install -y git automake autoconf gcc uml-utilities libtool build-essential git pkg-config linux-headers-`uname -r`
chmod +x boot.sh
./boot.sh
./configure
make && make install

touch /usr/local/etc/ovs-vswitchd.conf
mkdir -p /usr/local/etc/openvswitch
ovsdb-tool create /usr/local/etc/openvswitch/conf.db vswitchd/vswitch.ovsschema

ovsdb-server /usr/local/etc/openvswitch/conf.db \
--remote=punix:/usr/local/var/run/openvswitch/db.sock
ovs-vsctl --no-wait init
ovs-vswitchd --pidfile --detach
```

In case you have problems, this article can help with a step-by-step guide: http://networkstatic.net/installing-and-configuring-openvswitch-on-ubuntu-12-04-precise-pangolin/

## Usage

Multipath flow rules can be set up with the following command:

`ovs-ofctl -O OpenFlow13 add-group s1 group_id=11,type=select,bucket=weight:10,output:1,bucket=weight:20,output:2`

Reordering flow rules can be set up with the following command:

```
ovs-ofctl -O OpenFlow13 add-group s1 group_id=10,type=reordering,bucket=output:3
ovs-ofctl -O OpenFlow13 add-flow s1 in_port=1,actions=group:10
ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,actions=group:10
```
