/*
MySQL Data Transfer
Source Host: localhost
Source Database: bluelightplm
Target Host: localhost
Target Database: bluelightplm
Date: 2014/12/18 16:08:52
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for bmqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bmqxhflxx`;
CREATE TABLE `bmqxhflxx` (
  `bmqxhID` int(11) NOT NULL AUTO_INCREMENT,
  `bmqxh` char(100) NOT NULL,
  PRIMARY KEY (`bmqxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for bpqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bpqxhflxx`;
CREATE TABLE `bpqxhflxx` (
  `bpqxhID` int(11) NOT NULL AUTO_INCREMENT,
  `bpqxh` char(100) NOT NULL,
  PRIMARY KEY (`bpqxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for cpggxhxx
-- ----------------------------
DROP TABLE IF EXISTS `cpggxhxx`;
CREATE TABLE `cpggxhxx` (
  `cpggxhID` int(11) NOT NULL AUTO_INCREMENT,
  `gg` char(100) NOT NULL,
  PRIMARY KEY (`cpggxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ddztb
-- ----------------------------
DROP TABLE IF EXISTS `ddztb`;
CREATE TABLE `ddztb` (
  `ddztID` int(11) NOT NULL AUTO_INCREMENT,
  `ddzt` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`ddztID`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for htxx
-- ----------------------------
DROP TABLE IF EXISTS `htxx`;
CREATE TABLE `htxx` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `htID` char(16) DEFAULT NULL,
  `ClientID` int(11) DEFAULT NULL,
  `ggxhID` int(11) DEFAULT NULL,
  `sl` int(8) DEFAULT NULL,
  `zcID` int(11) DEFAULT NULL,
  `dfr` char(1) DEFAULT NULL,
  `zdqdyID` int(11) DEFAULT NULL,
  `yylggID` int(11) DEFAULT NULL,
  `sfjf` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `bpqxhID` int(11) DEFAULT NULL,
  `bmqxhID` int(11) DEFAULT NULL,
  `dlcd` char(20) DEFAULT NULL,
  `zxcd` char(20) DEFAULT NULL,
  `mpzl` int(11) DEFAULT NULL,
  `bz` char(100) DEFAULT NULL,
  `ddrq` date DEFAULT NULL,
  `ddzt` char(16) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `sftgywsh` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `sftgjhsh` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
   `yxj` int(8) DEFAULT 10,	
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for khcyxxb
-- ----------------------------
DROP TABLE IF EXISTS `khcyxxb`;
CREATE TABLE `khcyxxb` (
  `ClientID` int(11) NOT NULL AUTO_INCREMENT,
  `ggxhID` int(11) DEFAULT NULL,
  `zcID` int(11) DEFAULT NULL,
  `dfr` char(1) DEFAULT NULL,
  `zdqdyID` int(11) DEFAULT NULL,
  `yylggID` int(11) DEFAULT NULL,
  `sfjf` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `bpqxhID` int(11) DEFAULT NULL,
  `bmqxhID` int(11) DEFAULT NULL,
  `dlcd` char(20) DEFAULT NULL,
  `zxcd` char(20) DEFAULT NULL,
  `mpzl` char(100) DEFAULT NULL,
  PRIMARY KEY (`ClientID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for khxx
-- ----------------------------
DROP TABLE IF EXISTS `khxx`;
CREATE TABLE `khxx` (
  `clientID` int(11) NOT NULL AUTO_INCREMENT,
  `khmc` char(100) NOT NULL,
  `khcz` char(200) DEFAULT NULL,
  `lxr` char(20) DEFAULT NULL,
  `lxdh` char(20) DEFAULT NULL,
  `qtnr` char(100) DEFAULT NULL,
  PRIMARY KEY (`clientID`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for mpzlxx
-- ----------------------------
DROP TABLE IF EXISTS `mpzlxx`;
CREATE TABLE `mpzlxx` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `mpzl` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for pcjhxxb
-- ----------------------------
DROP TABLE IF EXISTS `pcjhxxb`;
CREATE TABLE `pcjhxxb` (
  `pcjhID` int(11) NOT NULL AUTO_INCREMENT,
  `htxxID` int(11) NOT NULL,
  `jhscrq` date DEFAULT NULL,
  `jhbzrq` date DEFAULT NULL,
  `jhfhrq` date DEFAULT NULL,
  `tcbh` char(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `ccbh` char(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `sftgywsh` char(1) COLLATE utf8_unicode_ci DEFAULT NULL,
  `sftgjhsh` char(1) COLLATE utf8_unicode_ci DEFAULT NULL,
  `bzsftgywsh` char(1) COLLATE utf8_unicode_ci DEFAULT NULL,
  `bzsftgjhsh` char(1) COLLATE utf8_unicode_ci DEFAULT NULL,
  `ddzt` char(16) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`pcjhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for permission
-- ----------------------------
DROP TABLE IF EXISTS `permission`;
CREATE TABLE `permission` (
  `role` char(100) NOT NULL,
  `xsywsh` tinyint(1) DEFAULT '0',
  `xsjhsh` tinyint(1) DEFAULT '0',
  `jhywsh` tinyint(1) DEFAULT '0',
  `jhjhsh` tinyint(1) DEFAULT '0',
  `jhbzywsh` tinyint(1) DEFAULT '0',
  `jhbzjhsh` tinyint(1) DEFAULT '0',
  `plan` tinyint(1) DEFAULT '0',
  `sale` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`role`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `name` char(100) NOT NULL,
  `psw` char(100) NOT NULL,
  `department` char(100) NOT NULL,
  `role` char(100) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for yylggflxx
-- ----------------------------
DROP TABLE IF EXISTS `yylggflxx`;
CREATE TABLE `yylggflxx` (
  `yylggID` int(11) NOT NULL AUTO_INCREMENT,
  `yylgg` char(100) NOT NULL,
  PRIMARY KEY (`yylggID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zcxx
-- ----------------------------
DROP TABLE IF EXISTS `zcxx`;
CREATE TABLE `zcxx` (
  `zcxhID` int(11) NOT NULL AUTO_INCREMENT,
  `zcxh` char(100) NOT NULL,
  PRIMARY KEY (`zcxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zdqdyflxx
-- ----------------------------
DROP TABLE IF EXISTS `zdqdyflxx`;
CREATE TABLE `zdqdyflxx` (
  `zdqdyID` int(11) NOT NULL AUTO_INCREMENT,
  `zdqdy` char(100) NOT NULL,
  PRIMARY KEY (`zdqdyID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `bmqxhflxx` VALUES ('1', '海1387');
INSERT INTO `bmqxhflxx` VALUES ('2', '其他');
INSERT INTO `bpqxhflxx` VALUES ('1', '富士');
INSERT INTO `bpqxhflxx` VALUES ('2', '默纳克');
INSERT INTO `bpqxhflxx` VALUES ('3', 'CV');
INSERT INTO `bpqxhflxx` VALUES ('4', '蓝光一体化');
INSERT INTO `cpggxhxx` VALUES ('1', 'U1.0ES-H');
INSERT INTO `cpggxhxx` VALUES ('2', 'S1.6C-H');
INSERT INTO `cpggxhxx` VALUES ('3', 'TA1.5C-H');
INSERT INTO `cpggxhxx` VALUES ('4', 'TA1.0CZ - H');
INSERT INTO `ddztb` VALUES ('1', '销售录入中');
INSERT INTO `ddztb` VALUES ('2', '销售审核中');
INSERT INTO `ddztb` VALUES ('3', '销售已审核/待计划排产');
INSERT INTO `ddztb` VALUES ('4', '销售审核未通过');
INSERT INTO `ddztb` VALUES ('5', '计划排产中');
INSERT INTO `ddztb` VALUES ('6', '计划排产审核中');
INSERT INTO `ddztb` VALUES ('7', '计划排产已审核');
INSERT INTO `ddztb` VALUES ('8', '计划排产审核未通过');
INSERT INTO `ddztb` VALUES ('9', '生产中');
INSERT INTO `ddztb` VALUES ('10', '生产完成');
INSERT INTO `htxx` VALUES ('1', '1', '1', '1', '100', '1', 'Y', '1', '1', 'Y', '1', '2', '5米', '8米', '1', '备注', '2014-11-27', '1', 'N', 'N', 100);
INSERT INTO `htxx` VALUES ('2', '2', '2', '2', '32', '2', 'Y', '2', '2', 'Y', '2', '1', '5米', '2米', '2', '原点住备注', '2014-11-11', '1', 'N', 'N', 100);
INSERT INTO `htxx` VALUES ('3', '3', '3', '1', '2', '2', 'Y', '3', '2', 'Y', '2', '2', '5米', '2米', '3', '原点住', '2014-11-11', '1', 'N', 'N', 100);
INSERT INTO `htxx` VALUES ('4', '4', '4', '3', '6', '2', 'Y', '3', '1', 'Y', '1', '1', '5米', '3米', '1', '原点住', '2014-11-04', '1', 'N', 'N', 100);
INSERT INTO `htxx` VALUES ('5', '5', '1', '2', '98', '2', 'Y', '3', '3', 'Y', '3', '2', '5米', '5米', '2', '原点住备注', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('6', '6', '3', '4', '7', '1', 'Y', '2', '2', 'Y', '2', '1', '5米', '2米', '1', '原点住', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('7', '7', '2', '3', '5', '2', 'Y', '1', '1', 'Y', '3', '1', '5米', '2米', '2', '原点住', '2014-11-11', '1', 'N', 'N', 100);
INSERT INTO `htxx` VALUES ('8', '8', '3', '2', '4', '1', 'Y', '2', '3', 'Y', '4', '2', '5米', '1米', '3', '原点住备注备注', '2014-11-28', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('9', '9', '1', '4', '6', '1', 'Y', '1', '1', 'Y', '3', '1', '5米', '8米', '3', '原点住', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('10', '10', '2', '3', '4', '2', 'Y', '1', '1', 'Y', '4', '1', '8米', '8米', '4', '备注', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('11', '11', '1', '1', '3', '1', 'Y', '2', '4', 'Y', '2', '2', '8米', '8米', '4', '原点住备注', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('12', '12', '3', '2', '2', '2', 'Y', '1', '4', 'Y', '1', '2', '8米', '2米', '2', '原点住备注', '2014-11-11', '1', 'N', 'N', 10);
INSERT INTO `htxx` VALUES ('13', '2345', '1', '1', '1', '1', 'N', '1', '1', 'N', '1', '1', '', '', '1', '', '2014-12-18', null, 'N', 'N', 10);
INSERT INTO `khcyxxb` VALUES ('1', '1', '1', 'Y', '1', '1', 'Y', '1', '1', '5m', '8m', '蓝光英文');
INSERT INTO `khxx` VALUES ('1', '佛山住友富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('2', '浙江怡达', null, null, null, null);
INSERT INTO `khxx` VALUES ('3', '中原智能', null, null, null, null);
INSERT INTO `khxx` VALUES ('4', '恒达富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('5', '天津奥斯达', null, null, null, null);
INSERT INTO `khxx` VALUES ('6', '预投', null, null, null, null);
INSERT INTO `mpzlxx` VALUES ('1', '蓝光英文铭牌');
INSERT INTO `mpzlxx` VALUES ('2', '蓝光铭牌');
INSERT INTO `mpzlxx` VALUES ('3', '蓝光英文西门子监制');
INSERT INTO `mpzlxx` VALUES ('4', '主机用西德英文铭牌');
INSERT INTO `mpzlxx` VALUES ('5', '制动器和上行超速铭牌用蓝光英文');
INSERT INTO `permission` VALUES ('ADMIN', '1', '1', '1', '1', '1', '1', '1', '1');
INSERT INTO `permission` VALUES ('USER', '0', '0', '0', '0', '0', '0', '0', '0');
INSERT INTO `permission` VALUES ('YWLEADER', '1', '1', '0', '0', '0', '0', '0', '1');
INSERT INTO `permission` VALUES ('JHLEADER', '0', '0', '1', '1', '1', '1', '1', '0');
INSERT INTO `user` VALUES ('Admin', md5('123456'), '其他', 'ADMIN');
INSERT INTO `user` VALUES ('周海越'  , md5('JOJO'), '业务部', 'YWLEADER');
INSERT INTO `user` VALUES ('王亚明', md5('wangyaming'), '业务部', 'USER');
INSERT INTO `user` VALUES ('喻杰', md5('yujie'), '业务部', 'USER');
INSERT INTO `user` VALUES ('孙莹莹', md5('sunyingying'), '业务部', 'USER');
INSERT INTO `user` VALUES ('曲鸣悦', md5('qumingyue'), '业务部', 'USER');
INSERT INTO `user` VALUES ('王颖', md5('wangying'), '业务部', 'USER');
INSERT INTO `user` VALUES ('陈鹤', md5('chenhesylg'), '业务部', 'USER');
INSERT INTO `user` VALUES ('高珊', md5('gaoshan'), '业务部', 'USER');
INSERT INTO `user` VALUES ('吴勇霞', md5('wuyongxia'), '业务部', 'USER');
INSERT INTO `user` VALUES ('卢文俏', md5('zoubo'), '业务部', 'USER');
INSERT INTO `user` VALUES ('陈静', md5('chjing'), '业务部', 'USER');
INSERT INTO `user` VALUES ('苏璇', md5('suxuan'), '业务部', 'USER');
INSERT INTO `user` VALUES ('李建华', md5('lijianhua'), '业务部', 'USER');
INSERT INTO `user` VALUES ('刘艳萍', md5('liuyanping'), '业务部', 'USER');
INSERT INTO `user` VALUES ('白艳玲', md5('baiyanling'), '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('高英', md5('gaoy'), '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('王玺', md5('wangxi'), '计划科', 'USER');
INSERT INTO `user` VALUES ('曹文俊', md5('cwj'), '计划科', 'USER');
INSERT INTO `user` VALUES ('刘明东', md5('LMD'), '计划科', 'USER');
INSERT INTO `user` VALUES ('孙海龙', md5('sunhailong'), '其他', 'ADMIN');
INSERT INTO `user` VALUES ('杨鹏', md5('yangpeng'), '其他', 'ADMIN');
INSERT INTO `user` VALUES ('王宇博', md5('wangyubo'), '其他', 'ADMIN');
INSERT INTO `yylggflxx` VALUES ('2', '400*5*10*16');
INSERT INTO `yylggflxx` VALUES ('3', '325*5*8*12');
INSERT INTO `yylggflxx` VALUES ('4', '400*5*10*16-2(SB)');
INSERT INTO `zcxx` VALUES ('1', 'BNN');
INSERT INTO `zcxx` VALUES ('2', 'RC');
INSERT INTO `zdqdyflxx` VALUES ('1', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('2', 'AC220V');
INSERT INTO `zdqdyflxx` VALUES ('3', 'DC220V');
