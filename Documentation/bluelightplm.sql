/*
MySQL Data Transfer
Source Host: localhost
Source Database: bluelightplm
Target Host: localhost
Target Database: bluelightplm
Date: 2014/11/27 13:32:40
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for bmqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bmqxhflxx`;
CREATE TABLE `bmqxhflxx` (
  `bmqxhID` int(11) NOT NULL auto_increment,
  `bmqxh` char(100) NOT NULL,
  PRIMARY KEY  (`bmqxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for bpqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bpqxhflxx`;
CREATE TABLE `bpqxhflxx` (
  `bpqxhID` int(11) NOT NULL auto_increment,
  `bpqxh` char(100) NOT NULL,
  PRIMARY KEY  (`bpqxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for cpggxhxx
-- ----------------------------
DROP TABLE IF EXISTS `cpggxhxx`;
CREATE TABLE `cpggxhxx` (
  `cpggxhID` int(11) NOT NULL auto_increment,
  `gg` char(100) NOT NULL,
  PRIMARY KEY  (`cpggxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ddztb
-- ----------------------------
DROP TABLE IF EXISTS `ddztb`;
CREATE TABLE `ddztb` (
  `ddztID` int(11) NOT NULL auto_increment,
  `ddzt` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`ddztID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for htxx
-- ----------------------------
DROP TABLE IF EXISTS `htxx`;
CREATE TABLE `htxx` (
  `ID` int(11) NOT NULL auto_increment,
  `htID` int(11) default NULL,
  `ClientID` int(11) default NULL,
  `ggxhID` int(11) default NULL,
  `sl` int(8) default NULL,
  `zcID` int(11) default NULL,
  `dfr` char(1) default NULL,
  `zdqdyID` int(11) default NULL,
  `yylggID` int(11) default NULL,
  `sfjf` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `bpqxhID` int(11) default NULL,
  `bmqxhID` int(11) default NULL,
  `dlcd` char(20) default NULL,
  `zxcd` char(20) default NULL,
  `mpzl` int(11) default NULL,
  `bz` char(100) default NULL,
  `ddrq` datetime default NULL,
  `ddzt` char(16) character set utf8 collate utf8_unicode_ci default NULL,
  `sftgywsh` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `sftgjhsh` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for khcyxxb
-- ----------------------------
DROP TABLE IF EXISTS `khcyxxb`;
CREATE TABLE `khcyxxb` (
  `ClientID` int(11) NOT NULL auto_increment,
  `ggxhID` int(11) default NULL,
  `zcID` int(11) default NULL,
  `dfr` char(1) default NULL,
  `zdqdyID` int(11) default NULL,
  `yylggID` int(11) default NULL,
  `sfjf` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `bpqxhID` int(11) default NULL,
  `bmqxhID` int(11) default NULL,
  `dlcd` char(20) default NULL,
  `zxcd` char(20) default NULL,
  `mpzl` char(100) default NULL,
  PRIMARY KEY  (`ClientID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for khxx
-- ----------------------------
DROP TABLE IF EXISTS `khxx`;
CREATE TABLE `khxx` (
  `clientID` int(11) NOT NULL auto_increment,
  `khmc` char(100) NOT NULL,
  `khcz` char(200) default NULL,
  `lxr` char(20) default NULL,
  `lxdh` char(20) default NULL,
  `qtnr` char(100) default NULL,
  PRIMARY KEY  (`clientID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for mpzlxx
-- ----------------------------
DROP TABLE IF EXISTS `mpzlxx`;
CREATE TABLE `mpzlxx` (
  `id` int(11) NOT NULL auto_increment,
  `mpzl` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for pcjhxxb
-- ----------------------------
DROP TABLE IF EXISTS `pcjhxxb`;
CREATE TABLE `pcjhxxb` (
  `pcjhID` int(11) NOT NULL auto_increment,
  `htID` char(16) collate utf8_unicode_ci NOT NULL,
  `jhscrq` char(12) collate utf8_unicode_ci default NULL,
  `jhbzrq` char(12) collate utf8_unicode_ci default NULL,
  `jhfhrq` char(12) collate utf8_unicode_ci default NULL,
  `tcbh` char(50) collate utf8_unicode_ci default NULL,
  `ccbh` char(50) collate utf8_unicode_ci default NULL,
  `sftgywsh` char(1) collate utf8_unicode_ci default NULL,
  `sftgjhsh` char(1) collate utf8_unicode_ci default NULL,
  `bzsftgywsh` char(1) collate utf8_unicode_ci default NULL,
  `bzsftgjhsh` char(1) collate utf8_unicode_ci default NULL,
  `ddzt` char(16) collate utf8_unicode_ci default NULL,
  PRIMARY KEY  (`pcjhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for yylggflxx
-- ----------------------------
DROP TABLE IF EXISTS `yylggflxx`;
CREATE TABLE `yylggflxx` (
  `yylggID` int(11) NOT NULL auto_increment,
  `yylgg` char(100) NOT NULL,
  PRIMARY KEY  (`yylggID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zcxx
-- ----------------------------
DROP TABLE IF EXISTS `zcxx`;
CREATE TABLE `zcxx` (
  `zcxhID` int(11) NOT NULL auto_increment,
  `zcxh` char(100) NOT NULL,
  PRIMARY KEY  (`zcxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zdqdyflxx
-- ----------------------------
DROP TABLE IF EXISTS `zdqdyflxx`;
CREATE TABLE `zdqdyflxx` (
  `zdqdyID` int(11) NOT NULL auto_increment,
  `zdqdy` char(100) NOT NULL,
  PRIMARY KEY  (`zdqdyID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
INSERT INTO `htxx` VALUES ('1', '1', '1', '1', '56', '1', 'Y', '1', '1', 'Y', '1', '2', '5米', '8米', '1', '备注', '2014-11-27 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('2', '2', '2', '2', '32', '2', 'Y', '2', '2', 'Y', '2', '1', '5米', '2米', '2', '原点住备注', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('3', '3', '3', '1', '2', '2', 'Y', '3', '2', 'Y', '2', '2', '5米', '2米', '3', '原点住', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('4', '4', '4', '3', '6', '2', 'Y', '3', '1', 'Y', '1', '1', '5米', '3米', '1', '原点住', '2014-11-04 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('5', '5', '1', '2', '98', '2', 'Y', '3', '3', 'Y', '3', '2', '5米', '5米', '2', '原点住备注', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('6', '6', '3', '4', '7', '1', 'Y', '2', '2', 'Y', '2', '1', '5米', '2米', '1', '原点住', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('7', '7', '2', '3', '5', '2', 'Y', '1', '1', 'Y', '3', '1', '5米', '2米', '2', '原点住', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('8', '8', '3', '2', '4', '1', 'Y', '2', '3', 'Y', '4', '2', '5米', '1米', '3', '原点住备注备注', '2014-11-28 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('9', '9', '1', '4', '6', '1', 'Y', '1', '1', 'Y', '3', '1', '5米', '8米', '3', '原点住', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('10', '10', '2', '3', '4', '2', 'Y', '1', '1', 'Y', '4', '1', '8米', '8米', '4', '备注', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('11', '11', '1', '1', '3', '1', 'Y', '2', '4', 'Y', '2', '2', '8米', '8米', '4', '原点住备注', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `htxx` VALUES ('12', '12', '3', '2', '2', '2', 'Y', '1', '4', 'Y', '1', '2', '8米', '2米', '2', '原点住备注', '2014-11-11 17:18:06', '1', 'N', 'N');
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
INSERT INTO `yylggflxx` VALUES ('1', '480*6*12*18');
INSERT INTO `yylggflxx` VALUES ('2', '400*5*10*16');
INSERT INTO `yylggflxx` VALUES ('3', '325*5*8*12');
INSERT INTO `yylggflxx` VALUES ('4', '400*5*10*16-2(SB)');
INSERT INTO `zcxx` VALUES ('1', 'BNN');
INSERT INTO `zcxx` VALUES ('2', 'RC');
INSERT INTO `zdqdyflxx` VALUES ('1', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('2', 'AC220V');
INSERT INTO `zdqdyflxx` VALUES ('3', 'DC220V');
