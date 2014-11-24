/*
MySQL Data Transfer
Source Host: localhost
Source Database: bluelightplm
Target Host: localhost
Target Database: bluelightplm
Date: 2014/11/24 10:40:24
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for bmqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bmqxhflxx`;
CREATE TABLE `bmqxhflxx` (
  `bmqxhID` char(16) NOT NULL,
  `bmqxh` char(100) NOT NULL,
  PRIMARY KEY  (`bmqxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for bpqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bpqxhflxx`;
CREATE TABLE `bpqxhflxx` (
  `bpqxhID` char(16) NOT NULL,
  `bpqxh` char(100) NOT NULL,
  PRIMARY KEY  (`bpqxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for cpggxhxx
-- ----------------------------
DROP TABLE IF EXISTS `cpggxhxx`;
CREATE TABLE `cpggxhxx` (
  `cpggxhID` char(16) NOT NULL,
  `gg` char(100) NOT NULL,
  PRIMARY KEY  (`cpggxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for ddztb
-- ----------------------------
DROP TABLE IF EXISTS `ddztb`;
CREATE TABLE `ddztb` (
  `ddztID` char(16) collate utf8_unicode_ci NOT NULL,
  `ddzt` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`ddztID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for htxx
-- ----------------------------
DROP TABLE IF EXISTS `htxx`;
CREATE TABLE `htxx` (
  `ID` int(16) NOT NULL,
  `htID` char(16) character set utf8 collate utf8_unicode_ci NOT NULL,
  `ClientID` char(16) default NULL,
  `ggxhID` char(16) default NULL,
  `sl` int(8) default NULL,
  `zcID` char(16) default NULL,
  `dfr` char(1) default NULL,
  `zdqdyID` char(16) default NULL,
  `yylggID` char(16) default NULL,
  `sfjf` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `bpqxhID` char(16) default NULL,
  `bmqxhID` char(16) default NULL,
  `dlcd` char(20) default NULL,
  `zxcd` char(20) default NULL,
  `mpzl` char(100) default NULL,
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
  `ClientID` char(16) NOT NULL,
  `ggxhID` char(16) default NULL,
  `zcID` char(16) default NULL,
  `dfr` char(1) default NULL,
  `zdqdyID` char(16) default NULL,
  `yylggID` char(16) default NULL,
  `sfjf` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `bpqxhID` char(16) default NULL,
  `bmqxhID` char(16) default NULL,
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
  `clientID` char(16) NOT NULL default '',
  `khmc` char(100) NOT NULL,
  `khcz` char(200) default NULL,
  `lxr` char(20) default NULL,
  `lxdh` char(20) default NULL,
  `qtnr` char(100) default NULL,
  PRIMARY KEY  (`clientID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for pcjhxxb
-- ----------------------------
DROP TABLE IF EXISTS `pcjhxxb`;
CREATE TABLE `pcjhxxb` (
  `pcjhID` char(16) collate utf8_unicode_ci NOT NULL,
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
  `yylggID` char(16) NOT NULL,
  `yylgg` char(100) NOT NULL,
  PRIMARY KEY  (`yylggID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zcxx
-- ----------------------------
DROP TABLE IF EXISTS `zcxx`;
CREATE TABLE `zcxx` (
  `zcxhID` char(16) NOT NULL,
  `zcxh` char(100) NOT NULL,
  PRIMARY KEY  (`zcxhID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for zdqdyflxx
-- ----------------------------
DROP TABLE IF EXISTS `zdqdyflxx`;
CREATE TABLE `zdqdyflxx` (
  `zdqdyID` char(16) NOT NULL,
  `zdqdy` char(100) NOT NULL,
  PRIMARY KEY  (`zdqdyID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `bmqxhflxx` VALUES ('00001', '海1387');
INSERT INTO `bpqxhflxx` VALUES ('00001', '富士');
INSERT INTO `bpqxhflxx` VALUES ('00002', '默纳克');
INSERT INTO `cpggxhxx` VALUES ('00001', 'U1.0ES-H');
INSERT INTO `cpggxhxx` VALUES ('00002', 'S1.6C-H');
INSERT INTO `ddztb` VALUES ('1', '销售录入中');
INSERT INTO `ddztb` VALUES ('10', '生产完成');
INSERT INTO `ddztb` VALUES ('2', '销售审核中');
INSERT INTO `ddztb` VALUES ('3', '销售已审核/待计划排产');
INSERT INTO `ddztb` VALUES ('4', '销售审核未通过');
INSERT INTO `ddztb` VALUES ('5', '计划排产中');
INSERT INTO `ddztb` VALUES ('6', '计划排产审核中');
INSERT INTO `ddztb` VALUES ('7', '计划排产已审核');
INSERT INTO `ddztb` VALUES ('8', '计划排产审核未通过');
INSERT INTO `ddztb` VALUES ('9', '生产中');
INSERT INTO `htxx` VALUES ('1', '00000001', '00001', '00001', '2', '00001', 'Y', '00001', '00001', 'Y', '00001', '00001', '5m', '8m', '蓝光英文', '原点住', '2014-11-11 17:18:06', '1', 'N', 'N');
INSERT INTO `khcyxxb` VALUES ('00001', '00001', '00001', 'Y', '00001', '00001', 'Y', '00001', '00001', '5m', '8m', '蓝光英文');
INSERT INTO `khxx` VALUES ('00001', '佛山住友富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('00002', '沃克斯电梯（上海腾能）', null, null, null, null);
INSERT INTO `yylggflxx` VALUES ('00001', '480*6*12*18');
INSERT INTO `yylggflxx` VALUES ('00002', '400*5*10*16');
INSERT INTO `zcxx` VALUES ('00001', 'BNN');
INSERT INTO `zcxx` VALUES ('00002', 'RC');
INSERT INTO `zdqdyflxx` VALUES ('00001', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('00002', 'AC220V');
