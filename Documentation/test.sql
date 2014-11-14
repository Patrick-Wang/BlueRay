/*
MySQL Data Transfer
Source Host: localhost
Source Database: test
Target Host: localhost
Target Database: test
Date: 2014/11/11 17:18:50
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
-- Table structure for htxx
-- ----------------------------
DROP TABLE IF EXISTS `htxx`;
CREATE TABLE `htxx` (
  `ID` int(16) NOT NULL,
  `ClientID` char(16) NOT NULL,
  `ggxhID` char(16) default NULL,
  `sl` int(8) default NULL,
  `zcID` char(16) default NULL,
  `dfr` char(1) default NULL,
  `zdqdyID` char(16) default NULL,
  `yylggID` char(16) default NULL,
  `sfjf` char(1) character set latin1 default NULL,
  `bpqxhID` char(16) default NULL,
  `bmqxhID` char(16) default NULL,
  `dlcd` char(20) default NULL,
  `zxcd` char(20) default NULL,
  `mpzl` char(100) default NULL,
  `bz` char(100) default NULL,
  `ddrq` datetime default NULL,
  PRIMARY KEY  (`ID`)
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
INSERT INTO `htxx` VALUES ('1', '00001', '00001', '2', '00001', 'Y', '00001', '00001', 'Y', '00001', '00001', '5m', '8m', '蓝光英文', '原点住', '2014-11-11 17:18:06');
INSERT INTO `khxx` VALUES ('00001', '佛山住友富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('00002', '沃克斯电梯（上海腾能）', null, null, null, null);
INSERT INTO `yylggflxx` VALUES ('00001', '480*6*12*18');
INSERT INTO `yylggflxx` VALUES ('00002', '400*5*10*16');
INSERT INTO `zcxx` VALUES ('00001', 'BNN');
INSERT INTO `zcxx` VALUES ('00002', 'RC');
INSERT INTO `zdqdyflxx` VALUES ('00001', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('00002', 'AC220V');
