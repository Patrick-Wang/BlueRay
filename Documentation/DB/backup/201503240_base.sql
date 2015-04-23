/*
MySQL Data Transfer
Source Host: localhost
Source Database: bluelightplm
Target Host: localhost
Target Database: bluelightplm
Date: 2015/3/24 13:20:24
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
-- Table structure for bzxdtgg
-- ----------------------------
DROP TABLE IF EXISTS `bzxdtgg`;
CREATE TABLE `bzxdtgg` (
  `id` int(11) NOT NULL auto_increment,
  `bzxdtgg` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

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
  `htID` char(128) default NULL,
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
  `bz` varchar(1024) default NULL,
  `ddrq` date default NULL,
  `ddzt` char(16) character set utf8 collate utf8_unicode_ci default NULL,
  `zjdyID` int(11) default NULL,
  `zjysID` int(11) default NULL,
  `zdqxhID` int(11) default NULL,
  `zyz` char(1) character set utf8 collate utf8_unicode_ci default 'Y',
  `bzxdtggID` int(11) default NULL,
  `gh` char(128) character set utf8 collate utf8_unicode_ci default NULL,
  `zzsID` int(11) default NULL,
  `khqyID` int(11) default NULL,
  `sftgywsh` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `sftgjhsh` char(1) character set utf8 collate utf8_unicode_ci default NULL,
  `yxj` int(8) default '10',
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
-- Table structure for khqy
-- ----------------------------
DROP TABLE IF EXISTS `khqy`;
CREATE TABLE `khqy` (
  `id` int(11) NOT NULL auto_increment,
  `khqy` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for khxx
-- ----------------------------
DROP TABLE IF EXISTS `khxx`;
CREATE TABLE `khxx` (
  `clientID` int(11) NOT NULL auto_increment,
  `khmc` char(255) NOT NULL,
  `khcz` char(255) default NULL,
  `lxr` char(255) default NULL,
  `lxdh` char(255) default NULL,
  `qtnr` char(255) character set utf8 collate utf8_unicode_ci default NULL,
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
  `htxxID` int(11) NOT NULL,
  `jhscrq` date default NULL,
  `jhbzrq` date default NULL,
  `jhfhrq` date default NULL,
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
-- Table structure for permission
-- ----------------------------
DROP TABLE IF EXISTS `permission`;
CREATE TABLE `permission` (
  `role` char(100) NOT NULL,
  `xsywsh` tinyint(1) default '0',
  `xsjhsh` tinyint(1) default '0',
  `jhywsh` tinyint(1) default '0',
  `jhjhsh` tinyint(1) default '0',
  `jhbzywsh` tinyint(1) default '0',
  `jhbzjhsh` tinyint(1) default '0',
  `plan` tinyint(1) default '0',
  `sale` tinyint(1) default '0',
  PRIMARY KEY  (`role`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for serialnumber
-- ----------------------------
DROP TABLE IF EXISTS `serialnumber`;
CREATE TABLE `serialnumber` (
  `id` int(11) NOT NULL auto_increment,
  `max` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
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
  PRIMARY KEY  (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
-- Table structure for zdqxh
-- ----------------------------
DROP TABLE IF EXISTS `zdqxh`;
CREATE TABLE `zdqxh` (
  `id` int(11) NOT NULL auto_increment,
  `zdqxh` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for zjdy
-- ----------------------------
DROP TABLE IF EXISTS `zjdy`;
CREATE TABLE `zjdy` (
  `id` int(11) NOT NULL auto_increment,
  `zjdy` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for zjys
-- ----------------------------
DROP TABLE IF EXISTS `zjys`;
CREATE TABLE `zjys` (
  `id` int(11) NOT NULL auto_increment,
  `zjys` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for zzs
-- ----------------------------
DROP TABLE IF EXISTS `zzs`;
CREATE TABLE `zzs` (
  `id` int(11) NOT NULL auto_increment,
  `zzs` char(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `bmqxhflxx` VALUES ('1', '');
INSERT INTO `bmqxhflxx` VALUES ('2', '海1387');
INSERT INTO `bmqxhflxx` VALUES ('3', '多8192');
INSERT INTO `bmqxhflxx` VALUES ('4', '海1313');
INSERT INTO `bmqxhflxx` VALUES ('5', '海1321');
INSERT INTO `bmqxhflxx` VALUES ('6', '无');
INSERT INTO `bpqxhflxx` VALUES ('1', '');
INSERT INTO `bpqxhflxx` VALUES ('2', '新时达');
INSERT INTO `bpqxhflxx` VALUES ('3', '安川L1000A');
INSERT INTO `bpqxhflxx` VALUES ('4', '富士');
INSERT INTO `bpqxhflxx` VALUES ('5', '蓝光一体化');
INSERT INTO `bpqxhflxx` VALUES ('6', '默纳克');
INSERT INTO `bpqxhflxx` VALUES ('7', '华为');
INSERT INTO `bpqxhflxx` VALUES ('8', '富士VG7S');
INSERT INTO `bpqxhflxx` VALUES ('9', '爱默生');
INSERT INTO `bpqxhflxx` VALUES ('10', '施耐德');
INSERT INTO `bpqxhflxx` VALUES ('11', '安川');
INSERT INTO `bpqxhflxx` VALUES ('12', '科比');
INSERT INTO `bpqxhflxx` VALUES ('13', '蒙德');
INSERT INTO `bpqxhflxx` VALUES ('14', '爱默生EV3100');
INSERT INTO `bpqxhflxx` VALUES ('15', '蓝光一体机');
INSERT INTO `bpqxhflxx` VALUES ('16', 'FD450VL43A 60HP 45K');
INSERT INTO `bpqxhflxx` VALUES ('17', ' 安川');
INSERT INTO `bpqxhflxx` VALUES ('18', ' 默纳克');
INSERT INTO `bpqxhflxx` VALUES ('19', '新时达');
INSERT INTO `bpqxhflxx` VALUES ('20', ' 科比');
INSERT INTO `bpqxhflxx` VALUES ('21', 'CTRL70A系统');
INSERT INTO `bpqxhflxx` VALUES ('22', 'CTRL90系统');
INSERT INTO `bpqxhflxx` VALUES ('23', 'CTRL80系统');
INSERT INTO `bpqxhflxx` VALUES ('24', '富士LIFT');
INSERT INTO `bpqxhflxx` VALUES ('25', 'CTRL70A');
INSERT INTO `bpqxhflxx` VALUES ('26', 'CTRL90A系统');
INSERT INTO `bpqxhflxx` VALUES ('27', '酷马');
INSERT INTO `bpqxhflxx` VALUES ('28', '安川L7B');
INSERT INTO `bpqxhflxx` VALUES ('29', '安川CIMR-L5IP4015');
INSERT INTO `bpqxhflxx` VALUES ('30', '艾默生');
INSERT INTO `bpqxhflxx` VALUES ('31', 'CTRL90');
INSERT INTO `bpqxhflxx` VALUES ('32', '西威');
INSERT INTO `bpqxhflxx` VALUES ('33', '安川L1000E');
INSERT INTO `bpqxhflxx` VALUES ('34', ' 新时达');
INSERT INTO `bpqxhflxx` VALUES ('35', '台达一体机');
INSERT INTO `bpqxhflxx` VALUES ('36', '无');
INSERT INTO `bpqxhflxx` VALUES ('37', 'CV');
INSERT INTO `bzxdtgg` VALUES ('1', '');
INSERT INTO `bzxdtgg` VALUES ('2', '蓝光标准包装箱');
INSERT INTO `bzxdtgg` VALUES ('3', '特殊包装箱');
INSERT INTO `bzxdtgg` VALUES ('4', '出口免熏蒸包装箱');
INSERT INTO `bzxdtgg` VALUES ('5', '出口单层包装箱');
INSERT INTO `bzxdtgg` VALUES ('6', '出口2层包装箱');
INSERT INTO `bzxdtgg` VALUES ('42', '出口免熏蒸包装');
INSERT INTO `cpggxhxx` VALUES ('1', '');
INSERT INTO `cpggxhxx` VALUES ('2', 'S0.5A-N');
INSERT INTO `cpggxhxx` VALUES ('3', 'S1.0A-N');
INSERT INTO `cpggxhxx` VALUES ('4', 'S1.5A-N');
INSERT INTO `cpggxhxx` VALUES ('5', 'S1.6A-N');
INSERT INTO `cpggxhxx` VALUES ('6', 'S1.75A-N');
INSERT INTO `cpggxhxx` VALUES ('7', 'S2.0A-N');
INSERT INTO `cpggxhxx` VALUES ('8', 'S2.5AL-N');
INSERT INTO `cpggxhxx` VALUES ('9', 'S1.0B-N');
INSERT INTO `cpggxhxx` VALUES ('10', 'S1.5B-N');
INSERT INTO `cpggxhxx` VALUES ('11', 'S1.6B-N');
INSERT INTO `cpggxhxx` VALUES ('12', 'S1.75B-N');
INSERT INTO `cpggxhxx` VALUES ('13', 'S2.0B-N');
INSERT INTO `cpggxhxx` VALUES ('14', 'S2.5B-N');
INSERT INTO `cpggxhxx` VALUES ('15', 'S0.5C-N');
INSERT INTO `cpggxhxx` VALUES ('16', 'S1.0C-N');
INSERT INTO `cpggxhxx` VALUES ('17', 'S1.5C-N');
INSERT INTO `cpggxhxx` VALUES ('18', 'S1.6C-N');
INSERT INTO `cpggxhxx` VALUES ('19', 'S1.75C-N');
INSERT INTO `cpggxhxx` VALUES ('20', 'S2.0C-N');
INSERT INTO `cpggxhxx` VALUES ('21', 'S2.5C-N');
INSERT INTO `cpggxhxx` VALUES ('22', 'S0.5D-N');
INSERT INTO `cpggxhxx` VALUES ('23', 'S1.0D-N');
INSERT INTO `cpggxhxx` VALUES ('24', 'S1.5D-N');
INSERT INTO `cpggxhxx` VALUES ('25', 'S1.6D-N');
INSERT INTO `cpggxhxx` VALUES ('26', 'S1.75D-N');
INSERT INTO `cpggxhxx` VALUES ('27', 'S2.0D-N');
INSERT INTO `cpggxhxx` VALUES ('28', 'S2.5D-N');
INSERT INTO `cpggxhxx` VALUES ('29', 'S2.0BL-N');
INSERT INTO `cpggxhxx` VALUES ('30', 'S2.5AL-N');
INSERT INTO `cpggxhxx` VALUES ('31', 'S1.0CL-N');
INSERT INTO `cpggxhxx` VALUES ('32', 'S1.5CL-N');
INSERT INTO `cpggxhxx` VALUES ('33', 'S1.6CL-N');
INSERT INTO `cpggxhxx` VALUES ('34', 'S1.75CL-N');
INSERT INTO `cpggxhxx` VALUES ('35', 'S2.0CL-N');
INSERT INTO `cpggxhxx` VALUES ('36', 'S2.5CL-N');
INSERT INTO `cpggxhxx` VALUES ('37', 'S1.0DL-N');
INSERT INTO `cpggxhxx` VALUES ('38', 'S1.6DL-N');
INSERT INTO `cpggxhxx` VALUES ('39', 'S1.75DL-N');
INSERT INTO `cpggxhxx` VALUES ('40', 'S2.0DL-N');
INSERT INTO `cpggxhxx` VALUES ('41', 'S2.5DL-N');
INSERT INTO `cpggxhxx` VALUES ('42', 'S1.0E-N');
INSERT INTO `cpggxhxx` VALUES ('43', 'S1.5E-N');
INSERT INTO `cpggxhxx` VALUES ('44', 'S1.6E-N');
INSERT INTO `cpggxhxx` VALUES ('45', 'S1.75E-N');
INSERT INTO `cpggxhxx` VALUES ('46', 'S2.0E-N');
INSERT INTO `cpggxhxx` VALUES ('47', 'S2.5E-N');
INSERT INTO `cpggxhxx` VALUES ('48', 'TA0.5A-N');
INSERT INTO `cpggxhxx` VALUES ('49', 'TA1.0A-N');
INSERT INTO `cpggxhxx` VALUES ('50', 'TA1.5A-N');
INSERT INTO `cpggxhxx` VALUES ('51', 'TA1.6A-N');
INSERT INTO `cpggxhxx` VALUES ('52', 'TA1.75A-N');
INSERT INTO `cpggxhxx` VALUES ('53', 'TA2.0A-N');
INSERT INTO `cpggxhxx` VALUES ('54', 'T2.0AL-N');
INSERT INTO `cpggxhxx` VALUES ('55', 'TA0.5B-N');
INSERT INTO `cpggxhxx` VALUES ('56', 'TA1.0B-N');
INSERT INTO `cpggxhxx` VALUES ('57', 'TA1.5B-N');
INSERT INTO `cpggxhxx` VALUES ('58', 'TA1.6B-N');
INSERT INTO `cpggxhxx` VALUES ('59', 'TA1.75B-N');
INSERT INTO `cpggxhxx` VALUES ('60', 'TA2.0B-N');
INSERT INTO `cpggxhxx` VALUES ('61', 'TA1.0BL-N');
INSERT INTO `cpggxhxx` VALUES ('62', 'TA1.5BL-N');
INSERT INTO `cpggxhxx` VALUES ('63', 'TA2.0BL-N');
INSERT INTO `cpggxhxx` VALUES ('64', 'TA0.5C-N');
INSERT INTO `cpggxhxx` VALUES ('65', 'TA1.0C-N');
INSERT INTO `cpggxhxx` VALUES ('66', 'TA1.5C-N');
INSERT INTO `cpggxhxx` VALUES ('67', 'TA1.6C-N');
INSERT INTO `cpggxhxx` VALUES ('68', 'TA1.75C-N');
INSERT INTO `cpggxhxx` VALUES ('69', 'TA2.0C-N');
INSERT INTO `cpggxhxx` VALUES ('70', 'TA0.5D-N');
INSERT INTO `cpggxhxx` VALUES ('71', 'TA1.0D-N');
INSERT INTO `cpggxhxx` VALUES ('72', 'TA1.5D-N');
INSERT INTO `cpggxhxx` VALUES ('73', 'TA1.6D-N');
INSERT INTO `cpggxhxx` VALUES ('74', 'TA1.75D-N');
INSERT INTO `cpggxhxx` VALUES ('75', 'TA2.0D-N');
INSERT INTO `cpggxhxx` VALUES ('76', 'TA0.5E-N');
INSERT INTO `cpggxhxx` VALUES ('77', 'TA1.0E-N');
INSERT INTO `cpggxhxx` VALUES ('78', 'TA1.5E-N');
INSERT INTO `cpggxhxx` VALUES ('79', 'TA1.6E-N');
INSERT INTO `cpggxhxx` VALUES ('80', 'TA1.75E-N');
INSERT INTO `cpggxhxx` VALUES ('81', 'TA2.0E-N');
INSERT INTO `cpggxhxx` VALUES ('82', 'TA1.0AL-N');
INSERT INTO `cpggxhxx` VALUES ('83', 'TA1.5BL-N');
INSERT INTO `cpggxhxx` VALUES ('84', 'TA1.75BL-N');
INSERT INTO `cpggxhxx` VALUES ('85', 'TA1.0CL-N');
INSERT INTO `cpggxhxx` VALUES ('86', 'TA1.5CL-N');
INSERT INTO `cpggxhxx` VALUES ('87', 'TA1.6CL-N');
INSERT INTO `cpggxhxx` VALUES ('88', 'TA1.75CL-N');
INSERT INTO `cpggxhxx` VALUES ('89', 'TA2.0CL-N');
INSERT INTO `cpggxhxx` VALUES ('90', 'TA0.5DL-N');
INSERT INTO `cpggxhxx` VALUES ('91', 'TA1.0DL-N');
INSERT INTO `cpggxhxx` VALUES ('92', 'TA1.5DL-N');
INSERT INTO `cpggxhxx` VALUES ('93', 'TA1.6DL-N');
INSERT INTO `cpggxhxx` VALUES ('94', 'TA1.75DL-N');
INSERT INTO `cpggxhxx` VALUES ('95', 'TA2.0DL-N');
INSERT INTO `cpggxhxx` VALUES ('96', 'T0.5AM-H');
INSERT INTO `cpggxhxx` VALUES ('97', 'T1.0AM-H');
INSERT INTO `cpggxhxx` VALUES ('98', 'T1.5AM-H');
INSERT INTO `cpggxhxx` VALUES ('99', 'T1.6AM-H');
INSERT INTO `cpggxhxx` VALUES ('100', 'T0.5BM-H');
INSERT INTO `cpggxhxx` VALUES ('101', 'T1.0BM-H');
INSERT INTO `cpggxhxx` VALUES ('102', 'T1.5BM-H');
INSERT INTO `cpggxhxx` VALUES ('103', 'T1.6BM-H');
INSERT INTO `cpggxhxx` VALUES ('104', 'T1.75BM-H');
INSERT INTO `cpggxhxx` VALUES ('105', 'S0.5A-H');
INSERT INTO `cpggxhxx` VALUES ('106', 'S1.0A-H');
INSERT INTO `cpggxhxx` VALUES ('107', 'S1.5A-H');
INSERT INTO `cpggxhxx` VALUES ('108', 'S1.6A-H');
INSERT INTO `cpggxhxx` VALUES ('109', 'S1.75A-H');
INSERT INTO `cpggxhxx` VALUES ('110', 'S2.0A-H');
INSERT INTO `cpggxhxx` VALUES ('111', 'S2.5AL-H');
INSERT INTO `cpggxhxx` VALUES ('112', 'S1.0B-H');
INSERT INTO `cpggxhxx` VALUES ('113', 'S1.5B-H');
INSERT INTO `cpggxhxx` VALUES ('114', 'S1.6B-H');
INSERT INTO `cpggxhxx` VALUES ('115', 'S1.75B-H');
INSERT INTO `cpggxhxx` VALUES ('116', 'S2.0B-H');
INSERT INTO `cpggxhxx` VALUES ('117', 'S2.5B-H');
INSERT INTO `cpggxhxx` VALUES ('118', 'S0.5C-H');
INSERT INTO `cpggxhxx` VALUES ('119', 'S1.0C-H');
INSERT INTO `cpggxhxx` VALUES ('120', 'S1.5C-H');
INSERT INTO `cpggxhxx` VALUES ('121', 'S1.6C-H');
INSERT INTO `cpggxhxx` VALUES ('122', 'S1.75C-H');
INSERT INTO `cpggxhxx` VALUES ('123', 'S2.0C-H');
INSERT INTO `cpggxhxx` VALUES ('124', 'S2.5C-H');
INSERT INTO `cpggxhxx` VALUES ('125', 'S0.5D-H');
INSERT INTO `cpggxhxx` VALUES ('126', 'S1.0D-H');
INSERT INTO `cpggxhxx` VALUES ('127', 'S1.5D-H');
INSERT INTO `cpggxhxx` VALUES ('128', 'S1.6D-H');
INSERT INTO `cpggxhxx` VALUES ('129', 'S1.75D-H');
INSERT INTO `cpggxhxx` VALUES ('130', 'S2.0D-H');
INSERT INTO `cpggxhxx` VALUES ('131', 'S2.5D-H');
INSERT INTO `cpggxhxx` VALUES ('132', 'S2.0BL-H');
INSERT INTO `cpggxhxx` VALUES ('133', 'S2.5AL-H');
INSERT INTO `cpggxhxx` VALUES ('134', 'S1.0CL-H');
INSERT INTO `cpggxhxx` VALUES ('135', 'S1.5CL-H');
INSERT INTO `cpggxhxx` VALUES ('136', 'S1.6CL-H');
INSERT INTO `cpggxhxx` VALUES ('137', 'S1.75CL-H');
INSERT INTO `cpggxhxx` VALUES ('138', 'S2.0CL-H');
INSERT INTO `cpggxhxx` VALUES ('139', 'S2.5CL-H');
INSERT INTO `cpggxhxx` VALUES ('140', 'S1.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('141', 'S1.6DL-H');
INSERT INTO `cpggxhxx` VALUES ('142', 'S1.75DL-H');
INSERT INTO `cpggxhxx` VALUES ('143', 'S2.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('144', 'S2.5DL-H');
INSERT INTO `cpggxhxx` VALUES ('145', 'S1.0E-H');
INSERT INTO `cpggxhxx` VALUES ('146', 'S1.5E-H');
INSERT INTO `cpggxhxx` VALUES ('147', 'S1.6E-H');
INSERT INTO `cpggxhxx` VALUES ('148', 'S1.75E-H');
INSERT INTO `cpggxhxx` VALUES ('149', 'S2.0E-H');
INSERT INTO `cpggxhxx` VALUES ('150', 'S2.5E-H');
INSERT INTO `cpggxhxx` VALUES ('151', 'TA0.5A-H');
INSERT INTO `cpggxhxx` VALUES ('152', 'TA1.0A-H');
INSERT INTO `cpggxhxx` VALUES ('153', 'TA1.5A-H');
INSERT INTO `cpggxhxx` VALUES ('154', 'TA1.6A-H');
INSERT INTO `cpggxhxx` VALUES ('155', 'TA1.75A-H');
INSERT INTO `cpggxhxx` VALUES ('156', 'TA2.0A-H');
INSERT INTO `cpggxhxx` VALUES ('157', 'T2.0AL-H');
INSERT INTO `cpggxhxx` VALUES ('158', 'TA0.5B-H');
INSERT INTO `cpggxhxx` VALUES ('159', 'TA1.0B-H');
INSERT INTO `cpggxhxx` VALUES ('160', 'TA1.5B-H');
INSERT INTO `cpggxhxx` VALUES ('161', 'TA1.6B-H');
INSERT INTO `cpggxhxx` VALUES ('162', 'TA1.75B-H');
INSERT INTO `cpggxhxx` VALUES ('163', 'TA2.0B-H');
INSERT INTO `cpggxhxx` VALUES ('164', 'TA1.0BL-H');
INSERT INTO `cpggxhxx` VALUES ('165', 'TA1.5BL-H');
INSERT INTO `cpggxhxx` VALUES ('166', 'TA2.0BL-H');
INSERT INTO `cpggxhxx` VALUES ('167', 'TA0.5C-H');
INSERT INTO `cpggxhxx` VALUES ('168', 'TA1.0C-H');
INSERT INTO `cpggxhxx` VALUES ('169', 'TA1.5C-H');
INSERT INTO `cpggxhxx` VALUES ('170', 'TA1.6C-H');
INSERT INTO `cpggxhxx` VALUES ('171', 'TA1.75C-H');
INSERT INTO `cpggxhxx` VALUES ('172', 'TA2.0C-H');
INSERT INTO `cpggxhxx` VALUES ('173', 'TA0.5D-H');
INSERT INTO `cpggxhxx` VALUES ('174', 'TA1.0D-H');
INSERT INTO `cpggxhxx` VALUES ('175', 'TA1.5D-H');
INSERT INTO `cpggxhxx` VALUES ('176', 'TA1.6D-H');
INSERT INTO `cpggxhxx` VALUES ('177', 'TA1.75D-H');
INSERT INTO `cpggxhxx` VALUES ('178', 'TA2.0D-H');
INSERT INTO `cpggxhxx` VALUES ('179', 'TA0.5E-H');
INSERT INTO `cpggxhxx` VALUES ('180', 'TA1.0E-H');
INSERT INTO `cpggxhxx` VALUES ('181', 'TA1.5E-H');
INSERT INTO `cpggxhxx` VALUES ('182', 'TA1.6E-H');
INSERT INTO `cpggxhxx` VALUES ('183', 'TA1.75E-H');
INSERT INTO `cpggxhxx` VALUES ('184', 'TA2.0E-H');
INSERT INTO `cpggxhxx` VALUES ('185', 'TA1.0AL-H');
INSERT INTO `cpggxhxx` VALUES ('186', 'TA1.5BL-H');
INSERT INTO `cpggxhxx` VALUES ('187', 'TA1.75BL-H');
INSERT INTO `cpggxhxx` VALUES ('188', 'TA1.0CL-H');
INSERT INTO `cpggxhxx` VALUES ('189', 'TA1.5CL-H');
INSERT INTO `cpggxhxx` VALUES ('190', 'TA1.6CL-H');
INSERT INTO `cpggxhxx` VALUES ('191', 'TA1.75CL-H');
INSERT INTO `cpggxhxx` VALUES ('192', 'TA2.0CL-H');
INSERT INTO `cpggxhxx` VALUES ('193', 'TA0.5DL-H');
INSERT INTO `cpggxhxx` VALUES ('194', 'TA1.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('195', 'TA1.5DL-H');
INSERT INTO `cpggxhxx` VALUES ('196', 'TA1.6DL-H');
INSERT INTO `cpggxhxx` VALUES ('197', 'TA1.75DL-H');
INSERT INTO `cpggxhxx` VALUES ('198', 'TA2.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('199', 'TA1.0B(S)-H');
INSERT INTO `cpggxhxx` VALUES ('200', 'TA1.5B(S)-H');
INSERT INTO `cpggxhxx` VALUES ('201', 'TA1.75B(S)-H');
INSERT INTO `cpggxhxx` VALUES ('202', 'TA2.0B(S)-H');
INSERT INTO `cpggxhxx` VALUES ('203', 'TA1.0C(S)-H');
INSERT INTO `cpggxhxx` VALUES ('204', 'TA1.5C(S)-H');
INSERT INTO `cpggxhxx` VALUES ('205', 'TA1.75C(S)-H');
INSERT INTO `cpggxhxx` VALUES ('206', 'TA2.0C(S)-H');
INSERT INTO `cpggxhxx` VALUES ('207', 'TA1.0D(S)-H');
INSERT INTO `cpggxhxx` VALUES ('208', 'TA1.5D(S)-H');
INSERT INTO `cpggxhxx` VALUES ('209', 'TA1.75D(S)-H');
INSERT INTO `cpggxhxx` VALUES ('210', 'TA2.0D(S)-H');
INSERT INTO `cpggxhxx` VALUES ('211', 'TA1.0E(S)-H');
INSERT INTO `cpggxhxx` VALUES ('212', 'TA1.75E(S)-H');
INSERT INTO `cpggxhxx` VALUES ('213', 'TA2.0E(S)-H');
INSERT INTO `cpggxhxx` VALUES ('214', 'U0.5DS-H');
INSERT INTO `cpggxhxx` VALUES ('215', 'U1.0DS-H');
INSERT INTO `cpggxhxx` VALUES ('216', 'U1.5DS-H');
INSERT INTO `cpggxhxx` VALUES ('217', 'U1.6DS-H');
INSERT INTO `cpggxhxx` VALUES ('218', 'U1.75DS-H');
INSERT INTO `cpggxhxx` VALUES ('219', 'U2.0DS-H');
INSERT INTO `cpggxhxx` VALUES ('220', 'U2.5DS-H');
INSERT INTO `cpggxhxx` VALUES ('221', 'U0.5ES-H');
INSERT INTO `cpggxhxx` VALUES ('222', 'U1.0ES-H');
INSERT INTO `cpggxhxx` VALUES ('223', 'U1.5ES-H');
INSERT INTO `cpggxhxx` VALUES ('224', 'U1.6ES-H');
INSERT INTO `cpggxhxx` VALUES ('225', 'U1.75ES-H');
INSERT INTO `cpggxhxx` VALUES ('226', 'U2.0ES-H');
INSERT INTO `cpggxhxx` VALUES ('227', 'U2.5ES-H');
INSERT INTO `cpggxhxx` VALUES ('228', 'U0.5FS-H');
INSERT INTO `cpggxhxx` VALUES ('229', 'U1.0FS-H');
INSERT INTO `cpggxhxx` VALUES ('230', 'U1.5FS-H');
INSERT INTO `cpggxhxx` VALUES ('231', 'U1.6FS-H');
INSERT INTO `cpggxhxx` VALUES ('232', 'U1.75FS-H');
INSERT INTO `cpggxhxx` VALUES ('233', 'U2.0FS-H');
INSERT INTO `cpggxhxx` VALUES ('234', 'U2.5FS-H');
INSERT INTO `cpggxhxx` VALUES ('235', 'U2.5BCS-H');
INSERT INTO `cpggxhxx` VALUES ('236', 'U3.0CS-H');
INSERT INTO `cpggxhxx` VALUES ('237', 'Y1.0A1-H');
INSERT INTO `cpggxhxx` VALUES ('238', 'Y1.6A1-H');
INSERT INTO `cpggxhxx` VALUES ('239', 'Y1.75A1-H');
INSERT INTO `cpggxhxx` VALUES ('240', 'Y2.0A1-H');
INSERT INTO `cpggxhxx` VALUES ('241', 'Y2.5A1-H');
INSERT INTO `cpggxhxx` VALUES ('242', 'Y3.0A1-H');
INSERT INTO `cpggxhxx` VALUES ('243', 'Y4.0A1-H');
INSERT INTO `cpggxhxx` VALUES ('244', 'Y2.0A2-H');
INSERT INTO `cpggxhxx` VALUES ('245', 'Y2.5A2-H');
INSERT INTO `cpggxhxx` VALUES ('246', 'Y2.0A3-H');
INSERT INTO `cpggxhxx` VALUES ('247', 'Y2.5A3-H');
INSERT INTO `cpggxhxx` VALUES ('248', 'Y3.0A3-H');
INSERT INTO `cpggxhxx` VALUES ('249', 'Y4.0A3-H');
INSERT INTO `cpggxhxx` VALUES ('250', 'Y1.0B1-H');
INSERT INTO `cpggxhxx` VALUES ('251', 'Y1.6B1-H');
INSERT INTO `cpggxhxx` VALUES ('252', 'Y1.75B1-H');
INSERT INTO `cpggxhxx` VALUES ('253', 'Y2.0B1-H');
INSERT INTO `cpggxhxx` VALUES ('254', 'Y2.5B1-H');
INSERT INTO `cpggxhxx` VALUES ('255', 'Y3.0B1-H');
INSERT INTO `cpggxhxx` VALUES ('256', 'Y4.0B1-H');
INSERT INTO `cpggxhxx` VALUES ('257', 'Y1.75B2-H');
INSERT INTO `cpggxhxx` VALUES ('258', 'Y2.0B2-H');
INSERT INTO `cpggxhxx` VALUES ('259', 'Y3.0B2-H');
INSERT INTO `cpggxhxx` VALUES ('260', 'Y2.5B2-H');
INSERT INTO `cpggxhxx` VALUES ('261', 'Y3.5B2-H');
INSERT INTO `cpggxhxx` VALUES ('262', 'Y4.0B2-H');
INSERT INTO `cpggxhxx` VALUES ('263', 'Y1.0B3-H');
INSERT INTO `cpggxhxx` VALUES ('264', 'Y1.75B3-H');
INSERT INTO `cpggxhxx` VALUES ('265', 'Y2.0B3-H');
INSERT INTO `cpggxhxx` VALUES ('266', 'Y2.5B3-H');
INSERT INTO `cpggxhxx` VALUES ('267', 'Y3.0B3-H');
INSERT INTO `cpggxhxx` VALUES ('268', 'Y4.0B3-H');
INSERT INTO `cpggxhxx` VALUES ('269', 'Y1.0BC-H');
INSERT INTO `cpggxhxx` VALUES ('270', 'Y1.75BC-H');
INSERT INTO `cpggxhxx` VALUES ('271', 'Y2.5BC-H');
INSERT INTO `cpggxhxx` VALUES ('272', 'Y1.0BC3-H');
INSERT INTO `cpggxhxx` VALUES ('273', 'Y2.5BC2-H');
INSERT INTO `cpggxhxx` VALUES ('274', 'Y3.0BC2-H');
INSERT INTO `cpggxhxx` VALUES ('275', 'Y4.0BC2-H');
INSERT INTO `cpggxhxx` VALUES ('276', 'Y1.6BC3-H');
INSERT INTO `cpggxhxx` VALUES ('277', 'Y1.75BC3-H');
INSERT INTO `cpggxhxx` VALUES ('278', 'Y2.0BC3-H');
INSERT INTO `cpggxhxx` VALUES ('279', 'Y2.5BC3-H');
INSERT INTO `cpggxhxx` VALUES ('280', 'Y3.0BC3-H');
INSERT INTO `cpggxhxx` VALUES ('281', 'Y4.0BC3-H');
INSERT INTO `cpggxhxx` VALUES ('282', 'Y1.0C1-H');
INSERT INTO `cpggxhxx` VALUES ('283', 'Y1.5C1-H');
INSERT INTO `cpggxhxx` VALUES ('284', 'Y1.6C1-H');
INSERT INTO `cpggxhxx` VALUES ('285', 'Y1.75C1-H');
INSERT INTO `cpggxhxx` VALUES ('286', 'Y2.0C1-H');
INSERT INTO `cpggxhxx` VALUES ('287', 'Y2.5C1-H');
INSERT INTO `cpggxhxx` VALUES ('288', 'Y3.0C1-H');
INSERT INTO `cpggxhxx` VALUES ('289', 'Y3.5C1-H');
INSERT INTO `cpggxhxx` VALUES ('290', 'Y4.0C1-H');
INSERT INTO `cpggxhxx` VALUES ('291', 'Y1.0C2-H');
INSERT INTO `cpggxhxx` VALUES ('292', 'Y2.5C2-H');
INSERT INTO `cpggxhxx` VALUES ('293', 'Y2.0C2-H');
INSERT INTO `cpggxhxx` VALUES ('294', 'Y3.0C2-H');
INSERT INTO `cpggxhxx` VALUES ('295', 'Y3.5C2-H');
INSERT INTO `cpggxhxx` VALUES ('296', 'Y1.0C3-H');
INSERT INTO `cpggxhxx` VALUES ('297', 'Y1.6C3-H');
INSERT INTO `cpggxhxx` VALUES ('298', 'Y1.75C3-H');
INSERT INTO `cpggxhxx` VALUES ('299', 'Y2.0C3-H');
INSERT INTO `cpggxhxx` VALUES ('300', 'Y2.5C3-H');
INSERT INTO `cpggxhxx` VALUES ('301', 'Y3.0C3-H');
INSERT INTO `cpggxhxx` VALUES ('302', 'Y1.0D1-H');
INSERT INTO `cpggxhxx` VALUES ('303', 'Y1.5D1-H');
INSERT INTO `cpggxhxx` VALUES ('304', 'Y1.6D1-H');
INSERT INTO `cpggxhxx` VALUES ('305', 'Y1.75D1-H');
INSERT INTO `cpggxhxx` VALUES ('306', 'Y2.0D1-H');
INSERT INTO `cpggxhxx` VALUES ('307', 'Y2.5D1-H');
INSERT INTO `cpggxhxx` VALUES ('308', 'Y3.0D1-H');
INSERT INTO `cpggxhxx` VALUES ('309', 'Y3.5D1-H');
INSERT INTO `cpggxhxx` VALUES ('310', 'Y4.0D1-H');
INSERT INTO `cpggxhxx` VALUES ('311', 'Y5.0D1-H');
INSERT INTO `cpggxhxx` VALUES ('312', 'Y1.0D2-H');
INSERT INTO `cpggxhxx` VALUES ('313', 'Y1.6D2-H');
INSERT INTO `cpggxhxx` VALUES ('314', 'Y2.0D2-H');
INSERT INTO `cpggxhxx` VALUES ('315', 'Y2.5D2-H');
INSERT INTO `cpggxhxx` VALUES ('316', 'Y3.0D2-H');
INSERT INTO `cpggxhxx` VALUES ('317', 'Y4.0D2-H');
INSERT INTO `cpggxhxx` VALUES ('318', 'Y1.0D3-H');
INSERT INTO `cpggxhxx` VALUES ('319', 'Y1.6D3-H');
INSERT INTO `cpggxhxx` VALUES ('320', 'Y1.75D3-H');
INSERT INTO `cpggxhxx` VALUES ('321', 'Y2.0D3-H');
INSERT INTO `cpggxhxx` VALUES ('322', 'Y2.5D3-H');
INSERT INTO `cpggxhxx` VALUES ('323', 'Y3.0D3-H');
INSERT INTO `cpggxhxx` VALUES ('324', 'Y4.0D3-H');
INSERT INTO `cpggxhxx` VALUES ('325', 'Y0.5E1-H');
INSERT INTO `cpggxhxx` VALUES ('326', 'Y1.0E1-H');
INSERT INTO `cpggxhxx` VALUES ('327', 'Y1.5E1-H');
INSERT INTO `cpggxhxx` VALUES ('328', 'Y1.6E1-H');
INSERT INTO `cpggxhxx` VALUES ('329', 'Y1.75E1-H');
INSERT INTO `cpggxhxx` VALUES ('330', 'Y2.0E1-H');
INSERT INTO `cpggxhxx` VALUES ('331', 'Y2.5E1-H');
INSERT INTO `cpggxhxx` VALUES ('332', 'Y3.0E1-H');
INSERT INTO `cpggxhxx` VALUES ('333', 'Y4.0E1-H');
INSERT INTO `cpggxhxx` VALUES ('334', 'Y4.0E2-H');
INSERT INTO `cpggxhxx` VALUES ('335', 'Y1.0E2-H');
INSERT INTO `cpggxhxx` VALUES ('336', 'Y1.5E2-H');
INSERT INTO `cpggxhxx` VALUES ('337', 'Y1.6E2-H');
INSERT INTO `cpggxhxx` VALUES ('338', 'Y1.75E2-H');
INSERT INTO `cpggxhxx` VALUES ('339', 'Y2.0E2-H');
INSERT INTO `cpggxhxx` VALUES ('340', 'Y2.5E2-H');
INSERT INTO `cpggxhxx` VALUES ('341', 'Y3.0E2-H');
INSERT INTO `cpggxhxx` VALUES ('342', 'Y3.5E2-H');
INSERT INTO `cpggxhxx` VALUES ('343', 'Y4.0E2-H');
INSERT INTO `cpggxhxx` VALUES ('344', 'Y1.0E3-H');
INSERT INTO `cpggxhxx` VALUES ('345', 'Y1.6E3-H');
INSERT INTO `cpggxhxx` VALUES ('346', 'Y1.75E3-H');
INSERT INTO `cpggxhxx` VALUES ('347', 'Y2.0E3-H');
INSERT INTO `cpggxhxx` VALUES ('348', 'Y2.5E3-H');
INSERT INTO `cpggxhxx` VALUES ('349', 'Y3.0E3-H');
INSERT INTO `cpggxhxx` VALUES ('350', 'Y4.0E3-H');
INSERT INTO `cpggxhxx` VALUES ('351', 'Y1.0EF2-H');
INSERT INTO `cpggxhxx` VALUES ('352', 'Y3.0EF2-H');
INSERT INTO `cpggxhxx` VALUES ('353', 'Y1.0EF3-H');
INSERT INTO `cpggxhxx` VALUES ('354', 'Y1.6EF3-H');
INSERT INTO `cpggxhxx` VALUES ('355', 'Y0.5F1-H');
INSERT INTO `cpggxhxx` VALUES ('356', 'Y1.0F1-H');
INSERT INTO `cpggxhxx` VALUES ('357', 'Y1.6F1-H');
INSERT INTO `cpggxhxx` VALUES ('358', 'Y1.75F1-H');
INSERT INTO `cpggxhxx` VALUES ('359', 'Y2.0F1-H');
INSERT INTO `cpggxhxx` VALUES ('360', 'Y2.5F1-H');
INSERT INTO `cpggxhxx` VALUES ('361', 'Y3.0F1-H');
INSERT INTO `cpggxhxx` VALUES ('362', 'Y4.0F1-H');
INSERT INTO `cpggxhxx` VALUES ('363', 'Y1.0F2-H');
INSERT INTO `cpggxhxx` VALUES ('364', 'Y1.6F2-H');
INSERT INTO `cpggxhxx` VALUES ('365', 'Y2.0F2-H');
INSERT INTO `cpggxhxx` VALUES ('366', 'Y3.0F2-H');
INSERT INTO `cpggxhxx` VALUES ('367', 'Y4.0F2-H');
INSERT INTO `cpggxhxx` VALUES ('368', 'Y2.5F2-H');
INSERT INTO `cpggxhxx` VALUES ('369', 'Y0.5F3-H');
INSERT INTO `cpggxhxx` VALUES ('370', 'Y1.0F3-H');
INSERT INTO `cpggxhxx` VALUES ('371', 'Y1.6F3-H');
INSERT INTO `cpggxhxx` VALUES ('372', 'Y1.75F3-H');
INSERT INTO `cpggxhxx` VALUES ('373', 'Y2.0F3-H');
INSERT INTO `cpggxhxx` VALUES ('374', 'Y3.0F3-H');
INSERT INTO `cpggxhxx` VALUES ('375', 'Y4.0F3-H');
INSERT INTO `cpggxhxx` VALUES ('376', 'Y1.5G3-H');
INSERT INTO `cpggxhxx` VALUES ('377', 'Y1.0A1-N');
INSERT INTO `cpggxhxx` VALUES ('378', 'Y1.6A1-N');
INSERT INTO `cpggxhxx` VALUES ('379', 'Y1.75A1-N');
INSERT INTO `cpggxhxx` VALUES ('380', 'Y2.0A1-N');
INSERT INTO `cpggxhxx` VALUES ('381', 'Y2.5A1-N');
INSERT INTO `cpggxhxx` VALUES ('382', 'Y3.0A1-N');
INSERT INTO `cpggxhxx` VALUES ('383', 'Y4.0A1-N');
INSERT INTO `cpggxhxx` VALUES ('384', 'Y2.0A2-N');
INSERT INTO `cpggxhxx` VALUES ('385', 'Y2.5A2-N');
INSERT INTO `cpggxhxx` VALUES ('386', 'Y2.0A3-N');
INSERT INTO `cpggxhxx` VALUES ('387', 'Y2.5A3-N');
INSERT INTO `cpggxhxx` VALUES ('388', 'Y3.0A3-N');
INSERT INTO `cpggxhxx` VALUES ('389', 'Y4.0A3-N');
INSERT INTO `cpggxhxx` VALUES ('390', 'Y1.0B1-N');
INSERT INTO `cpggxhxx` VALUES ('391', 'Y1.6B1-N');
INSERT INTO `cpggxhxx` VALUES ('392', 'Y1.75B1-N');
INSERT INTO `cpggxhxx` VALUES ('393', 'Y2.0B1-N');
INSERT INTO `cpggxhxx` VALUES ('394', 'Y2.5B1-N');
INSERT INTO `cpggxhxx` VALUES ('395', 'Y3.0B1-N');
INSERT INTO `cpggxhxx` VALUES ('396', 'Y4.0B1-N');
INSERT INTO `cpggxhxx` VALUES ('397', 'Y1.75B2-N');
INSERT INTO `cpggxhxx` VALUES ('398', 'Y2.0B2-N');
INSERT INTO `cpggxhxx` VALUES ('399', 'Y3.0B2-N');
INSERT INTO `cpggxhxx` VALUES ('400', 'Y2.5B2-N');
INSERT INTO `cpggxhxx` VALUES ('401', 'Y3.5B2-N');
INSERT INTO `cpggxhxx` VALUES ('402', 'Y4.0B2-N');
INSERT INTO `cpggxhxx` VALUES ('403', 'Y1.0B3-N');
INSERT INTO `cpggxhxx` VALUES ('404', 'Y1.75B3-N');
INSERT INTO `cpggxhxx` VALUES ('405', 'Y2.0B3-N');
INSERT INTO `cpggxhxx` VALUES ('406', 'Y2.5B3-N');
INSERT INTO `cpggxhxx` VALUES ('407', 'Y3.0B3-N');
INSERT INTO `cpggxhxx` VALUES ('408', 'Y4.0B3-N');
INSERT INTO `cpggxhxx` VALUES ('409', 'Y1.0BC-N');
INSERT INTO `cpggxhxx` VALUES ('410', 'Y1.75BC-N');
INSERT INTO `cpggxhxx` VALUES ('411', 'Y2.5BC-N');
INSERT INTO `cpggxhxx` VALUES ('412', 'Y1.0BC3-N');
INSERT INTO `cpggxhxx` VALUES ('413', 'Y2.5BC2-N');
INSERT INTO `cpggxhxx` VALUES ('414', 'Y3.0BC2-N');
INSERT INTO `cpggxhxx` VALUES ('415', 'Y4.0BC2-N');
INSERT INTO `cpggxhxx` VALUES ('416', 'Y1.6BC3-N');
INSERT INTO `cpggxhxx` VALUES ('417', 'Y1.75BC3-N');
INSERT INTO `cpggxhxx` VALUES ('418', 'Y2.0BC3-N');
INSERT INTO `cpggxhxx` VALUES ('419', 'Y2.5BC3-N');
INSERT INTO `cpggxhxx` VALUES ('420', 'Y3.0BC3-N');
INSERT INTO `cpggxhxx` VALUES ('421', 'Y4.0BC3-N');
INSERT INTO `cpggxhxx` VALUES ('422', 'Y1.0C1-N');
INSERT INTO `cpggxhxx` VALUES ('423', 'Y1.5C1-N');
INSERT INTO `cpggxhxx` VALUES ('424', 'Y1.6C1-N');
INSERT INTO `cpggxhxx` VALUES ('425', 'Y1.75C1-N');
INSERT INTO `cpggxhxx` VALUES ('426', 'Y2.0C1-N');
INSERT INTO `cpggxhxx` VALUES ('427', 'Y2.5C1-N');
INSERT INTO `cpggxhxx` VALUES ('428', 'Y3.0C1-N');
INSERT INTO `cpggxhxx` VALUES ('429', 'Y3.5C1-N');
INSERT INTO `cpggxhxx` VALUES ('430', 'Y4.0C1-N');
INSERT INTO `cpggxhxx` VALUES ('431', 'Y1.0C2-N');
INSERT INTO `cpggxhxx` VALUES ('432', 'Y2.5C2-N');
INSERT INTO `cpggxhxx` VALUES ('433', 'Y2.0C2-N');
INSERT INTO `cpggxhxx` VALUES ('434', 'Y3.0C2-N');
INSERT INTO `cpggxhxx` VALUES ('435', 'Y3.5C2-N');
INSERT INTO `cpggxhxx` VALUES ('436', 'Y1.0C3-N');
INSERT INTO `cpggxhxx` VALUES ('437', 'Y1.6C3-N');
INSERT INTO `cpggxhxx` VALUES ('438', 'Y1.75C3-N');
INSERT INTO `cpggxhxx` VALUES ('439', 'Y2.0C3-N');
INSERT INTO `cpggxhxx` VALUES ('440', 'Y2.5C3-N');
INSERT INTO `cpggxhxx` VALUES ('441', 'Y3.0C3-N');
INSERT INTO `cpggxhxx` VALUES ('442', 'Y1.0D1-N');
INSERT INTO `cpggxhxx` VALUES ('443', 'Y1.5D1-N');
INSERT INTO `cpggxhxx` VALUES ('444', 'Y1.6D1-N');
INSERT INTO `cpggxhxx` VALUES ('445', 'Y1.75D1-N');
INSERT INTO `cpggxhxx` VALUES ('446', 'Y2.0D1-N');
INSERT INTO `cpggxhxx` VALUES ('447', 'Y2.5D1-N');
INSERT INTO `cpggxhxx` VALUES ('448', 'Y3.0D1-N');
INSERT INTO `cpggxhxx` VALUES ('449', 'Y3.5D1-N');
INSERT INTO `cpggxhxx` VALUES ('450', 'Y4.0D1-N');
INSERT INTO `cpggxhxx` VALUES ('451', 'Y5.0D1-N');
INSERT INTO `cpggxhxx` VALUES ('452', 'Y1.0D2-N');
INSERT INTO `cpggxhxx` VALUES ('453', 'Y1.6D2-N');
INSERT INTO `cpggxhxx` VALUES ('454', 'Y2.0D2-N');
INSERT INTO `cpggxhxx` VALUES ('455', 'Y2.5D2-N');
INSERT INTO `cpggxhxx` VALUES ('456', 'Y3.0D2-N');
INSERT INTO `cpggxhxx` VALUES ('457', 'Y4.0D2-N');
INSERT INTO `cpggxhxx` VALUES ('458', 'Y1.0D3-N');
INSERT INTO `cpggxhxx` VALUES ('459', 'Y1.6D3-N');
INSERT INTO `cpggxhxx` VALUES ('460', 'Y1.75D3-N');
INSERT INTO `cpggxhxx` VALUES ('461', 'Y2.0D3-N');
INSERT INTO `cpggxhxx` VALUES ('462', 'Y2.5D3-N');
INSERT INTO `cpggxhxx` VALUES ('463', 'Y3.0D3-N');
INSERT INTO `cpggxhxx` VALUES ('464', 'Y4.0D3-N');
INSERT INTO `cpggxhxx` VALUES ('465', 'Y0.5E1-N');
INSERT INTO `cpggxhxx` VALUES ('466', 'Y1.0E1-N');
INSERT INTO `cpggxhxx` VALUES ('467', 'Y1.5E1-N');
INSERT INTO `cpggxhxx` VALUES ('468', 'Y1.6E1-N');
INSERT INTO `cpggxhxx` VALUES ('469', 'Y1.75E1-N');
INSERT INTO `cpggxhxx` VALUES ('470', 'Y2.0E1-N');
INSERT INTO `cpggxhxx` VALUES ('471', 'Y2.5E1-N');
INSERT INTO `cpggxhxx` VALUES ('472', 'Y3.0E1-N');
INSERT INTO `cpggxhxx` VALUES ('473', 'Y4.0E1-N');
INSERT INTO `cpggxhxx` VALUES ('474', 'Y4.0E2-N');
INSERT INTO `cpggxhxx` VALUES ('475', 'Y1.0E2-N');
INSERT INTO `cpggxhxx` VALUES ('476', 'Y1.5E2-N');
INSERT INTO `cpggxhxx` VALUES ('477', 'Y1.6E2-N');
INSERT INTO `cpggxhxx` VALUES ('478', 'Y1.75E2-N');
INSERT INTO `cpggxhxx` VALUES ('479', 'Y2.0E2-N');
INSERT INTO `cpggxhxx` VALUES ('480', 'Y2.5E2-N');
INSERT INTO `cpggxhxx` VALUES ('481', 'Y3.0E2-N');
INSERT INTO `cpggxhxx` VALUES ('482', 'Y3.5E2-N');
INSERT INTO `cpggxhxx` VALUES ('483', 'Y4.0E2-N');
INSERT INTO `cpggxhxx` VALUES ('484', 'Y1.0E3-N');
INSERT INTO `cpggxhxx` VALUES ('485', 'Y1.6E3-N');
INSERT INTO `cpggxhxx` VALUES ('486', 'Y1.75E3-N');
INSERT INTO `cpggxhxx` VALUES ('487', 'Y2.0E3-N');
INSERT INTO `cpggxhxx` VALUES ('488', 'Y2.5E3-N');
INSERT INTO `cpggxhxx` VALUES ('489', 'Y3.0E3-N');
INSERT INTO `cpggxhxx` VALUES ('490', 'Y4.0E3-N');
INSERT INTO `cpggxhxx` VALUES ('491', 'Y1.0EF2-N');
INSERT INTO `cpggxhxx` VALUES ('492', 'Y3.0EF2-N');
INSERT INTO `cpggxhxx` VALUES ('493', 'Y1.0EF3-N');
INSERT INTO `cpggxhxx` VALUES ('494', 'Y1.6EF3-N');
INSERT INTO `cpggxhxx` VALUES ('495', 'Y0.5F1-N');
INSERT INTO `cpggxhxx` VALUES ('496', 'Y1.0F1-N');
INSERT INTO `cpggxhxx` VALUES ('497', 'Y1.6F1-N');
INSERT INTO `cpggxhxx` VALUES ('498', 'Y1.75F1-N');
INSERT INTO `cpggxhxx` VALUES ('499', 'Y2.0F1-N');
INSERT INTO `cpggxhxx` VALUES ('500', 'Y2.5F1-N');
INSERT INTO `cpggxhxx` VALUES ('501', 'Y3.0F1-N');
INSERT INTO `cpggxhxx` VALUES ('502', 'Y4.0F1-N');
INSERT INTO `cpggxhxx` VALUES ('503', 'Y1.0F2-N');
INSERT INTO `cpggxhxx` VALUES ('504', 'Y1.6F2-N');
INSERT INTO `cpggxhxx` VALUES ('505', 'Y2.0F2-N');
INSERT INTO `cpggxhxx` VALUES ('506', 'Y3.0F2-N');
INSERT INTO `cpggxhxx` VALUES ('507', 'Y4.0F2-N');
INSERT INTO `cpggxhxx` VALUES ('508', 'Y2.5F2-N');
INSERT INTO `cpggxhxx` VALUES ('509', 'Y0.5F3-N');
INSERT INTO `cpggxhxx` VALUES ('510', 'Y1.0F3-N');
INSERT INTO `cpggxhxx` VALUES ('511', 'Y1.6F3-N');
INSERT INTO `cpggxhxx` VALUES ('512', 'Y1.75F3-N');
INSERT INTO `cpggxhxx` VALUES ('513', 'Y2.0F3-N');
INSERT INTO `cpggxhxx` VALUES ('514', 'Y3.0F3-N');
INSERT INTO `cpggxhxx` VALUES ('515', 'Y4.0F3-N');
INSERT INTO `cpggxhxx` VALUES ('516', 'Y1.5G3-N');
INSERT INTO `cpggxhxx` VALUES ('517', 'DZE-14EAS');
INSERT INTO `cpggxhxx` VALUES ('518', 'DZE-14EB2S');
INSERT INTO `cpggxhxx` VALUES ('519', 'DZE-16E3B2');
INSERT INTO `cpggxhxx` VALUES ('520', 'TC1.75C-H');
INSERT INTO `cpggxhxx` VALUES ('521', 'TC1.75E-H');
INSERT INTO `cpggxhxx` VALUES ('522', 'TC1.75D-H');
INSERT INTO `cpggxhxx` VALUES ('523', 'TC2.0C-H');
INSERT INTO `cpggxhxx` VALUES ('524', '曳引轮');
INSERT INTO `cpggxhxx` VALUES ('525', 'TC2.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('526', 'TC1.5E-H');
INSERT INTO `cpggxhxx` VALUES ('527', 'TC1.0DL-H');
INSERT INTO `cpggxhxx` VALUES ('528', 'DZE-14EA');
INSERT INTO `cpggxhxx` VALUES ('529', 'S转子组件D/CLZ');
INSERT INTO `cpggxhxx` VALUES ('530', 'Y1.75C2-H');
INSERT INTO `cpggxhxx` VALUES ('531', '方型制动器（左）');
INSERT INTO `cpggxhxx` VALUES ('532', 'DZE-14EB2');
INSERT INTO `cpggxhxx` VALUES ('533', 'Y1.0CS-H');
INSERT INTO `cpggxhxx` VALUES ('534', 'DZE-16E3B2A');
INSERT INTO `cpggxhxx` VALUES ('535', 'TC2.0E-H');
INSERT INTO `ddztb` VALUES ('1', '');
INSERT INTO `ddztb` VALUES ('2', '销售录入中');
INSERT INTO `ddztb` VALUES ('3', '销售审核中');
INSERT INTO `ddztb` VALUES ('4', '销售已审核/待计划排产');
INSERT INTO `ddztb` VALUES ('5', '销售审核未通过');
INSERT INTO `ddztb` VALUES ('6', '计划排产中');
INSERT INTO `ddztb` VALUES ('7', '计划排产审核中');
INSERT INTO `ddztb` VALUES ('8', '计划排产已审核');
INSERT INTO `ddztb` VALUES ('9', '计划排产审核未通过');
INSERT INTO `ddztb` VALUES ('10', '生产中');
INSERT INTO `ddztb` VALUES ('11', '生产完成');
INSERT INTO `htxx` VALUES ('7886', '711040', '533', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米配', '', '132', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7887', '803013-803014', '533', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米配', '', '133', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7888', '711117', '533', '196', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米配', '', '134', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7889', '801070-801073', '533', '161', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7890', '803015', '533', '168', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '133', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7891', '803030-803031', '533', '224', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米配', '', '133', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7892', '2014-213A-J', '97', '168', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '136', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7893', 'YN150317A', '510', '518', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装，上出线', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7894', 'YN150316A', '557', '126', '0', '9', 'W', '5', '122', 'N', '5', '2', '7米', '4米', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7895', 'PO01503170008.2', '512', '171', '0', '2', 'W', '2', '117', 'N', '2', '2', '7米', '', '137', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7896', 'YS150313C', '528', '129', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'XAK20150206-1-3', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7897', '91038', '533', '176', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '139', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7898', '711116', '533', '159', '0', '2', 'W', '2', '123', 'N', '6', '2', '7米配', '', '133', 'D型 ', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7899', '91034', '533', '196', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米配', '', '139', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7900', '91036-91037', '533', '177', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '140', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7901', 'YS150317A', '518', '197', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '13833600b    L2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7902', 'YE150317E', '560', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '141', 'D型 沃克斯包装箱  工号：V15N1265(WKS20150317055)', '2015-01-01', '', '5', '18', '10', '', '3', 'V15N1265(WKS', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7903', 'YE150317H', '560', '171', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '141', 'D型 沃克斯包装箱  工号：V14N6564(WKS20150317038)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N6564(WKS', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7904', 'YE150317J', '560', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '141', 'D型 沃克斯包装箱   工号：V14N6565(WKS20150317038)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N6565(WKS', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7905', 'YE150317K', '560', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '141', 'D型 沃克斯包装箱   工号：V14N8813-8816(WKS20150317069)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N8813-8816', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7906', 'YE150316E', '560', '124', '0', '9', 'W', '5', '122', 'Y', '6', '2', '9米', '', '135', 'D型 沃克斯包装箱  工号：V14NB446-449，460-463(WKS20150316001)', '2015-01-01', '', '5', '18', '2', '', '3', 'V14NB446-449', '2', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7907', 'YE150316D', '574', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：D060056.3-4/P-201503699', '2015-01-01', '', '5', '18', '10', '', '3', 'D060056.3-4/P-', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7908', 'YN150316B', '510', '517', '0', '1', 'W', '2', '1', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7909', 'YE150316C', '508', '169', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '20150307', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7910', 'YN150316C', '510', '524', '0', '1', 'W', '1', '44', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7911', 'YN150316D', '510', '519', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7912', 'YE150316L', '560', '171', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '143', 'D型 沃克斯包装箱  工号：V14NB464-483(WKS20150316019)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NB464-483(', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7913', 'YE150316A', '501', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '144', 'D型 出口包装', '2015-01-01', '', '5', '18', '10', '', '5', 'D000523K', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7914', 'YE150316B', '501', '223', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '144', 'D型 出口包装', '2015-01-01', '', '5', '18', '1', '', '5', 'D000524K', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7915', 'YE150312L', '583', '375', '0', '6', 'W', '2', '134', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7916', 'YE150316K', '574', '215', '0', '10', 'W', '2', '127', 'Y', '6', '2', '8米', '', '145', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E020018/P150314604', '2015-01-01', '', '5', '18', '22', '', '3', 'E020018/P1503', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7917', 'YE150316J', '574', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：D120108.1/P150314603', '2015-01-01', '', '5', '18', '10', '', '3', 'D120108.1/P15', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7918', 'YE150316H', '574', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：D120108.2/P150314602', '2015-01-01', '', '5', '18', '10', '', '3', 'D120108.2/P15', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7919', 'YE150316G', '574', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '146', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E010036/P150314601', '2015-01-01', '', '5', '18', '10', '', '3', 'E010036/P1503', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7920', 'YE150316F', '574', '168', '0', '2', 'W', '2', '122', 'Y', '32', '2', '8米', '', '143', 'D型，要原点值   工号：E010023/P150314526', '2015-01-01', '', '5', '18', '10', '', '2', 'E010023/P1503', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7921', 'YE150316M', '560', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '141', 'D型 沃克斯包装箱   工号：V14N0959-0960(WKS20150316049)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N0959-0960', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7922', 'YE150316N', '560', '178', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱   工号：V14N1957-1962(WKS20150316072)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N1957-1962', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7923', 'YE150316R', '560', '74', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '147', 'D型 沃克斯包装箱 合格证按1050kg开   工号：V14N4939-4942(WKS20150316060)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N4939-4942', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7924', 'YE150316S', '560', '74', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '141', 'D型 沃克斯包装箱  工号：V14N0961-0962，0951-0952(WKS20150316036)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N0961-0962', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7925', 'YE150316U', '560', '74', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱  工号：V14N8211-8212(WKS20150316081)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N8211-8212', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7926', 'GY-15-03', '573', '365', '0', '8', 'W', '5', '6', 'Y', '6', '2', '7米', '', '144', 'D型', '2015-01-01', '', '5', '18', '24', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7927', 'JYN150312A', '2', '171', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '148', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7928', 'JYN150312A', '2', '168', '0', '2', 'W', '3', '122', 'N', '5', '2', '10米', '', '149', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7929', 'JYN150312A', '2', '169', '0', '2', 'W', '3', '122', 'N', '5', '2', '10米', '', '149', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7930', 'JYN150312A', '2', '174', '0', '2', 'W', '3', '122', 'N', '5', '2', '10米', '', '149', 'D型，β=95γ=55', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7931', 'YE150316V', '560', '74', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱   工号：V15N1603-1604(WKS20150316102)', '2015-01-01', '', '5', '18', '10', '', '3', 'V15N1603-1604', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7932', 'YE150316W', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '146', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E010019.11-15/P-201503757', '2015-01-01', '', '5', '18', '10', '', '3', 'E010019.11-15/', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7933', 'YE150316X', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '146', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E010019.16-18/P-201503757', '2015-01-01', '', '5', '18', '10', '', '3', 'E010019.16-18/', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7934', 'YE150316Y', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '146', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E010019.1-3/P-201503756', '2015-01-01', '', '5', '18', '10', '', '3', 'E010019.1-3/P-', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7935', 'YE150316Z', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '146', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光   工号：E010019.4-10/P-201503756', '2015-01-01', '', '5', '18', '10', '', '3', 'E010019.4-10/P', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7936', 'YE150316Aa', '560', '171', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '143', 'D型 沃克斯包装箱  工号：V14NB458-459(WKS20150316122)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NB458-459(', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7937', '14-33165A4', '579', '106', '0', '9', 'W', '5', '123', 'N', '1', '2', '7米', '5米', '150', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', '14-33165A4', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7938', '14-33165A1', '579', '106', '0', '9', 'W', '5', '123', 'N', '1', '2', '7米', '5米', '150', 'D型', '2015-01-01', '', '6', '18', '3', '', '2', '14-33165A4', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7939', '14-33165A3', '579', '106', '0', '9', 'W', '5', '123', 'N', '1', '2', '7米', '5米', '150', 'D型', '2015-01-01', '', '6', '18', '3', '', '2', '14-33165A4', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7940', '14-33165A2', '579', '106', '0', '9', 'W', '5', '123', 'N', '1', '2', '7米', '5米', '150', 'D型', '2015-01-01', '', '6', '18', '3', '', '2', '14-33165A4', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7941', 'YE150313L', '574', '168', '0', '2', 'W', '2', '122', 'Y', '37', '2', '8米', '', '143', '要原点值  工号：E010024/P-201503597', '2015-01-01', '', '5', '18', '10', '', '2', 'E010024/P-201', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7942', 'YN15031', '582', '528', '0', '1', 'W', '2', '1', 'N', '1', '1', '', '', '1', '木箱包装，出厂编号：1420005/2007BCC', '2015-01-01', '', '5', '18', '1', '', '2', '', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7943', 'YE150313B', '421', '229', '0', '10', 'W', '2', '124', 'Y', '4', '2', '7米', '', '151', '', '2015-01-01', '', '5', '18', '25', '', '2', 'TEC15-013', '2', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7944', 'YE150313M', '560', '171', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '143', 'D型 沃克斯包装箱  工号：V14NB450-457(WKS20150313062)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NB450-457(', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7945', 'YS150313B', '552', '534', '0', '1', 'W', '2', '1', 'N', '1', '1', '', '', '1', '木箱包装，载重1350KG，上出线 广日主机', '2015-01-01', '', '5', '8', '1', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7946', 'YS150312A', '523', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '502074', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7947', '90060-90062', '533', '196', '0', '2', 'W', '2', '126', 'Y', '4', '2', '7米配', '', '139', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7948', '802004', '533', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '133', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '3', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7949', 'YM150312J', '580', '159', '0', '2', 'W', '2', '123', 'Y', '5', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '6', '14', '13', '', '2', '', '4', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7950', 'YM150312L', '580', '175', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '6', '14', '10', '', '2', '', '4', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7951', 'YM150312K', '580', '168', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '6', '14', '10', '', '2', '', '4', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7952', 'YE150312M', '565', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '201503061', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7953', 'YE150313C', '509', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A15-K-0219', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7954', 'YE2015-00720', '341', '168', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '152', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-00720', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7955', 'YE150313D', '560', '168', '0', '2', 'W', '2', '123', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱 工号：V14NC031-043(WKS20150313020)', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NC031-043(', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7956', 'YE150313E', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '153', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光  工号：D120069/P150313509', '2015-01-01', '', '5', '18', '10', '', '3', 'D120069/P1503', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7957', '711120-711122', '533', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '139', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '3', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7958', 'YS150313E', '581', '126', '0', '9', 'W', '2', '122', 'N', '6', '2', '7米', '6米', '135', 'D型 ', '2015-01-01', '', '5', '18', '3', '', '2', '', '2', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7959', 'YN150312C', '96', '524', '0', '1', 'W', '1', '123', 'N', '1', '1', '', '', '1', 'WYT-S-3D，2.2版，木箱包装，出厂编码06L0624', '2015-01-01', '', '5', '18', '1', '', '2', '', '2', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7960', 'YE150313F', '560', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱 工号：V15N0300-0303(WKS20150313048)', '2015-01-01', '', '5', '18', '10', '', '3', 'V15N0300-0303', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7961', 'PO01503130097.5', '512', '222', '0', '10', 'W', '2', '115', 'Y', '2', '2', '7米', '', '154', 'D型，提供原点值，V型带切口:100°、50°', '2015-01-01', '', '5', '8', '22', '', '2', '', '2', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7962', 'YE150313G', '574', '159', '0', '2', 'W', '2', '123', 'Y', '37', '2', '8米', '', '144', '要原点值，出口免熏蒸包装  工号：E02P218/P-201503600', '2015-01-01', '', '5', '18', '13', '', '42', 'E02P218/P-201', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7963', 'YE150313H', '574', '152', '0', '2', 'W', '2', '123', 'Y', '37', '2', '8米', '', '144', '要原点值，出口免熏蒸包装  工号：E02P219/P-201503600', '2015-01-01', '', '5', '18', '13', '', '42', 'E02P219/P-201', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7964', 'YE150313J', '574', '152', '0', '2', 'W', '2', '123', 'Y', '37', '2', '8米', '', '144', '要原点值，出口免熏蒸包装  工号：E02P220/P-201503600', '2015-01-01', '', '5', '18', '13', '', '42', 'E02P220/P-201', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7965', 'YE150313K', '574', '152', '0', '2', 'W', '2', '123', 'Y', '37', '2', '8米', '', '144', '要原点值，出口免熏蒸包装  工号：E02P221/P-201503600', '2015-01-01', '', '5', '18', '13', '', '42', 'E02P221/P-201', '4', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7966', 'PO01503130097.4', '512', '535', '0', '1', 'W', '2', '59', 'Y', '2', '2', '7米', '', '155', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '11', '', '2', '', '3', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7967', 'YE150312J', '574', '178', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '143', 'D型，要原点值  工号：D080022.5-8/P-201503552', '2015-01-01', '', '5', '18', '10', '', '2', 'D080022.5-8/P-', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7968', 'YE150312K', '574', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '143', 'D型，要原点值  工号：D080022.13-20/P-201503552', '2015-01-01', '', '5', '18', '10', '', '2', 'D080022.13-20/', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7969', 'XDL153913-153914', '551', '146', '0', '9', 'W', '5', '16', 'N', '37', '2', '10米配', '5米', '156', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7970', 'XDL153911-153912', '551', '175', '0', '2', 'W', '2', '122', 'Y', '37', '2', '10米配', '', '157', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7971', 'YS150309F', '504', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '158', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1503003', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7972', 'YS150310F', '504', '176', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '159', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1503011', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7973', 'YE150310B', '565', '168', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '201503061', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7974', 'YN150310A', '569', '120', '0', '9', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7975', 'YE150311H', '560', '168', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '141', 'D型， 沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NA150(WKS20150310163)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7976', 'PO01503100019.3', '512', '521', '0', '1', 'W', '2', '59', 'Y', '2', '2', '7米', '', '160', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7977', 'YE150310F', '441', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'LD15B3740', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7978', 'YE150311J', '574', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '10', '', '3', 'E010059/P150311444', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7979', 'YE150310A', '574', '195', '0', '2', 'W', '2', '126', 'N', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '11', '', '3', 'D090106.1-2/P-201503421', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7980', 'YE150311K', '574', '222', '0', '10', 'W', '2', '127', 'N', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '22', '', '3', 'E020029/P150310405', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7981', 'CQT201502-6', '576', '126', '0', '9', 'W', '5', '122', 'N', '6', '2', '10米', '8米', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '3', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7982', 'YS150309H', '547', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7983', 'YM150309D', '566', '131', '0', '9', 'W', '5', '122', 'Y', '5', '2', '10米', '', '135', 'D型，减震12块（赠)', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7984', 'YS150309E', '522', '97', '0', '2', 'W', '2', '128', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '26', '', '2', 'K201501010', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7985', 'YE150209F', '574', '194', '0', '2', 'W', '2', '126', 'N', '4', '2', '8米', '', '144', 'D型，要原点值，出口免熏蒸包装', '2015-01-01', '', '5', '18', '11', '', '42', 'D04CB091R.3-5/P-201502075', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7986', 'YE2015-00540-00545', '341', '177', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '161', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-00540-00545', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7987', 'XDL153908', '551', '174', '0', '2', 'W', '2', '122', 'Y', '37', '2', '10米配', '', '162', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7988', 'XDL153888', '551', '170', '0', '2', 'W', '2', '122', 'Y', '37', '2', '10米配', '', '163', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7989', 'XDL153885', '551', '176', '0', '2', 'W', '2', '122', 'Y', '37', '2', '10米配', '', '163', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7990', 'YN150309B', '510', '518', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装，上出线', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7991', '200051850-00087683', '503', '279', '0', '21', 'W', '2', '69', 'Y', '25', '2', '10米', '', '144', 'V型槽，β=103，γ=50，全英文资料，WYT-Y1C-FHZ.5防护罩， 左置，包角>145度，NSK轴承', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7992', 'SSEC20151095(2015020135)', '492', '197', '0', '2', 'W', '2', '126', 'Y', '5', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '11', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7993', 'YM150306B', '448', '178', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7994', 'YM150309B', '563', '119', '0', '9', 'W', '2', '122', 'N', '2', '2', '8米', '7米', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7995', 'YS150309A', '519', '222', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'K201503003', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7996', 'YS150309G', '520', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'K150304-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7997', 'YM150304B', '359', '532', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7998', 'YE150306C', '560', '162', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '141', 'D型 ,沃克斯包装箱', '2015-01-01', '', '5', '18', '13', '', '3', 'V14N9408-9415(WKS20141127507)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('7999', 'YE150309C', '560', '222', '0', '10', 'W', '2', '127', 'Y', '2', '2', '9米', '', '141', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '22', '', '3', 'V14NB658(WKS20150309001)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8000', '预投', '568', '215', '0', '10', 'W', '2', '127', 'Y', '6', '2', '9米', '', '135', 'D型,歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '22', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8001', '预投', '568', '229', '0', '10', 'W', '2', '124', 'Y', '6', '2', '9米', '', '135', 'D型,歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '25', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8002', 'YM150302Q', '570', '215', '0', '10', 'W', '2', '124', 'Y', '2', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'HNW2015K0009', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8003', 'YM150306A', '497', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米配', '', '135', 'D型，减震1套（赠）', '2015-01-01', '', '5', '18', '10', '', '2', 'XDL15K0718 永嘉县乌牛锦泰华商宾馆', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8004', 'YM150306C', '497', '180', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米配', '', '135', 'D型，减震1套（赠）', '2015-01-01', '', '5', '18', '11', '', '2', 'XDL15K0628李志坚', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8005', 'SYLG150309A', '571', '222', '0', '10', 'W', '2', '124', 'Y', '4', '2', '10米', '', '165', '减震垫8块（赠），U出口包装箱（2层），预先接上编码器电缆', '2015-01-01', '', '5', '18', '22', '', '6', '', '1', '12', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8006', 'PO01503090096.1', '512', '447', '0', '22', 'W', '2', '60', 'Y', '7', '3', '7米', '', '166', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8007', 'SYLG150309B', '571', '218', '0', '10', 'W', '2', '124', 'Y', '4', '2', '10米', '', '165', '减震垫4块（赠），U出口包装箱（2层），预先接上编码器电缆', '2015-01-01', '', '5', '18', '22', '', '6', '', '1', '12', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8008', 'YS150305E', '531', '177', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '167', 'D型，广日豆绿色 β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', 'P001020150305', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8009', 'YS150306C', '544', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '安陆凤凰', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8010', 'YE150305F', '501', '215', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '168', 'D型, U型出口包装', '2015-01-01', '', '5', '18', '22', '', '5', 'D000527K', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8011', 'YS150305D', '520', '176', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'K150305-2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8012', 'GLR201503060001（G15NK027-028）', '568', '222', '0', '10', 'W', '2', '127', 'Y', '6', '2', '9米', '', '135', 'D型,歌拉瑞包装；壁挂器无厂址', '2015-01-01', '', '5', '20', '22', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8013', 'XDL153876-153881', '551', '129', '0', '9', 'W', '5', '122', 'Y', '37', '2', '10米配', '', '169', '', '2015-01-01', '', '5', '14', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8014', 'SSEC03190(2014061118-1120)', '492', '142', '0', '9', 'W', '5', '46', 'Y', '2', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '2', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8015', 'PO01503030009.4', '512', '180', '0', '2', 'W', '2', '105', 'N', '2', '2', '7米', '', '170', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8016', 'YE2015-D00001', '500', '174', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '171', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-D00001', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8017', 'YE150303D', '501', '112', '0', '9', 'W', '2', '123', 'N', '6', '2', '7米', '7米', '144', 'D型，S出口包装', '2015-01-01', '', '5', '18', '3', '', '5', 'D000525E', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8018', 'YE150303E', '501', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '144', 'D型，TA出口包装', '2015-01-01', '', '5', '18', '13', '', '5', 'D000526E', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8019', 'YM150303B', '561', '181', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '172', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8020', 'YS150304D', '520', '152', '0', '2', 'W', '2', '123', 'Y', '2', '2', '7米', '', '173', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'K150227-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8021', 'YS150305B', '520', '159', '0', '2', 'W', '2', '123', 'Y', '2', '2', '7米', '', '174', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'K150303-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8022', 'YS150304E', '520', '222', '0', '10', 'W', '2', '127', 'Y', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'K150126-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8023', 'YE150305B', '560', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型 沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N7641-7642，7645-7650(WKS20150305035)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8024', 'PO01503050016.5', '512', '215', '0', '10', 'W', '2', '115', 'Y', '2', '2', '7米', '', '175', 'D型，提供原点值，V型带切口:100°、50°', '2015-01-01', '', '5', '8', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8025', 'PO01503050016.6', '512', '222', '0', '10', 'W', '2', '115', 'Y', '2', '2', '7米', '', '154', 'D型，提供原点值，V型带切口:100°、50°', '2015-01-01', '', '5', '8', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8026', 'PO01503050016.7', '512', '218', '0', '10', 'W', '2', '115', 'Y', '2', '2', '7米', '', '176', 'D型，提供原点值，V型带切口:100°、50°', '2015-01-01', '', '5', '8', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8027', 'PO01503050016.8', '512', '442', '0', '22', 'W', '2', '4', 'Y', '7', '3', '7米', '', '177', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8028', 'YS150304F', '531', '159', '0', '2', 'W', '2', '129', 'Y', '2', '2', '7米', '', '178', 'D型，广日豆绿色 β105 γ40 ', '2015-01-01', '', '5', '8', '13', '', '2', 'P000920150304', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8029', 'YE150304L', '574', '160', '0', '2', 'W', '2', '123', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '13', '', '3', 'D120017/P-201503244', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8030', 'YS150304A', '545', '130', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'FJS1412-120东岭逸景花园L9/L11', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8031', '(SSEC)2015030157-0168', '492', '530', '0', '8', 'W', '5', '5', 'Y', '4', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '24', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8032', 'YM150304C', '359', '183', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '11', '', '2', '11500504', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8033', 'YM150302P', '359', '222', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '180', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '22', '', '2', '11500508', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8034', 'YS150303C', '527', '112', '0', '9', 'W', '2', '123', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', '15037#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8035', '801096-801097', '533', '224', '0', '10', 'W', '2', '124', 'Y', '4', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8036', '15-1525', '263', '176', '0', '2', 'W', '2', '122', 'Y', '10', '2', '10米', '', '135', '', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8037', 'YM150304A', '543', '131', '0', '9', 'W', '2', '7', 'Y', '2', '2', '8米', '', '181', 'D型', '2015-01-01', '', '5', '14', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8038', 'YM150302C', '543', '225', '0', '10', 'W', '2', '124', 'Y', '2', '2', '8米', '', '182', 'D型', '2015-01-01', '', '5', '14', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8039', 'YE2015-02057', '341', '169', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '152', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-02057', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8040', 'YE150302Ma', '550', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A15-D-0026ABCDEF', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8041', 'YE150302Ja', '509', '215', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'A15-K-0199', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8042', 'YS150302A', '511', '171', '0', '2', 'W', '2', '122', 'Y', '37', '2', '7米', '', '135', '', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8043', 'YE150302Ga', '502', '168', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '183', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'K2029', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8044', 'YS150302G', '515', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8045', 'YS150302F', '515', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8046', 'PO01503020052.5', '512', '183', '0', '2', 'W', '2', '59', 'Y', '2', '2', '7米', '', '184', 'D型，提供原点值，β105 γ40  ', '2015-01-01', '', '5', '8', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8047', 'YM150302N', '563', '120', '0', '9', 'W', '2', '122', 'N', '6', '2', '8米', '4米', '135', 'D型，减震5套（赠，减震组合螺栓型号为：M16*40）,左置', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8048', 'YS150302D', '504', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '159', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1412122', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8049', 'YM150302E', '563', '143', '0', '9', 'W', '2', '98', 'Y', '6', '2', '8米', '', '135', 'D型，减震4套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8050', 'YM150302G', '563', '159', '0', '2', 'W', '2', '123', 'Y', '2', '2', '8米', '', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8051', 'YM150302I', '563', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8052', 'YM150302D', '563', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型，减震6套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8053', 'YM150302F', '563', '215', '0', '10', 'W', '2', '36', 'Y', '6', '2', '8米', '', '185', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8054', 'YE150302Hb', '565', '159', '0', '2', 'W', '2', '123', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '201502038', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8055', 'YE150302Hd', '565', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '201502040', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8056', 'YS150302K', '522', '169', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '186', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8057', 'YS150302J', '523', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型，主机电压AC220V', '2015-01-01', '', '4', '18', '10', '', '2', '503008', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8058', 'YE150303G', '560', '131', '0', '9', 'W', '5', '122', 'Y', '2', '2', '9米', '', '143', 'D型 ,沃克斯包装箱', '2015-01-01', '', '5', '18', '2', '', '3', 'V14N7297，7301，7305(WKS20150303041)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8059', 'PO01502130029.8', '512', '469', '0', '22', 'W', '2', '4', 'Y', '7', '3', '7米', '', '187', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8060', '15Z0332', '530', '174', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '188', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8061', '15Z0360-363', '530', '192', '0', '2', 'W', '2', '126', 'Y', '4', '2', '', '', '189', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8062', 'FJ14-10-411-416', '577', '225', '0', '10', 'W', '3', '124', 'Y', '6', '2', '10米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8063', 'YE2015-02181出口', '341', '152', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米', '', '190', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '2015-02181出口', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8064', 'YE2015-02156-02157', '341', '222', '0', '10', 'W', '2', '124', 'Y', '4', '2', '7米', '', '161', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '2015-02156-02157', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8065', 'YE150302Mb', '550', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A15-K-0025ABCDEF', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8066', 'YE150302B', '574', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '10', '', '3', 'E010046.3-4/P-201503015', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8067', 'YE150302Eg', '574', '183', '0', '2', 'W', '2', '7', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '11', '', '3', 'E010046.57/P-201503068', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8068', 'YE150302En', '574', '183', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '11', '', '3', 'E010046.63-67/P-201503068', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8069', 'YM150302J', '554', '177', '0', '2', 'W', '3', '122', 'Y', '11', '2', '8米', '', '135', '', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8070', '4500806986', '506', '229', '0', '10', 'W', '2', '49', 'N', '2', '2', '10米', '', '191', 'D型,提供原点值，贴上下行标签', '2015-01-01', '', '5', '15', '25', '', '2', '10027130/230,260,280', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8071', 'GLR201502130008（G15NL026）', '568', '183', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '192', 'D型 ,歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '11', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8072', 'YE2015-02057', '341', '168', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '152', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-02057（5-5）', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8073', 'YM150211A', '555', '222', '0', '10', 'W', '3', '36', 'Y', '37', '2', '8米配', '', '144', '', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8074', 'YM150210F', '556', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8075', 'YE150211B', '501', '130', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'D000518-521', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8076', 'YE150212A', '560', '219', '0', '10', 'W', '2', '127', 'Y', '6', '2', '9米', '', '141', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '22', '', '3', 'V14NB643-646(WKS20150212038)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8077', 'GLR201502120002(115LSP011-012)', '568', '160', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '144', 'D型壁挂器无厂址', '2015-01-01', '', '5', '19', '13', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8078', 'GLR201502120023（115LSPM005）', '568', '181', '0', '2', 'W', '2', '122', 'N', '6', '2', '9米', '', '144', 'D型壁挂器无厂址', '2015-01-01', '', '5', '19', '11', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8079', 'GLR201502110022（G15NK022-025）', '568', '177', '0', '2', 'W', '2', '122', 'Y', '5', '2', '9米', '', '193', 'D型，歌拉瑞包装，所有随机资料，主机及部件铭牌全部为英文，不允许有任何中文及拼音    壁挂器无厂址', '2015-01-01', '', '5', '19', '10', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8080', 'SYLG150210D', '571', '531', '0', '1', 'W', '2', '133', 'N', '1', '1', '', '', '144', '出口包装箱,用在TA1.0D主机上', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '12', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8081', 'SSEC2015837(2015010100)', '492', '120', '0', '9', 'W', '5', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '2', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8082', 'SSEC2015815(2015010099)', '492', '127', '0', '9', 'W', '5', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '2', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8083', 'YS150210A', '516', '171', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A.2015.02.005', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8084', 'XDL153844', '551', '223', '0', '10', 'W', '2', '63', 'Y', '37', '2', '10米配', '', '195', '', '2015-01-01', '', '5', '14', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8085', 'YM150209E', '555', '130', '0', '9', 'W', '5', '7', 'Y', '37', '2', '8米配', '', '135', '', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8086', 'YM150209I', '555', '159', '0', '2', 'W', '3', '123', 'Y', '37', '2', '8米配', '', '135', '', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8087', 'YM150209G', '564', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8088', 'YM150210A', '359', '173', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD ,奥立达包装箱', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8089', 'YM150209D', '359', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '21500006', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8090', 'YM150209C', '359', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2150009-21500010', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8091', 'GLR201502090011（G15NA008）', '568', '168', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '192', 'D型，歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '10', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8092', '预投YS150210E', '512', '178', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '196', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8093', '预投YS150210A', '512', '522', '0', '1', 'W', '2', '125', 'Y', '2', '2', '7米', '', '197', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8094', '预投YS150210C', '512', '523', '0', '1', 'W', '2', '125', 'Y', '2', '2', '7米', '', '198', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8095', 'SYLG150210A', '571', '101', '0', '2', 'W', '2', '132', 'Y', '4', '2', '10米', '', '199', '出口包装箱（2层），减震垫20块（赠,WYT-TAM-5），机座外型特殊，韩国富士用图纸,另每台带4个M16*45螺栓,预先接上编码器电缆', '2015-01-01', '', '5', '18', '26', '', '6', '', '1', '12', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8096', 'PO01502070011.3', '512', '524', '0', '1', 'W', '1', '4', 'N', '1', '1', '', '', '1', 'WYT-Y2D-3G,木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8097', 'YE150209F', '574', '194', '0', '2', 'W', '2', '126', 'N', '4', '2', '8米', '', '200', 'D型，要原点值，出口免熏蒸包装', '2015-01-01', '', '5', '18', '11', '', '42', 'D04CB091R.3-5/P-201502075', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8098', 'YE150209E', '574', '229', '0', '10', 'W', '2', '127', 'N', '4', '2', '8米', '', '200', 'D型，要原点值，U出口主机包装箱', '2015-01-01', '', '5', '18', '25', '', '2', 'D04CB091R.1-2/P-201502075', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8099', 'YE2015-02062-02064', '341', '171', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '201', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-02062-02064', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8100', 'YE2015-02059', '341', '229', '0', '10', 'W', '2', '124', 'Y', '4', '2', '7米', '', '152', 'D型', '2015-01-01', '', '5', '18', '25', '', '2', '2015-02059', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8101', 'YN150209A', '510', '517', '0', '1', 'W', '2', '1', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8102', 'SSEC2015723(201510107-0108)', '492', '138', '0', '9', 'W', '5', '53', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '2', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8103', 'SSEC2015656(2015020118)', '492', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8104', '801145', '533', '222', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米配', '', '133', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8105', 'YE150205H', '508', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '202', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '20150204', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8106', 'YE150205G', '502', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '203', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'D2143', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8107', 'YS150203E', '522', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8108', 'YS150205I', '523', '176', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '204', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '502053', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8109', 'YS150205G', '523', '182', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '204', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '502060', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8110', 'YS150205D', '528', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'XAK20150203-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8111', 'YM150205G', '374', '533', '0', '12', 'W', '2', '26', 'Y', '5', '2', '7米', '', '135', 'D型 ,有库存，不用排产', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8112', 'PO01502060033.2', '512', '445', '0', '22', 'W', '2', '4', 'Y', '7', '3', '7米', '', '205', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8113', '15Z0259', '530', '216', '0', '10', 'W', '2', '127', 'Y', '4', '2', '', '', '135', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8114', 'YE150204E', '502', '222', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '206', 'D型 ', '2015-01-01', '', '5', '18', '22', '', '2', 'D2287', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8115', 'YE150205D', '562', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '15-02024#', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8116', 'YS150204A', '519', '218', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '204', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'K201501018', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8117', 'YM150205B', '570', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'HNW2015K0005', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8118', 'GY-15-02', '573', '368', '0', '8', 'W', '5', '6', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '24', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8119', 'YE150205A', '348', '177', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '150205(0235)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8120', 'XDL153789', '551', '222', '0', '10', 'W', '2', '63', 'Y', '37', '2', '10米配', '', '207', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '22', '', '5', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8121', 'YN15-0055', '97', '171', '0', '2', 'W', '3', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8122', 'YN15-0054', '97', '177', '0', '2', 'W', '3', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8123', 'PO01502040011.2', '512', '470', '0', '22', 'W', '2', '4', 'Y', '7', '3', '7米', '', '208', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8124', 'YS150203A', '532', '168', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '135', 'D型β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8125', 'YS150203B', '532', '174', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '135', 'D型β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8126', '4500802846', '498', '143', '0', '9', 'W', '5', '46', 'Y', '2', '2', '10米', '', '191', 'D型，减震12块（赠），康力防护罩，康力包装，带M24*130组合螺栓，提供原点值，贴上下行标签', '2015-01-01', '', '5', '15', '2', '', '2', '152000279/130-150', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8127', 'MJ20150204-01', '540', '169', '0', '2', 'W', '2', '122', 'Y', '5', '2', '6米', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8128', 'MJ20150204-02', '540', '175', '0', '2', 'W', '2', '122', 'Y', '5', '2', '6米', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8129', 'YS150202G', '516', '120', '0', '9', 'W', '5', '122', 'Y', '2', '2', '7米', '', '194', 'D型 ', '2015-01-01', '', '5', '18', '2', '', '2', 'A.2015.01.043', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8130', 'YE150203M', '562', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '销售购买', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8131', 'YS150202H', '522', '173', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'H201501008', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8132', 'YS150202C', '528', '120', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'XAK20150116-9', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8133', 'YS150202A', '528', '122', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'XAK20150116-4-5', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8134', 'YE150203C', '560', '160', '0', '2', 'W', '2', '123', 'Y', '2', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '13', '', '3', 'V13N8144-8146(WKS20150202051)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8135', 'YS150202F', '528', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'XAK20150121-2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8136', 'YE150203B', '572', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'HT15010014(L1)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8137', '15Z0238', '530', '229', '0', '10', 'W', '2', '127', 'Y', '4', '2', '', '', '135', '不带电缆', '2015-01-01', '', '5', '3', '25', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8138', 'YS150202I', '548', '160', '0', '2', 'W', '2', '123', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'A.2015.01.002', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8139', 'YE150202A', '508', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '10', '', '2', '20150119', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8140', 'PO01502020025.1', '512', '159', '0', '2', 'W', '2', '117', 'N', '2', '2', '7米', '', '209', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8141', 'SSEC2015509(2015010086)', '492', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8142', 'YS150129D', '522', '152', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'K201501010', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8143', 'YM150202A', '359', '180', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD ,奥立达包装箱', '2015-01-01', '', '5', '18', '11', '', '2', '11500313', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8144', 'YS150130A', '526', '225', '0', '10', 'W', '2', '124', 'N', '6', '2', '10米', '', '210', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'SGL20150127-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8145', 'YE150202C', '560', '266', '0', '12', 'W', '5', '30', 'Y', '2', '2', '9米', '', '143', 'D型,沃克斯包装箱', '2015-01-01', '', '5', '18', '24', '', '3', 'V14N0978-0979(WKS20150202001)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8146', '82176', '533', '225', '0', '10', 'W', '2', '124', 'Y', '4', '2', '7米配', '', '211', 'D型 ', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8147', 'CQT201502-2-5', '576', '225', '0', '10', 'W', '2', '124', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '3', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8148', 'YM150130A', '561', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '212', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2014-K-00838', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8149', 'YM150130B', '561', '169', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '212', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8150', 'YM150130C', '561', '171', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '213', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8151', 'YS150129B', '523', '161', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '204', 'D型，主机电压AC220V', '2015-01-01', '', '4', '18', '13', '', '2', '503003', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8152', 'YS150128F', '518', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '14833615 L1#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8153', 'YS150128B', '529', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，主机下置，带盘车装置', '2015-01-01', '', '5', '18', '10', '', '2', '15T7730013', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8154', 'GLR201501290005（G15NA001-006）', '568', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '214', 'D型.歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '10', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8155', 'YM150128A', '497', '160', '0', '2', 'W', '2', '123', 'Y', '6', '2', '8米配', '', '135', 'D型，减震1套（赠）', '2015-01-01', '', '5', '18', '13', '', '2', 'XDL15K0388许清江', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8156', 'YM150128D', '497', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米配', '', '135', 'D型，减震1套（赠）', '2015-01-01', '', '5', '18', '10', '', '2', 'XDL15K0398福建省金加工时恒达裕皮革制品有限公司', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8157', 'YE150129F', '572', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'HT14120147（L1-L4）', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8158', 'YE150129J', '574', '225', '0', '10', 'W', '2', '127', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '22', '', '3', 'D020025.3-5/P-2015011038', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8159', 'PO01501240003', '512', '26', '0', '9', 'W', '2', '125', 'Y', '7', '3', '7米', '', '215', '提供原点值', '2015-01-01', '', '5', '8', '3', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8160', 'YS150127C', '516', '175', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A.2015.01.034', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8161', 'YS150126G', '532', '177', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '135', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8162', 'YM150127H', '535', '119', '0', '9', 'W', '5', '122', 'N', '37', '2', '7米', '5米', '135', '', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8163', '14-32098', '579', '200', '0', '2', 'W', '2', '9', 'Y', '1', '2', '7米', '', '150', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8164', 'XDL153760-153763', '551', '130', '0', '9', 'W', '5', '122', 'Y', '37', '2', '10米配', '', '216', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8165', 'YE150126G', '509', '152', '0', '2', 'W', '2', '123', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'A15-K-0179', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8166', '200050630-00087683', '503', '279', '0', '21', 'W', '2', '69', 'Y', '25', '2', '10米', '', '144', 'V型槽，β=103，γ=50，全英文资料，WYT-Y1C-FHZ.5防护罩， 左置，包角>145度，NSK轴承', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8167', 'YS150126I', '504', '127', '0', '9', 'W', '5', '122', 'Y', '2', '2', '7米', '', '159', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '2', '', '2', '1412063', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8168', 'YS150126J', '523', '180', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '502001', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8169', 'YS150127A', '528', '127', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型 ', '2015-01-01', '', '5', '18', '3', '', '2', 'XAK20150116-6-8', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8170', 'YM150127A', '497', '195', '0', '2', 'W', '2', '126', 'Y', '6', '2', '8米配', '', '217', 'D型，减震1套（赠）', '2015-01-01', '', '5', '18', '11', '', '2', 'XDL15K0358温州市程丰金属制品厂', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8171', '2015-302B', '575', '225', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8172', 'YM150127C', '534', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米配', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8173', 'YM150127B', '534', '169', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米配', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8174', 'YM150127D', '534', '171', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米配', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8175', 'YM150126A', '554', '171', '0', '2', 'W', '3', '122', 'Y', '11', '2', '8米', '', '135', '', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8176', 'YM150112B', '556', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型,合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8177', 'YS150316H', '518', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '15833514 L1-L2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8178', 'YM150123A', '559', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '218', 'D型，TA出口包装', '2015-01-01', '', '5', '14', '10', '', '5', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8179', 'YS150126E', '518', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '219', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '15833511    L1#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8180', 'YS150126F', '518', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '220', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '15833514 L1-L2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8181', 'YS150126D', '520', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'K150123-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8182', 'YN15-0036', '569', '162', '0', '2', 'W', '3', '123', 'Y', '5', '2', '10米', '', '221', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8183', 'PO01501230028', '512', '220', '0', '10', 'W', '2', '114', 'Y', '2', '2', '7米', '', '222', 'D型，提供原点值，V型带切口:β100γ50 ', '2015-01-01', '', '5', '8', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8184', 'YS150126B', '531', '522', '0', '1', 'W', '2', '125', 'Y', '2', '2', '7米', '', '167', 'D型，广日豆绿色 β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', 'P000420150123', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8185', '15-1469', '263', '215', '0', '10', 'W', '2', '124', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8186', 'YN150121D', '513', '168', '0', '2', 'W', '2', '123', 'N', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8187', 'YN150123A', '558', '531', '0', '1', 'W', '2', '131', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8188', 'YM150121A', '559', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '223', 'D型，TA出口包装', '2015-01-01', '', '5', '14', '13', '', '5', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8189', '沃克斯型式试验', '560', '234', '0', '10', 'W', '2', '124', 'Y', '37', '2', '7米', '', '141', '用库存机器', '2015-01-01', '', '5', '18', '25', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8190', 'YS150122C', '527', '119', '0', '9', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '3', '', '2', '15002# 15003#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8191', 'YS150122A', '529', '159', '0', '2', 'W', '2', '123', 'Y', '2', '2', '7米', '', '135', 'D型，主机下置，带盘车装置', '2015-01-01', '', '5', '18', '13', '', '2', '15T5920010', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8192', 'YS150122B', '529', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，主机下置，带盘车装置', '2015-01-01', '', '5', '18', '10', '', '2', '15T5920009', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8193', 'YAIJ201501-03', '578', '169', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8194', 'YAIJ201501-01', '578', '175', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8195', '凯斯博型式试验', '543', '367', '0', '8', 'W', '5', '6', 'Y', '37', '2', '7米', '', '224', '已与技术打过招呼，用他们的实验机器', '2015-01-01', '', '5', '18', '24', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8196', 'SSEC03004(2014122609-2610)', '492', '177', '0', '2', 'W', '2', '122', 'Y', '24', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8197', 'YE150122F', '574', '131', '0', '9', 'W', '5', '7', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '2', '', '3', 'D110112.1/P-201501711', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8198', '90011-90012', '533', '215', '0', '10', 'W', '2', '36', 'N', '5', '2', '7米配', '', '133', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8199', 'YM150122A', '541', '143', '0', '9', 'W', '2', '98', 'Y', '5', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '14', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8200', 'YE2015-01085', '341', '176', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '190', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-01085出口', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8201', 'YE150119G', '508', '183', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '20150110', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8202', 'YN141224A', '557', '168', '0', '2', 'W', '3', '122', 'N', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8203', 'YE150120G', '560', '159', '0', '2', 'W', '2', '123', 'Y', '2', '2', '9米', '', '200', 'D型，TA出口包装', '2015-01-01', '', '5', '18', '13', '', '5', 'V15NE0001(WKS20150121030)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8204', 'YS150121A', '528', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'XAK20150108-7', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8205', 'YE150120F', '572', '159', '0', '2', 'W', '2', '123', 'Y', '2', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '13', '', '2', 'HT15010010(L1)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8206', '707113', '533', '198', '0', '2', 'W', '2', '126', 'Y', '6', '2', '8米配', '', '225', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8207', '2015-302A', '575', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '136', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8208', 'YM150121C', '543', '222', '0', '10', 'W', '2', '124', 'Y', '2', '2', '8米', '', '182', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8209', 'SSEC2015139（2015010021-0022）', '492', '137', '0', '9', 'W', '5', '53', 'Y', '2', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '2', '', '3', '2014092156-2157(9#东9#西)', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8210', 'SSEC2015176(2015010025-0026)', '492', '176', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8211', 'YM150119D', '563', '152', '0', '2', 'W', '2', '123', 'Y', '6', '2', '8米', '', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）。', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8212', 'YS150116C', '520', '160', '0', '2', 'W', '2', '123', 'Y', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'K150114-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8213', 'YS150119J', '521', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8214', 'YM150119C', '359', '130', '0', '9', 'W', '5', '122', 'Y', '6', '2', '7米', '', '226', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '2', '', '2', '2015-K-0013/0011/0002/0007/0008/0001/0009/0010/0012/0014', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8215', 'YM150119A', '359', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8216', 'PO01501200080.6', '512', '466', '0', '22', 'W', '2', '4', 'Y', '7', '3', '7米', '', '227', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8217', 'YE150119J', '353', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8218', 'YJN150119B', '507', '532', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8219', 'YE150119M', '348', '168', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '150156(0135)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8220', 'YE150119L', '348', '174', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '150154(0065)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8221', 'YE150119K', '348', '180', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '150155(0045)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8222', '711146', '533', '527', '0', '1', 'W', '2', '126', 'N', '6', '2', '7米配', '', '228', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8223', '707274', '533', '218', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米配', '', '185', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8224', '预投', '506', '144', '0', '9', 'W', '5', '46', 'Y', '2', '2', '10米', '', '191', 'D型，减震88块（赠)，提供原点值。带M24*130组合螺栓提供原点值。贴上下行标签', '2015-01-01', '', '5', '15', '2', '', '2', '10027323-10~220', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8225', 'YE150119P', '550', '168', '0', '2', 'W', '2', '122', 'N', '2', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-Kn-0016', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8226', 'YE150116D', '509', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-K-0099', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8227', 'SSEC201501(2015010013-0014)', '492', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '2014122618-2619', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8228', 'YS150119H', '522', '178', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '229', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'K201501003', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8229', 'YM150113A', '363', '524', '0', '1', 'W', '1', '123', 'N', '1', '1', '', '', '1', 'WYT-S-3D，2.2版，木箱包装，出厂编码07L0852', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8230', 'YE150119B', '574', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '10', '', '3', 'C09043.5-6/P-201501587', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8231', '89352', '533', '176', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米配', '', '230', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8232', 'FJ-70000', '577', '227', '0', '10', 'W', '3', '124', 'Y', '6', '2', '10米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8233', 'YM150116A', '542', '350', '0', '6', 'W', '7', '11', 'Y', '13', '2', '7米', '', '231', '', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8234', 'YE2015-01037-01038', '341', '159', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米', '', '190', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '2015-01037-01038出口', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8235', 'YN150116A', '549', '518', '0', '1', 'W', '5', '1', 'N', '1', '1', '', '', '1', '木箱包装，上出线', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8236', 'PO01501160063.6', '512', '168', '0', '2', 'W', '2', '117', 'N', '2', '2', '7米', '', '232', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8237', 'YM150115I', '561', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8238', 'YE150115B', '565', '222', '0', '10', 'W', '2', '124', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '201501024', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8239', 'YS150114F', '524', '168', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '135', 'D型，β105 γ40 ', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8240', 'YE150116A', '560', '363', '0', '8', 'W', '2', '6', 'Y', '2', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '23', '', '3', 'V14NA998(POORD002166)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8241', 'YE150115H', '560', '364', '0', '8', 'W', '2', '6', 'Y', '2', '2', '9米', '', '233', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '23', '', '3', 'V14NA996-A997(POORD002166)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8242', 'YE150115C', '342', '174', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '10', '', '2', 'NA14-K-15802', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8243', 'YE150115B', '342', '170', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '10', '', '2', 'NA15-K-10301', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8244', 'YS150116B', '544', '171', '0', '2', 'W', '2', '122', 'Y', '2', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '新天地12-144-145', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8245', '200049798-00171154', '503', '370', '0', '17', 'W', '2', '103', 'Y', '31', '2', '10米', '', '234', 'V型槽，β=103，γ=50，全英文资料，防护罩防护罩WYT-Y2D-FHZ.4，右置，包角＞145°NSK轴承,DOVER包装箱', '2015-01-01', '', '5', '18', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8246', 'YS150114J', '511', '19', '0', '9', 'W', '5', '122', 'Y', '4', '3', '7米', '', '135', '', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8247', 'YS150114H', '523', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '502008', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8248', 'YS150115A', '528', '171', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'XAK20150108-6', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8249', 'GLR201501150004（G14NC073）', '568', '228', '0', '10', 'W', '2', '127', 'N', '6', '2', '9米', '', '135', 'D型，歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '25', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8250', 'YM150115C', '374', '168', '0', '2', 'W', '7', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '金典', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8251', 'YM150115B', '374', '174', '0', '2', 'W', '7', '122', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '义乌福奥', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8252', 'YE150115L', '574', '178', '0', '2', 'W', '2', '7', 'Y', '6', '2', '8米', '', '143', 'D型，要原点值  ', '2015-01-01', '', '5', '18', '10', '', '2', 'B04015.21-26/P-201501519', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8253', 'YE2015-01044-01045', '341', '174', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '161', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-01044-01045', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8254', 'YE2015-01033', '341', '175', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '235', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2015-01033出口', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8255', 'YM150114A', '448', '226', '0', '10', 'W', '2', '124', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8256', 'YS150109B', '520', '175', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'K150104-2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8257', 'YE150114D', '565', '223', '0', '10', 'W', '2', '124', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '201501019', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8258', 'YS150113I', '523', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '402270', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8259', 'YS150113H', '528', '129', '0', '9', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '3', '', '2', 'XAK20150108-1-4', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8260', 'YE150114F', '342', '168', '0', '2', 'W', '2', '122', 'Y', '5', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '10', '', '2', 'NA14-K-10302', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8261', '15Z0051-0055', '530', '525', '0', '1', 'W', '2', '34', 'Y', '4', '2', '', '', '236', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8262', '711211', '533', '161', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8263', 'YAIJ201501-14', '578', '222', '0', '10', 'W', '2', '124', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8264', 'XDL153737', '551', '160', '0', '2', 'W', '2', '123', 'Y', '37', '2', '10米配', '', '163', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '13', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8265', 'XDL145596-145597-1', '551', '218', '0', '10', 'W', '2', '36', 'Y', '10', '2', '10米配', '', '237', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '22', '', '3', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8266', 'YE150112M', '502', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'D2203', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8267', 'YS150112A', '522', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'K201412028', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8268', 'YS150112C', '528', '25', '0', '9', 'W', '5', '122', 'Y', '4', '3', '7米', '', '135', '', '2015-01-01', '', '5', '18', '2', '', '2', 'XAK20150109-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8269', 'PO01501100004.2', '512', '524', '0', '1', 'W', '1', '125', 'N', '1', '1', '', '', '1', 'WYT-S-3F1，2.1版本，用于S1.75C，木箱包装', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8270', '15Z0025-31', '530', '143', '0', '13', 'W', '5', '98', 'Y', '4', '2', '', '', '238', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8271', 'YE150112R', '574', '152', '0', '2', 'W', '2', '123', 'Y', '4', '2', '8米', '', '239', 'D型，要原点值，出口免熏蒸包装  BG04鲜绿色', '2015-01-01', '', '5', '17', '13', '', '42', 'SEEIB2015919/P-201501386', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8272', '4500666185', '506', '524', '0', '1', 'W', '1', '110', 'N', '1', '1', '', '', '1', 'WYT-Y2D-3F(T)木箱包装，出厂编号1276204EWW ', '2015-01-01', '', '5', '18', '1', '', '2', '55024122/20', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8273', 'YM150109E', '556', '178', '0', '2', 'W', '2', '122', 'N', '2', '2', '7米', '', '144', 'D型.合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8274', 'YM150106E', '448', '180', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '240', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8275', 'YM150108A', '370', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型，要原点值', '2015-01-01', '', '5', '18', '10', '', '2', 'F40037T01-T04澄碧花园第一批', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8276', 'YE150109K', '574', '232', '0', '10', 'W', '2', '127', 'Y', '4', '2', '8米', '', '200', 'D型，要原点值，U出口主机包装箱', '2015-01-01', '', '5', '18', '25', '', '2', 'D11CB113.1-2/P-201501294', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8277', 'CQT201501-24-25', '576', '222', '0', '10', 'W', '2', '124', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '3', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8278', 'YS150108B', '548', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8279', 'XDL153672', '551', '119', '0', '9', 'W', '5', '122', 'N', '37', '2', '10米配', '5米', '241', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8280', 'XDL153673', '551', '127', '0', '9', 'W', '5', '122', 'N', '37', '2', '10米配', '5米', '156', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8281', 'YM150109B', '359', '181', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '11', '', '2', '2014-K-3970/3969/3966/3965', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8282', 'YE150109G', '560', '167', '0', '2', 'W', '2', '123', 'Y', '2', '2', '9米', '', '141', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NA347(POORD02121)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8283', 'YE150109J', '560', '178', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V12N0761-0762，0764-0765(WKS20150109055)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8284', 'PO01501090043.7', '512', '410', '0', '18', 'W', '2', '12', 'Y', '7', '3', '7米', '', '242', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8285', 'SYLG150109A', '571', '101', '0', '2', 'W', '2', '132', 'Y', '4', '2', '10米', '', '199', '出口包装箱（2层），减震垫10块（赠,WYT-TAM-5），机座外型特殊，韩国富士用图纸,另每台带4个M16*45螺栓,预先接上编码器电缆', '2015-01-01', '', '5', '18', '26', '', '6', '', '1', '12', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8286', 'YE150109F', '574', '215', '0', '10', 'W', '2', '127', 'Y', '6', '2', '8米', '', '243', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '22', '', '3', 'D120048/P150109135', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8287', 'CQT201501-22', '576', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '3', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8288', 'YM150107F', '536', '528', '0', '1', 'W', '2', '1', 'N', '1', '1', '', '', '1', '木箱包装，出厂编号：07HJJ6799', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8289', 'N15-0005', '40', '168', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8290', 'YE150108G', '550', '169', '0', '2', 'W', '2', '122', 'Y', '2', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-K-0005/0006', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8291', 'YN141217B', '507', '168', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8292', 'YM141223G', '554', '119', '0', '9', 'W', '5', '122', 'N', '5', '2', '8米', '4米', '135', 'D型', '2015-01-01', '', '5', '14', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8293', 'YM150108C', '555', '126', '0', '9', 'W', '5', '122', 'N', '37', '2', '8米配', '5米', '135', '', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8294', 'YM150106J', '555', '177', '0', '2', 'W', '3', '122', 'Y', '37', '2', '8米配', '', '135', '', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8295', 'YM150107G', '556', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8296', 'YM150107H', '556', '169', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8297', 'YM150106D', '556', '171', '0', '2', 'W', '2', '122', 'Y', '2', '2', '7米', '', '135', 'D型，合格证和随机资料不放在箱子里单独邮给客户', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8298', 'YE150106L', '502', '172', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'D2182', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8299', 'YE150106M', '502', '178', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'D2183', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8300', 'YE150107E', '514', '168', '0', '2', 'W', '2', '122', 'N', '5', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '20141222-2', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8301', 'YE150107A', '456', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '244', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8302', 'YS150107B', '516', '129', '0', '9', 'W', '5', '122', 'Y', '2', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '2', '', '2', 'A.2010.10.042补', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8303', 'YS150107C', '516', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A.2015.01.002-004', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8304', 'YS150107J', '516', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '东莞科迈电梯', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8305', 'YS150107K', '516', '225', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '194', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '东莞科迈电梯', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8306', 'YM150106K', '563', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型，减震2套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8307', 'YM150107E', '564', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '14', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8308', 'YM150107I', '566', '177', '0', '2', 'W', '3', '122', 'Y', '5', '2', '10米', '', '135', 'D型，减震24块（赠)', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8309', 'YM150107C', '359', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '10', '', '2', '2014-K-3995-3994/3994b', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8310', 'YM150107D', '359', '162', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '13', '', '2', '2014-K-0020', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8311', 'YS150106C', '525', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '2-1412174-76', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8312', 'YS150107G', '528', '152', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'XAK20150105-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8313', 'YE150108L', '560', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '245', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N6335-6336(WKS20150108070)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8314', 'YS150107H', '528', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', ' XAK20141230-9', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8315', 'YS150107D', '528', '215', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'XAK20141230-5', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8316', 'YE150107F', '353', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8317', 'PO01501080033.1', '512', '394', '0', '18', 'W', '2', '19', 'Y', '7', '3', '7米', '', '246', '提供原点值 ', '2015-01-01', '', '5', '8', '23', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8318', 'YS150107A', '531', '174', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '167', 'D型，广日豆绿色 β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', 'P000420150107', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8319', 'YS150107F', '531', '526', '0', '1', 'W', '2', '125', 'Y', '2', '2', '7米', '', '167', 'D型，广日豆绿色 β105 γ40 ', '2015-01-01', '', '5', '8', '11', '', '2', 'P000420150107', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8320', 'YM150108D', '537', '529', '0', '1', 'W', '1', '130', 'Y', '1', '1', '', '', '1', '发组装件，木箱包装，N轴，曳引轮400*5*10*16，，代码1.13.01.111，图号WYT-S-3D(2.3/2.4版）原主机S1.75D-N 08157701XT有机房。', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8321', 'PO01501060059.1', '512', '174', '0', '2', 'W', '2', '105', 'N', '2', '2', '7米', '', '247', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8322', 'PO01501060059.3', '512', '178', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '196', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8323', 'YE150105C', '565', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '201501010', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8324', 'YE150105B', '565', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '201501006', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8325', '预投1', '530', '112', '0', '13', 'W', '5', '123', 'Y', '4', '2', '7米', '', '135', '', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8326', '预投2', '530', '159', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米', '', '135', '', '2015-01-01', '', '5', '3', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8327', '预投3', '530', '160', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米', '', '135', '', '2015-01-01', '', '5', '3', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8328', '预投4', '530', '162', '0', '2', 'W', '2', '123', 'Y', '4', '2', '7米', '', '135', '', '2015-01-01', '', '5', '3', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8329', '14Z0203.208', '530', '215', '0', '10', 'W', '2', '34', 'Y', '4', '2', '7米', '', '248', '', '2015-01-01', '', '5', '3', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8330', 'YE150106S', '574', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '13', '', '3', 'D120015/P-201501231', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8331', '89358', '533', '217', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米配', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8332', 'YAIJ201501-12', '578', '174', '0', '2', 'W', '3', '122', 'N', '6', '2', '10米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '9', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8333', 'YE150107B', '546', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8334', 'XDL145714', '551', '120', '0', '9', 'W', '5', '122', 'N', '37', '2', '10米配', '5米', '249', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8335', 'XDL145716-145717', '551', '122', '0', '9', 'W', '5', '122', 'Y', '10', '2', '10米配', '', '241', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8336', 'XDL145683-145685', '551', '149', '0', '9', 'W', '5', '16', 'Y', '37', '2', '10米配', '', '156', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '2', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8337', 'XDL145728', '551', '168', '0', '2', 'W', '2', '122', 'Y', '37', '2', '10米配', '', '163', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8338', 'XDL145724-145727', '551', '169', '0', '2', 'W', '2', '122', 'Y', '10', '2', '10米配', '', '157', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '10', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8339', 'XDL145712', '551', '181', '0', '2', 'W', '2', '122', 'Y', '10', '2', '10米配', '', '250', '西门子LOGO包装箱', '2015-01-01', '', '5', '14', '11', '', '42', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8340', 'YE150105E', '508', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '13', '', '2', '20150102', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8341', 'YE150105D', '508', '180', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', '20150101', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8342', 'YM150105A', '561', '177', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '213', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8343', 'YS150105C', '518', '173', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '14833627a L1#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8344', 'YS150105B', '518', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '14833579 L9#', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8345', 'YS150105A', '518', '197', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '14833597   L1-L8', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8346', 'YM150106B', '359', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '251', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '10', '', '2', '2014-K-3456-3459/ 3424/3409/ 3425/ 3564/3565/ 3514', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8347', 'YM150105B', '567', '130', '0', '9', 'W', '2', '122', 'Y', '4', '2', '10米', '', '135', '散头', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8348', 'YE150106D', '560', '171', '0', '2', 'W', '2', '123', 'Y', '6', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14N2799-2806(WKS20150106007)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8349', '预投YS150106.23', '512', '159', '0', '2', 'W', '2', '129', 'Y', '2', '2', '7米', '', '252', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8350', 'GLR201501050017（G14NB500）', '568', '174', '0', '2', 'W', '2', '122', 'N', '6', '2', '9米', '', '135', 'D型，歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '19', '10', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8351', '预投YS150106.24', '512', '159', '0', '2', 'W', '2', '129', 'Y', '2', '2', '7米', '', '253', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8352', '预投YS150106.13', '512', '168', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '254', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8353', '预投YS150106.14', '512', '168', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '255', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8354', '预投YS150106.15', '512', '174', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '256', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8355', 'GLR201501050012(G14NH037-038)', '568', '178', '0', '2', 'W', '2', '122', 'Y', '6', '2', '9米', '', '135', 'D型，歌拉瑞包装壁挂器无厂址', '2015-01-01', '', '5', '21', '10', '', '3', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8356', '预投YS150106.16', '512', '174', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '257', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8357', '预投YS150106.21', '512', '162', '0', '2', 'W', '2', '129', 'Y', '2', '2', '7米', '', '258', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8358', '预投YS150106.22', '512', '162', '0', '2', 'W', '2', '129', 'Y', '2', '2', '7米', '', '259', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8359', '预投YS150106.17', '512', '171', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '260', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8360', '预投YS150106.18', '512', '171', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '261', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8361', '预投YS150106.19', '512', '177', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '262', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8362', '预投YS150106.20', '512', '177', '0', '2', 'W', '2', '125', 'Y', '2', '2', '7米', '', '263', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8363', 'YE150105N', '572', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'HT14120135(L1)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8364', 'YE141230E', '342', '152', '0', '2', 'W', '2', '123', 'Y', '5', '2', '7米', '', '135', 'D型  ', '2015-01-01', '', '5', '18', '13', '', '2', 'NA14-K-C5814', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8365', 'YE141230F', '342', '159', '0', '2', 'W', '2', '123', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'NA14-K-C5815', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8366', 'YE150105H', '574', '126', '0', '9', 'W', '5', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '2', '', '3', 'D100038/P-201501136', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8367', 'YE150105G', '574', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '264', 'D型，要原点值  ', '2015-01-01', '', '5', '18', '10', '', '2', 'D120116/P-201501136', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8368', '14Z5292', '530', '222', '0', '10', 'W', '2', '127', 'Y', '4', '2', '', '', '135', '不带电缆', '2015-01-01', '', '5', '3', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8369', '预投YS150106.1', '530', '119', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '265', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8370', 'YE150105J', '574', '180', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '200', 'D型，要原点值，出口免熏蒸包装', '2015-01-01', '', '5', '18', '11', '', '42', 'D12SYS06/P-201501136', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8371', '预投YS150106.4', '530', '126', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '266', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8372', '预投YS150106.2', '530', '120', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '267', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8373', '预投YS150106.5', '530', '127', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '268', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8374', '预投YS150106.3', '530', '122', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '269', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8375', '预投YS150106.6', '530', '129', '0', '13', 'W', '5', '122', 'Y', '4', '2', '', '', '270', '不带电缆', '2015-01-01', '', '5', '3', '2', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8376', '预投YS150106.7', '530', '168', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '265', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8377', '预投YS150106.10', '530', '174', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '266', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8378', '预投YS150106.8', '530', '169', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '267', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8379', '预投YS150106.11', '530', '175', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '268', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8380', '预投YS150106.9', '530', '171', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '269', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8381', '预投YS150106.12', '530', '177', '0', '2', 'W', '2', '122', 'Y', '4', '2', '', '', '270', '不带电缆', '2015-01-01', '', '5', '3', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8382', '711135', '533', '170', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8383', '预投YS150106.25', '533', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8384', '预投YS150106.26', '533', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8385', '预投YS150106.27', '533', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8386', '预投YS150106.30', '533', '196', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8387', '预投YS150106.29', '533', '191', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8388', '预投YS150106.31', '533', '197', '0', '2', 'W', '2', '126', 'Y', '6', '2', '7米配', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '11', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8389', 'YE150106A', '550', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-K-0001', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8390', 'YS141231G', '552', '17', '0', '9', 'W', '2', '122', 'Y', '7', '3', '7米', '', '135', '永日蓝,发河南郑州现场', '2015-01-01', '', '5', '3', '3', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8391', 'YS141231F', '553', '24', '0', '9', 'W', '2', '122', 'Y', '4', '3', '7米', '', '135', '永日蓝，多带一个D型15针插头放在随机资料里，发广西玉林现场', '2015-01-01', '', '5', '3', '3', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8392', 'SSEC02789', '492', '122', '0', '9', 'W', '5', '122', 'Y', '1', '2', '', '', '164', '不带电缆线。蓝光标准颜色', '2015-01-01', '', '5', '18', '2', '', '3', '201006601售后服务', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8393', 'PO01501050060.6', '512', '177', '0', '2', 'W', '2', '105', 'N', '2', '2', '7米', '', '271', 'D型，提供原点值，β85 γ50 V型，防护罩用WYT-TA.6B', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8394', 'SSEC02636', '492', '168', '0', '2', 'W', '2', '122', 'Y', '2', '2', '', '', '164', '不带电缆线', '2015-01-01', '', '5', '14', '10', '', '3', '2014122655-2658', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8395', 'SSEC02777', '492', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线。', '2015-01-01', '', '5', '14', '10', '', '3', '20141226', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8396', 'SSEC02718', '492', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '', '', '164', '不带电缆线。', '2015-01-01', '', '5', '14', '10', '', '3', '2014122667-2674', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8397', 'YE141231A', '502', '159', '0', '2', 'W', '2', '123', 'N', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '13', '', '2', 'D2144', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8398', 'PO01501050060.7', '512', '520', '0', '1', 'W', '2', '125', 'Y', '2', '2', '7米', '', '272', 'D型，提供原点值，β105 γ40 ', '2015-01-01', '', '5', '8', '10', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8399', 'YE150101A', '456', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '244', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8400', 'YS141231B', '517', '170', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型 ', '2015-01-01', '', '5', '18', '10', '', '2', 'K0425-0426', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8401', 'YS141230A', '504', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '158', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1412092', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8402', 'YS141230B', '504', '174', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '273', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1412093', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8403', 'YM150104C', '563', '126', '0', '9', 'W', '2', '122', 'N', '2', '2', '8米', '7米', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8404', 'YM150104D', '563', '122', '0', '9', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型，减震3套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8405', 'YS150104C', '504', '170', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '158', 'D型，主机颜色为黑色，代码为1.06.578', '2015-01-01', '', '5', '13', '10', '', '2', '1411045-46', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8406', 'YM150104E', '563', '129', '0', '9', 'W', '2', '7', 'Y', '6', '2', '8米', '', '135', 'D型，减震3套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8407', 'YM150104H', '563', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '135', 'D型，减震12套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '10', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8408', 'YM141231B', '359', '175', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '10', '', '2', '2014-K-3821', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8409', 'YM141231C', '359', '177', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '179', 'D型，型号WYT前加大写ALD 奥立达包装箱', '2015-01-01', '', '5', '18', '10', '', '2', '2014-K-3835', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8410', 'YM141226B', '363', '524', '0', '1', 'W', '1', '122', 'N', '1', '1', '', '', '1', '木箱包装，WYT-S-3D(2.2版),S1.75C主机用,04年主机', '2015-01-01', '', '5', '18', '1', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8411', 'GLR201501030001（14LS093）', '568', '159', '0', '2', 'W', '2', '123', 'N', '6', '2', '9米', '', '144', 'D型壁挂器无厂址', '2015-01-01', '', '5', '19', '13', '', '2', '', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8412', 'YS150104E', '528', '159', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', 'XAK20141229-1', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8413', 'YE150105F', '560', '174', '0', '2', 'W', '2', '122', 'Y', '2', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '10', '', '3', 'V14NA980(WKS20150105012)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8414', 'YS141231A', '528', '168', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '138', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'XAK20141223-2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8415', 'YS141231D', '528', '181', '0', '2', 'W', '2', '122', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '11', '', '2', 'XAK20141223-2', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8416', 'YE150105A', '560', '225', '0', '10', 'W', '2', '127', 'Y', '2', '2', '9米', '', '143', 'D型，沃克斯包装箱', '2015-01-01', '', '5', '18', '22', '', '3', 'V14NA964(WKS20140903432)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8417', 'YS141231B', '528', '222', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', 'XAB20141215-4/5', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8418', 'PO01412310078', '512', '225', '0', '10', 'W', '2', '115', 'Y', '2', '2', '7米', '', '274', 'D型，提供原点值，V型带切口:100°、50°', '2015-01-01', '', '5', '8', '22', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8419', 'YS141230C', '531', '130', '0', '9', 'W', '5', '122', 'Y', '6', '2', '7米', '', '167', 'D型', '2015-01-01', '', '5', '3', '2', '', '2', 'P000520141230', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8420', 'YE150104A', '574', '169', '0', '2', 'W', '2', '122', 'Y', '6', '2', '8米', '', '142', 'D型，要原点值，怡达包装箱和装箱清单，带两张合格证，一张怡达合格证，一张蓝光 ', '2015-01-01', '', '5', '18', '10', '', '3', 'D100085/P-201501036', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8421', '710083', '533', '152', '0', '2', 'W', '2', '123', 'N', '6', '2', '7米配', '', '133', 'D型 ', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8422', '711031', '533', '154', '0', '2', 'W', '2', '123', 'Y', '6', '2', '7米配', '', '275', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '', '1', '8', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8423', 'YE150101B', '348', '160', '0', '2', 'W', '2', '123', 'Y', '5', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '13', '', '2', '150103(3209)', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8424', 'YM150104G', '538', '9', '0', '9', 'W', '5', '123', 'Y', '4', '3', '7米', '', '135', '散头', '2015-01-01', '', '5', '18', '2', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8425', 'YM141231D', '539', '215', '0', '10', 'W', '2', '124', 'Y', '6', '2', '7米', '', '135', 'D型', '2015-01-01', '', '5', '18', '22', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8426', 'YM150104C', '563', '126', '0', '9', 'W', '2', '122', 'N', '2', '2', '8米', '7米', '135', 'D型，减震1套（赠，减震组合螺栓型号为：M16*40）', '2015-01-01', '', '5', '18', '3', '', '2', '', '1', '11', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8427', 'YE141231L', '550', '173', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-Kn-0088/89', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8428', 'YE141231M', '550', '175', '0', '2', 'W', '2', '122', 'N', '6', '2', '8米', '', '135', 'D型', '2015-01-01', '', '5', '18', '10', '', '2', 'A14-Kn-0090AB', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8429', 'YE2015-00653-', '341', '174', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '152', 'D型  工号：2015-00653-00654', '2015-01-01', '', '1', '18', '10', '', '2', '2015-00653-00', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8430', 'YE2015-00679-', '341', '171', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '161', 'D型  工号：2015-00679-80,83-84,87-91', '2015-01-01', '', '1', '18', '10', '', '2', '2015-00679-80,', '1', '10', 'Y', 'Y', '100');
INSERT INTO `htxx` VALUES ('8431', 'YE2015-00681-', '341', '177', '0', '2', 'W', '2', '122', 'Y', '4', '2', '7米', '', '161', 'D型  工号：2015-00681-82,85-86,92-95', '2015-01-01', '', '1', '18', '10', '', '2', '2015-00681-82,', '1', '10', 'Y', 'Y', '100');
INSERT INTO `khcyxxb` VALUES ('1', '1', '1', 'Y', '1', '1', 'Y', '1', '1', '5m', '8m', '蓝光英文');
INSERT INTO `khqy` VALUES ('1', '');
INSERT INTO `khqy` VALUES ('2', 'YA');
INSERT INTO `khqy` VALUES ('3', 'YE1');
INSERT INTO `khqy` VALUES ('4', 'YE2');
INSERT INTO `khqy` VALUES ('5', 'YN');
INSERT INTO `khqy` VALUES ('6', 'YS');
INSERT INTO `khqy` VALUES ('7', 'YW');
INSERT INTO `khqy` VALUES ('8', '华南');
INSERT INTO `khqy` VALUES ('9', '北方');
INSERT INTO `khqy` VALUES ('10', '华东1');
INSERT INTO `khqy` VALUES ('11', '华东2');
INSERT INTO `khqy` VALUES ('12', '国际');
INSERT INTO `khxx` VALUES ('1', '', '', '', null, '');
INSERT INTO `khxx` VALUES ('2', '北京航天金羊', '北京通州区永乐经济开发区(河北省廊坊市)', '徐智健1113969966 赵爽1383369631', null, '010-80114178');
INSERT INTO `khxx` VALUES ('3', '北京升华电梯有限公司', '北京市顺义区京密路西牛栏山段7号', '孙峰 1366363860  010-1138899-1103传真 舒薇熹010-1398899-1101', null, '010-69410840');
INSERT INTO `khxx` VALUES ('4', '北京升华北京分公司', '北京市朝阳区大郊亭中街2号院华腾国际甲5#2楼', '罗学铸 010-1836903 1101036169', null, '010-87912909');
INSERT INTO `khxx` VALUES ('5', '北京九方基业电梯设备有限公司', '北京市丰台区嘉园一里3号楼601室', '010-8916318朱方伍', null, null);
INSERT INTO `khxx` VALUES ('6', '北京宏立电梯服务中心', '北京市岩庆县东外大街建业胡同经济委员会1楼电梯服务公司', '李臣勇1390131939', null, '010-87893084');
INSERT INTO `khxx` VALUES ('7', '北京恒富隆机电部设备安装有限公司', '北京通州区马驹桥新海东路2号院8号楼722', '010-6019810杜力亚1380166988', null, '010-60193811');
INSERT INTO `khxx` VALUES ('8', '北京雍和瑞景物业管理有限公司', '北京东城区安定门东大街28号B座15层', '蔡鹏飞13901101838', null, '010-64079983');
INSERT INTO `khxx` VALUES ('9', '华升富士达', '北京东城区新中街68号聚龙花园8A楼102室', '010-61116688崔学工', null, '010-61122332');
INSERT INTO `khxx` VALUES ('10', '北京燕园图新电梯自动化技术有限公司', '北京海淀区上地南路10号院1号楼首层12-6号', '刘媛010-83903810', null, '010-62978231');
INSERT INTO `khxx` VALUES ('11', '北京金前锋电梯有限公司第三技术服务有限公司', '北京', null, null, null);
INSERT INTO `khxx` VALUES ('12', '莫尼克电梯制造(北京)有限公司', '亦庄经济技术开发区东区同和路', '周法国010-89396910', null, null);
INSERT INTO `khxx` VALUES ('13', '莫尼克电梯制造(北京)有限公司', '北京市朝阳区广汇门外大街8号优士阁西座12B10', '010-18613911', null, null);
INSERT INTO `khxx` VALUES ('14', '广东台日电梯有限公司北京分公司', '北京市丰台区三路居凤凰嘴53号', '任宏13911166383', null, '010-66011801');
INSERT INTO `khxx` VALUES ('15', '北京百斯特尔电梯有限公司', '北京市丰台区华源三里16号楼3单元101', '夏经理13901001933', null, '010-63379733');
INSERT INTO `khxx` VALUES ('16', '北京雍和瑞景物业管理有限公司(时代龙和代)', '北京市东城区秦老胡同甲16号', '贾炜   13366396998', null, null);
INSERT INTO `khxx` VALUES ('17', '北京多嘉通电梯有限公司', '北京朝阳区潘家园松榆西里五十六楼四门202室(发票接收)', '李世晓139-01306691 王树苹(发票)010-69366193', null, '010-87390662');
INSERT INTO `khxx` VALUES ('18', '北京中铁电梯工程有限公司', '北京市丰台区张仪村路16号中铁建设集团办公西区电梯公司', '李祖章13601019681 010-11881301', null, '010-11881268');
INSERT INTO `khxx` VALUES ('19', '北京挚诚恒远电梯有限责任公司', '北京市朝阳区小营路10号阳明广场C座9F', '艾宪岭13901311330', null, null);
INSERT INTO `khxx` VALUES ('20', '北京金宇联合设备安装有限公司', '北京市海淀区中关村南大街12号卉园大楼A401', '康建', null, null);
INSERT INTO `khxx` VALUES ('21', '北京首都电梯厂', '北京市朝阳区东坝乡娘娘庙后街', '丰毅武010-61693661', null, null);
INSERT INTO `khxx` VALUES ('22', '北京佳友恒泰机电设备有限公司', '北京市丰台区友安门外开阳里三区1号楼3单元101号', '刘继林010-63163916 13901093911', null, null);
INSERT INTO `khxx` VALUES ('23', '北京优力维特电梯有限公司(与佳友恒泰一家)', '北京市丰台区友安门外开阳里三区1号楼3单元101号', '刘继林010-63163916 13901093911', null, null);
INSERT INTO `khxx` VALUES ('24', '北京怡达和谐电梯有限责任公司', '北京市朝阳区望花路西八间北里163号楼三层', '水文13810963398 010-66961936', null, '010-64741724');
INSERT INTO `khxx` VALUES ('25', '北京南方恒力电梯工程有限公司', '北京市朝阳区北苑路大屯里小区115楼2409室', '管建民13301301806 010-86803866', null, null);
INSERT INTO `khxx` VALUES ('26', '北京升华电梯集团有限公司黑龙江省分公司', '哈尔滨市南岗区长江路65号723室', '王威0611-83031989 马明艳0611-83031899', null, '0411-83021767');
INSERT INTO `khxx` VALUES ('27', '北京金菱恒达电梯设备有限公司', '北京市朝阳区西大望路平乐园10号', '刘会玲010-69980130', null, null);
INSERT INTO `khxx` VALUES ('28', '北京北安时代电梯安装公司', '北京市朝阳区百子湾南二路76号院7号楼3单元', '黄建峰13901086100', null, '0379-63216612');
INSERT INTO `khxx` VALUES ('29', '北京北方鑫奥电梯有限公司', '北京市朝阳区西大望路19号金港园国际8栋1单元103号', '顾爱民13901399366 010-89916908-606/010-89916918-606', null, '010-87716416');
INSERT INTO `khxx` VALUES ('30', '北京安捷利达', '北京市西城区黄寺大街23号6号楼1层3号（德胜园区）', '段晓林010-83339631/13311316918', null, null);
INSERT INTO `khxx` VALUES ('31', '北京捷尔斯', '北京市丰台区南顶路6号院', '周海军13910919981', null, null);
INSERT INTO `khxx` VALUES ('32', '北京斯迈普电梯有限公司', '北京市丰台区右安门外大街2号楼迦南大厦1303室', '史永明010-6319 1830  18910633930', null, null);
INSERT INTO `khxx` VALUES ('33', '北京华菱鑫奥电梯有限公司', '北京市大兴区西红门宏盛园22-4-102', '袁志伦13311119381', null, null);
INSERT INTO `khxx` VALUES ('34', '北京铂铠星奥电梯设备有限公司', '北京市丰台区星河苑1号院24号楼501', '李德志 010-69136133 13011398361', null, null);
INSERT INTO `khxx` VALUES ('35', '苏州飞腾北京分公司', '北京市西城区三里河路40号院4号楼502', '梁小波13601300339', null, null);
INSERT INTO `khxx` VALUES ('36', '北京广船伟华机电设备有限公司', '北京市海淀区龙翔路4号1611', '廉振英 13910836636  010-83098969', null, null);
INSERT INTO `khxx` VALUES ('37', '天津宏翔电梯有限公司', '天津市西青区辛口镇水高庄工业园2号院', '陈龙033-36396363  13803019913', null, '022-26374243');
INSERT INTO `khxx` VALUES ('38', '天津市盛诚电梯装璜有限公司', '天津市河北区宜白路玉琢里后下卫道88号', '周大立13103136189', null, '022-26710338');
INSERT INTO `khxx` VALUES ('39', '天津中江公司', '天津市河西区福建路福盛花园物业办公楼', '孟德艳033-33330318', null, null);
INSERT INTO `khxx` VALUES ('40', '天津奥富特', '天津市北辰区津围公路LG电子对面 北辰科技园 景观路', '吴刚11803396069', null, '022-86313711');
INSERT INTO `khxx` VALUES ('41', '天津市澳士达电梯销售有限公司', '天津市南开区庆丰路十号', '辛云刚13831619008', null, null);
INSERT INTO `khxx` VALUES ('42', '天津市塘沽区同正电梯有限公司', '塘沽区贻成东园13号楼1门102', '程恩全13930136339   033-66361099（传真）', null, '022-21301614说明给同正发传真');
INSERT INTO `khxx` VALUES ('43', '天津市得利信电梯有限公司', '收货地址:天津市西青区张窝(津涞公路距津沧高速公路200米)于建军 13920176035', '张书信033-38368666*13930830190', null, '022-28348646');
INSERT INTO `khxx` VALUES ('44', '天津玉泰实业有限公司', '天津东丽开发区三纬路与一经路交口', '刘士琴033-36991999', null, null);
INSERT INTO `khxx` VALUES ('45', '天津市盛强电梯有限公司', '北辰区宜兴埠津围公路107号', '033-86313309 魏有祥', null, null);
INSERT INTO `khxx` VALUES ('46', '天津东南电梯销售有限公司', '天津河西区友谊路增进道22号', '发票:杨伟颖033-38369983-83 毛卫兵033-38369983-803', null, '022-28367880');
INSERT INTO `khxx` VALUES ('47', '天津市康通电梯销售有限公司', '天津市河西区黑牛城道纪发公寓增1号', '赵玉娟 033-33916919 33963960王建才 38333131', null, '022-28322121');
INSERT INTO `khxx` VALUES ('48', '天津市津翔电梯厂巨星机电工程公司', '天津市北辰区双街镇郎园工业区', '孙岳云86816938-8006陈祥义033-36980916', null, '022-26980912');
INSERT INTO `khxx` VALUES ('49', '天津市津翔巨星电梯制造有限公司', '天津市北辰区双街镇郎园工业区', '吴凤来11900369136 座机18930911861 033-36980919 033-36980913', null, '022-26980912');
INSERT INTO `khxx` VALUES ('50', '天津市中迅赛勒瓦电梯有限公司', '河西区紫金山路澳隆花园C-5-601', '033-88391361龚健13116130199', null, '022-88294944');
INSERT INTO `khxx` VALUES ('51', '天津市三志电梯有限公司', '西青区大寺镇北口村', '周惠亭033-33990313*33960010', null, '022-23970213');
INSERT INTO `khxx` VALUES ('52', '天津市同兴电梯有限公司', '天津市河东区12经路13号501-506室', '韩金旭13903193131  033-36319363 宋经理13830991116', null, '022-24317376');
INSERT INTO `khxx` VALUES ('53', '天津莱茵克拉电梯有限公司', null, '39363100', null, '022-29229100');
INSERT INTO `khxx` VALUES ('54', '天津奥斯达电梯有限公司', '天津市大寺镇北里八口村', '（收货 EMS发票）黄文朝033-83983313*13803003311 王利花11033063663', null, '022-83983313');
INSERT INTO `khxx` VALUES ('55', '天津津奥电梯有限公司', '天津市河西区宾馆南道4号', '陆毅 13633091600 033-38310806', null, null);
INSERT INTO `khxx` VALUES ('56', '柏岱斯蒂(天津)机械有限公司', '天津市北辰开发区双源科技园', '万宁033-3698098 0    0698     0981', null, '022-26980983');
INSERT INTO `khxx` VALUES ('57', '天津西玛格电梯制造有限公司', '天津北辰区宜兴埠京津塘高速公路东', '033-86311911/033-86313911 赵跃华(13830019681 033-86816393)', null, '022-86311911');
INSERT INTO `khxx` VALUES ('58', '天津西玛格电梯有限公司', '天津市东丽区金钟街南孙庄新河北', '董玉斌033-86816393/13003333666', null, null);
INSERT INTO `khxx` VALUES ('59', '天津联恒克劳斯电梯有限公司', '天津大港经济开发区安和路433号', '郭鑫义13831191383/033-19918319', null, '022-19718360');
INSERT INTO `khxx` VALUES ('60', '天津市恒晟自动化工程有限公司', '天津红桥区丁字沽一号路泛洋大厦2-2206室', '刘淞033-36110030/36168313', null, '022-26148312');
INSERT INTO `khxx` VALUES ('61', '天津市联星电梯有限公司', '天津市河北区胜利路琴海公寓1号楼1门1007室', '王吉元13116089989/033-60131968', null, '022-60131749');
INSERT INTO `khxx` VALUES ('62', '天津市恒利电梯技术开发有限公司', '发票寄天津办（张冠健） 刘斌去取', '刘斌13683003988', null, '022-60111012');
INSERT INTO `khxx` VALUES ('63', '天津市永诚电梯有限公司', '天津市津南区双港工业园一号路', '范连成13803061069', null, '28171166');
INSERT INTO `khxx` VALUES ('64', '天津冠辉安装工程有限公司', '天津市河西区友谊北路广银大厦1209室', '李俊祥 13683198038  李强13831981636  033-33361999', null, '022-23233101-82');
INSERT INTO `khxx` VALUES ('65', '天津海通电梯有限公司', null, '刘11900318116', null, '022-23122078');
INSERT INTO `khxx` VALUES ('66', '天津永成电梯有限公司', '天津市津南区梨双路双港工业园区1号路2号', '033-38191333 范瑞成(13389039999)', null, null);
INSERT INTO `khxx` VALUES ('67', '天津赛福伟业电梯技术有限公司', '天津市西青区侯台村碧欣园B区2号楼3门302', '翟军13930801666', null, null);
INSERT INTO `khxx` VALUES ('68', '天津市新奥翔电梯安装维修配件中心', '天津市河北区三马路77号', '郭玉武13803091139', null, '022-26663291');
INSERT INTO `khxx` VALUES ('69', '天津菱奥宏达电梯有限公司', '天津市北辰区文化中心图书馆B座509室', '李辉13903133399 033-36838169', null, null);
INSERT INTO `khxx` VALUES ('70', '天津市中颖电梯有限公司', '天津市南开区北城街金轩商务中心1号楼2505室', '张洋18930611999', null, '022-86660722');
INSERT INTO `khxx` VALUES ('71', '天津泰福电梯安装工程有限公司', '天津市和平区青海路46号', '梅纯13930809933', null, '022-27819110');
INSERT INTO `khxx` VALUES ('72', '天津西北电梯安装有限公司', '天津市河西区友谊路增进道22号', '办公室033-38138396', null, '022-28367782');
INSERT INTO `khxx` VALUES ('73', '天津市奥博电梯销售有限公司', '天津市河东区中山门互助南里23-4号底商 发票地址:河东区华兴道月光园6-2-101', '李永财033-86361933 李小姐(发票)13913983016', null, null);
INSERT INTO `khxx` VALUES ('74', '天津辽富电梯有限公司', '天津市河北区王串场五号路盛宇里15号110门305室', '刘恒宇13313039983', null, null);
INSERT INTO `khxx` VALUES ('75', '天津市欧科电梯有限公司', '天津市北辰区铁东路(铁东北路)天盈道16号', '王志祥13930910809 刘戈雷：13803089311', null, '022-26992331');
INSERT INTO `khxx` VALUES ('76', '天津铃木电梯工程有限公司', '发票:天津市南开区西湖道风荷园1号楼4门902室', '张丽明033-39610338', null, null);
INSERT INTO `khxx` VALUES ('77', '天津方景电梯工程有限公司', '天津市东丽区昆仑路临月里6号楼2门501室', '李蓓  13831118601', null, null);
INSERT INTO `khxx` VALUES ('78', '天津市科苑电梯配件有限公司', '天津市河西区大沽南路洪泽花园7号楼1门101', '于艳民033-88363808', null, '022-88262808');
INSERT INTO `khxx` VALUES ('79', '天津市茗熔机电设备销售中心', '天津市南开区密云路与黄河道交汇西南侧北方城一区36栋105', '金先生033-39361180、13803061601', null, null);
INSERT INTO `khxx` VALUES ('80', '天津宏大', '天津市河北区养鱼池路3号（第二印染厂院内）', '赵宏光13930661996', null, null);
INSERT INTO `khxx` VALUES ('81', '天津唯思电梯技术服务有限公司', '天津市河西区九华山路蓝水园1-2-601', '陈化平033-83831113  18019193   18930691393', null, '022-83831113');
INSERT INTO `khxx` VALUES ('82', '天津奥瑞克机电有限公司', '天津东丽开发区五纬路与一经路交口', '王炳清033-36991999', null, null);
INSERT INTO `khxx` VALUES ('83', '天津合峰电梯有限公司', '天津市和平区西康路赛顿中心C座12层通力电梯公司', '段秀兰13913610068', null, null);
INSERT INTO `khxx` VALUES ('84', '辽宁北富电梯有限公司（原铁岭北方富士）', '铁岭县新台子镇懿路工业园区', '总经理:张洪举13960696801                                  常帅036-98811830、8811831', null, '024-8811820');
INSERT INTO `khxx` VALUES ('85', '铁岭北方富士电梯有限公司（驻沈阳办事处）-收货 发票', '沈阳市大东区老瓜堡西路14-5号8门', '赵杨杨13860061610 常小姐 036-88316663/036-98811830', null, null);
INSERT INTO `khxx` VALUES ('86', '沈阳申菱电梯维修有限公司', '沈阳市沈河区北站路78号邮政大厦转电梯何连华', '何连华33193339', null, null);
INSERT INTO `khxx` VALUES ('87', '沈阳沃可斯电梯有限公司', '沈阳市于洪区银山路59号', '方坤89331398 董智聪(收货） 孙斌 王雪（发票）86613631 李沛收 86693390', null, '024-86673891');
INSERT INTO `khxx` VALUES ('88', '沈阳捷迅电梯有限公司（沈阳泰特电梯有限公司）', '辽宁省抚顺市经济开发区中兴大街（七号街西侧B4b区）', '庞丽丹036-13818899', null, '13818811');
INSERT INTO `khxx` VALUES ('89', '沈阳长城电梯厂', '沈阳市沈河区方家栏路76号甲', '曲界殊13806998899  36316818 发票:财务吉明淑 81306009/36318398', null, null);
INSERT INTO `khxx` VALUES ('90', '沈阳西菱奥电梯工程有限公司', '沈阳市铁西区兴工街93-3  9门兴隆苑', '周龙18609816169', null, null);
INSERT INTO `khxx` VALUES ('91', '沈阳菱诺自动化设备有限公司', '沈阳市浑南新区高科路39号', '宋阳13960001398 王晓冬13960091989', null, '024-23783919');
INSERT INTO `khxx` VALUES ('92', '沈阳翰溟先达', '沈阳市沈河区惠工街157号362', '张海雁   13333610391', null, null);
INSERT INTO `khxx` VALUES ('93', '沈阳优力维特电梯制造厂', '沈阳市和平区十三纬路23号邵文君23857536/81090222                      发货地址：沈阳市东陵区民族经济开发区民旺路18号辽海机械厂院内（绕城高速下河湾收费口左转）', '吴绍东036-33896619`33896613  *13960660690   33909131技术杨玉海13136306106采购王宇13960068831 33909131 传真：33909131', null, '23707121  23876419');
INSERT INTO `khxx` VALUES ('94', '沈阳市横滨电梯厂', '铁西云峰街88506146-809财务', '周国刚88111880 13906039866                      周国强13106991399//88101331', null, '88106140');
INSERT INTO `khxx` VALUES ('95', '沈阳西奥电梯制造有限公司', '沈阳大东区大北街86-92号魅力大厦6楼', '陈文国13906039699 81196911 马桂英11860309666', null, '024-88106140');
INSERT INTO `khxx` VALUES ('96', '沈阳三洋电梯安装分公司', null, '胡宽胜13906006601 38909890 王美清13666061190', null, '024-88097893');
INSERT INTO `khxx` VALUES ('97', '辽宁三洋', '沈阳市于洪区银山路59号5楼', '马学杰 86606989 13998833386', null, '024-86601391');
INSERT INTO `khxx` VALUES ('98', '辽宁三洋(营口)', '营口市西市区科飞路33号', '李元春 13960911381  沈锦营11961911968', null, '0417-6669161');
INSERT INTO `khxx` VALUES ('99', '辽宁北方三洋电梯制造有限公司', '沈阳市皇姑区百花山路1-4号', '焦清惠（焦总）13906018339 86118691 86131963', null, '86121743');
INSERT INTO `khxx` VALUES ('100', '沈阳博林特', '沈阳市东陵区东陵路30-2号', '杨恒88616986 11006060691 88616696 88616618              唐行涛 88616918   13019391016', null, '88416420');
INSERT INTO `khxx` VALUES ('101', '沈阳博林特电梯有限公司(新厂区)', '沈阳市经济技术开发区开发大道27#(16号街 博林特电梯) 发票都寄到新厂区', '杨恒11006060691  兰天 31163936  13889399133', null, '21162110');
INSERT INTO `khxx` VALUES ('102', '沈阳正通电梯配件有限公司', '沈阳虎石台经济开发区兴隆街26号', '郑徽13313633333/89913819张工 63331199', null, '89712819');
INSERT INTO `khxx` VALUES ('103', '沈阳市兰菱电梯维修中心', '沈阳市北站路78号邮政大厦转电梯', '何联华13386880608', null, null);
INSERT INTO `khxx` VALUES ('104', '沈阳富士电梯有限公司', '于洪区凌东街153号', '于学光13860331309姜在峰（86891311 86601333 13998181119 传真：86601333）红楼一楼  姜思伦 86601681 13898116833', null, '22733918');
INSERT INTO `khxx` VALUES ('105', '沈阳川菱', '沈阳和平区青年大街386号华阳国际大厦A座D957 发票地址:沈阳市东陵区浑河民族经济技术开发区新立8号', '孙桂芝33180196*33918666总经理刘湛13333669969', null, '23718068*23180196');
INSERT INTO `khxx` VALUES ('106', '沈阳金都饭店', null, '高学鹏13898166099', null, null);
INSERT INTO `khxx` VALUES ('107', '沈阳百越电梯公司', null, '33313969岳13003613306', null, null);
INSERT INTO `khxx` VALUES ('108', '沈阳多维自控技术有限公司', null, '王晓光86396099', null, null);
INSERT INTO `khxx` VALUES ('109', '沈阳元和电梯有限公司', '沈阳市市府大路290号1-11-3摩根凯利', '于志刚13998161069', null, '024-22743922');
INSERT INTO `khxx` VALUES ('110', '沈阳蓝兴电梯公司', null, '张岩13900031199/81869901', null, '86241818');
INSERT INTO `khxx` VALUES ('111', '沈阳东迅电梯有限公司', null, '万经理13898169633/89139891', null, '89139871');
INSERT INTO `khxx` VALUES ('112', '沈阳市菱通电梯服务中心', '沈阳市大东区沈铁路52号5门', '梁昆莉88339119 88096163', null, null);
INSERT INTO `khxx` VALUES ('113', '沈阳新圣亚超硬合金工具有限公司', '沈阳市和平区文化路44号', '马红梅13386836199 33898968', null, null);
INSERT INTO `khxx` VALUES ('114', '沈阳智健精工电梯装饰有限公司', '沈阳市于洪区陵东乡田义村  发货地址：于洪区鸭绿江北街（过二环打电话）', '董仲军13860019810 63609691', null, '024-62609671');
INSERT INTO `khxx` VALUES ('115', '沈阳凤翥楼宇工程有限公司', '发票地址:沈阳市和平区南京南街80号B座1402', '徐红13698868366 33111169', null, null);
INSERT INTO `khxx` VALUES ('116', '辽宁杭奥电梯工程有限公司', '沈阳市皇姑区陵东街83巷10甲号', '肖琦 31303610 发票:于洪耀13998836361', null, null);
INSERT INTO `khxx` VALUES ('117', '辽宁信达电梯有限公司（鑫一达）', '沈阳市皇姑区华山路215号1门4楼财务部', '蒋辉收81191690陈晓龙81819313李长虹13998893999技术吕守彬33939811 13136366333', null, '88072283/78');
INSERT INTO `khxx` VALUES ('118', '辽宁鑫一达电梯有限公司', '沈阳市大东区前进乡大志村', '齐闯88093383张兆旭13806008191', null, '');
INSERT INTO `khxx` VALUES ('119', '沈阳三洋电梯杭州工程有限公司', '杭州市下城区环城北路63号财富中心1703室', '张纯良0191-81863380 13093906019', null, '0171-81863336');
INSERT INTO `khxx` VALUES ('120', '辽宁豪华电梯安装有限公司', '沈阳市和平区西塔北街1号', '高金城11803660606 33691196', null, null);
INSERT INTO `khxx` VALUES ('121', '沈阳汇成电缆集团有限公司', '沈阳市于洪区青海西路41号', null, null, null);
INSERT INTO `khxx` VALUES ('122', '沈阳德信控制设备有限公司', '沈阳市皇姑区陵北街37巷7号', '马丽新036-86313018 13960138086', null, '024-86212018');
INSERT INTO `khxx` VALUES ('123', '沈阳南迅电梯', '沈阳市沈河区北京街19-3号3单元6楼2号', '胡丽民33961911', null, null);
INSERT INTO `khxx` VALUES ('124', '沈阳辽富电梯销售有限公司', null, '于洋13860319966', null, null);
INSERT INTO `khxx` VALUES ('125', '沈阳三洋电梯工程设备有限公司', '沈阳市东北大马路272号', '车金凤13960199010 036-86890636', null, '86908801');
INSERT INTO `khxx` VALUES ('126', '鸿彤园', '大东区204和睦北三路鸿彤园A座3单元9楼', '吴颖 11806060908 11806060896', null, null);
INSERT INTO `khxx` VALUES ('127', '沈阳新力电梯有限公司', '沈阳市皇姑区昆山中路2号18-1', '姜跃权 13306000839', null, null);
INSERT INTO `khxx` VALUES ('128', '辽宁富士袁总', '沈阳市皇姑区银山路59号307室', '王小姐86609618  韩工 13889363133  袁英芳（发票）', null, null);
INSERT INTO `khxx` VALUES ('129', '辽宁富士张总', '沈阳市于洪区银山路59号309室', '张松岩13909839033', null, null);
INSERT INTO `khxx` VALUES ('130', '大连方州电梯工程有限公司', '大连市中山区民生街宏爱巷1号18楼1号', '王洪新', null, null);
INSERT INTO `khxx` VALUES ('131', '大连富士电梯有限公司', '大连市沙河口区连胜街82号城市公园A座1506室', '范本吏13313391199 0611-86133999', null, '0411-84121327');
INSERT INTO `khxx` VALUES ('132', '大连得利电梯制造有限公司', '瓦房店市得利寺镇', '倪云春13963839360', null, '0411-81320028');
INSERT INTO `khxx` VALUES ('133', '大连通用电梯公司(大连正华电梯有限公司)', '中山区大众街9号', '邵力0611-83906309 13906380980                  蒋红敏13961138899                              李树博13863618936  0611-83931330', null, '0411-82704207');
INSERT INTO `khxx` VALUES ('134', '大连顺达电梯有限公司', '沙河口区工华街17号三丰大厦326房', '刘绍亮  13998616098  0611-86899088/89                        刘绍钦83989139', null, '0411-86897088');
INSERT INTO `khxx` VALUES ('135', '大连亨泰机电工程有限公司', '大连沙河口区西南路304号三门栋5楼3号', '王振有13906083613 13333318090 0611-86331333', null, '0411-87681000');
INSERT INTO `khxx` VALUES ('136', '大连力伏特电梯', '大连市沙河口区中山路538号新希望花园物业转电梯公司', '毛珉   0611-86313300   13960833109', null, null);
INSERT INTO `khxx` VALUES ('137', '大连志诚机电设备有限公司', '大连市中山区北斗街98号', '董世涛(经理)13333303896 0611-83983161 83983163', null, '0411-82783160');
INSERT INTO `khxx` VALUES ('138', '大连百菱电梯有限公司', '大连市西岗区鞍山路13号兴业广场B座308室', '王丽0611-83988033', null, null);
INSERT INTO `khxx` VALUES ('139', '大连凯天机电设备有限公司', '大连市甘井子泉水D1区25号2-1-1', '王盛勋 13963661669  0611-86699160', null, '0411-86477160');
INSERT INTO `khxx` VALUES ('140', '丹东三菱电梯销售有限公司', '丹东市振兴区九纬路85号(辽东宾馆)', '王广林13961138811/0611-3168330', null, null);
INSERT INTO `khxx` VALUES ('141', '丹东浩天经贸有限公司', '丹东市元宝区福海小区2号楼4单元209室', '于忠君13306310968 收货:隋志刚13900118699 0611-3883089', null, null);
INSERT INTO `khxx` VALUES ('142', '丹东盛华电梯服务有限公司', '丹东市振兴区体育馆路上域国际608室', '姜元军18861109966', null, '0411-2216212');
INSERT INTO `khxx` VALUES ('143', '丹东安达电梯厂', '丹东市振兴区福春街24号', '张连生13861181136 0611-3863916 收件人:曲衍模', null, '0411-3862713');
INSERT INTO `khxx` VALUES ('144', '鞍山市商业银行(鞍山市永生电梯服务有限公司)', '鞍山市铁东区五一路15号1515室', '邓永生011906130068   0613-3800931', null, '0412-2231794');
INSERT INTO `khxx` VALUES ('145', '鞍山五环酒店', '鞍山市铁西区南胜利路4号', '张辉13106136991', null, null);
INSERT INTO `khxx` VALUES ('146', '抚顺石化自动化系统技贸有限公司', null, '刘建13106339168', null, '0413-2660812');
INSERT INTO `khxx` VALUES ('147', '朝阳辽西沈阳东芝电梯有限公司', '朝阳市和平街60-9号', '皮井国 张庆国13191863991 0631-3398310 0631-3933666', null, '0421/3273666 0421-6688862');
INSERT INTO `khxx` VALUES ('148', '朝阳三菱电梯销售公司', '朝阳大街2段78号 龙腾商厦', '徐振忠0631-3806119徐世军 13188193030', null, '0421-2819111');
INSERT INTO `khxx` VALUES ('149', '营口航天稀土电机有限公司', '营口市高新技术开发区科飞路33号', '何忠意0619-8883993 财务0619-6893193', null, '0417-6669161');
INSERT INTO `khxx` VALUES ('150', '吉林建兴电梯有限公司', '长春晨光国际大厦B座1116室', '谢万锋13119138611/13119131919/0631-88969991', null, '0431-87821717');
INSERT INTO `khxx` VALUES ('151', '吉林市吉特电梯工程处', '吉林市松江中路65号市政府5号楼', '夏云秀   13963399661   0633-3699088', null, null);
INSERT INTO `khxx` VALUES ('152', '延边天禹电梯有限公司', '延吉市长白路6号怡华家园4楼3单元201室', '何英13116638368 0633-3336168', null, '0433-2236178');
INSERT INTO `khxx` VALUES ('153', '长春锐智电梯销售有限公司', '吉林省长春市经济开发区二区8栋102', '马英慧11963013990', null, null);
INSERT INTO `khxx` VALUES ('154', '长春市利达电梯有限公司', '长春二道区吉盛小区2-5栋', '刘江龙13116310111*0631-86919811', null, '0431-86706104.041184317448');
INSERT INTO `khxx` VALUES ('155', '长春市利升快速机电工程有限公司', '南关区卫星广场民航花园4栋3门102室', '肖刚13863136831/0631-81339689', null, '0431-81081184');
INSERT INTO `khxx` VALUES ('156', '吉林省现代电梯工程有限公司', '长春市宽城区白菊路10号白菊时代华庭4单元807室', '李长庆0631-83993899', null, null);
INSERT INTO `khxx` VALUES ('157', '吉林万里购物广场', '金先生13252523555', null, null, '0432-2412388');
INSERT INTO `khxx` VALUES ('158', '四平交通宾馆', '四平市铁西区站前交通大厦', '姜彪13896606139    普通发票', null, null);
INSERT INTO `khxx` VALUES ('159', '长春东日电梯有限公司', '长春市朝阳经济开发区硅谷大街与超强街交汇 西行200米。', '收货人胡鹏飞13966199313/王和忠(技术条件)13866091369/于婧18963631636', null, '0431-87017318');
INSERT INTO `khxx` VALUES ('160', '长春科达电梯工程有限公司', '寄发票地址:长春市普阳街副81号长春市特种设备监督检验中心', '王鹏云13806661638', null, '0431-8736811/7609976于小姐');
INSERT INTO `khxx` VALUES ('161', '四平凯利特电梯有限公司', '四平市铁东区南一委六马路', '赵生辉13636361096', null, null);
INSERT INTO `khxx` VALUES ('162', '吉林省四平电梯制造有限公司', '吉林省四平铁西区迎宾街北段(红嘴开发区)', '赵生辉0636-3301310朱文龙13606368383', null, '0434-3201210');
INSERT INTO `khxx` VALUES ('163', '四平市庆利电梯设备有限公司', '发货地址:长春经济技术开发区金州街1号宏泰宾馆1210室 发票地址:四平众达塑料纺织有限公司四平铁东区长发路1380号', '王雁飞13331608866 弄阳13863661139/0631-86831133', null, '0431-86821133');
INSERT INTO `khxx` VALUES ('164', '吉林百斯特电梯有限公司', '长春市自由大路4848号北方大厦8层', '潘巨春13019101319/0631-1839999韩光13316306991', null, null);
INSERT INTO `khxx` VALUES ('165', '中油吉林销售分公司', '吉林省白山市通江路24号', '邵国山0639-8993990', null, '0439-3214914');
INSERT INTO `khxx` VALUES ('166', '吉林省海神电梯销售服务有限公司', '长春市百草路221号2栋306室', '李建锋13866060311', null, '0431-88942711');
INSERT INTO `khxx` VALUES ('167', '吉林省委(吉林省事务管理局办公用房维修处)', '吉林省委院内577号', '袁铁峰0631-88903911', null, null);
INSERT INTO `khxx` VALUES ('168', '吉林省世博机电设备安装工程有限责任公司', '长春市普阳街2066号中天大厦308室', '钟玉波0631-81086966', null, null);
INSERT INTO `khxx` VALUES ('169', '吉林省三荣电梯工程有限公司', '吉林省长春市皓月大路739号标记大厦A5-1511室', '邓春艳0631-89831133 13196398880', null, '0431-87821133');
INSERT INTO `khxx` VALUES ('170', '长春福达电梯有限公司', '长春市皓月大路739号标记大厦4单元709室', '崔利萍0631-89936633', null, null);
INSERT INTO `khxx` VALUES ('171', '吉林省国土资源开发集团电梯工程有限公司', '发货：吉林省白城市爱国街2号 白城宾馆 发票：长春市经济开发区仙台大街1468号', '刘长青13106690918', null, null);
INSERT INTO `khxx` VALUES ('172', '长春莱茵电梯有限公司', '长春市长江路69号双龙大厦C单元1208室', '马国平0631-86988911', null, '0431-86788733');
INSERT INTO `khxx` VALUES ('173', '吉林省菱电电梯有限公司', '长春市宽城区辽宁路春铁大厦Ｂ座７０４室', '王焱森13366096999/0631-86099339', null, null);
INSERT INTO `khxx` VALUES ('174', '吉林省榆树市交通小区', '吉林省榆树市港榆小区2号楼7单元302', '刘朝春13316396863 0631-83630311', null, null);
INSERT INTO `khxx` VALUES ('175', '吉林市万星物业管理有限公司', '吉林市厦门街高新2号路亲亲家园北区物业办公室', '韩冰11136131611 0633-66669363', null, null);
INSERT INTO `khxx` VALUES ('176', '哈尔滨市东华机电设备有限公司', '哈尔滨市道外区承德街241号', '任伟东 财务:0611-88380119', null, '0411-83397868');
INSERT INTO `khxx` VALUES ('177', '黑龙江九隆科技开发有限公司', '黑龙江省哈尔滨市香坊区香大街167号', '0611-11666088付振海88113099*13103613099', null, '0411-11646088');
INSERT INTO `khxx` VALUES ('178', '齐齐哈尔东林电梯有限公司', '齐齐哈尔市站前大街206号（齐铁电务段）', '康秀东13100830916。发票：林玉坤13996898316', null, '0412-8061710');
INSERT INTO `khxx` VALUES ('179', '齐齐哈尔建华电梯有限公司', '齐齐哈尔市双华路1号', '13009913999*陈守君3611369', null, '0412-2614746');
INSERT INTO `khxx` VALUES ('180', '哈尔滨莱茵电梯有限公司', '哈尔滨市香坊区哈成路323号', '0611-83010931-861郝绩业83011918齐海1381866991崔经理13009908638代志刚13996008009', null, '0411-82011104');
INSERT INTO `khxx` VALUES ('181', '哈尔滨东方电梯安装工程处', null, '杜福臣13306803308', null, '0411-86229122');
INSERT INTO `khxx` VALUES ('182', '哈尔滨市东北电梯经销有限责任公司', '哈尔滨市道里区钢铁街1号楼', '韩金池0611-86811311', null, '0411-84811822');
INSERT INTO `khxx` VALUES ('183', '哈尔滨市恒益电梯厂', '南岗区哈西大街109号', '崔岳明厂长13906101366 0611-86663638           孙琪86663638/86693639 13903636163', null, '0411-86692429');
INSERT INTO `khxx` VALUES ('184', '哈尔滨中兆迪康电梯制造有限公司', '哈尔滨香坊区中山路162-1号迪康财富大厦7楼', '关春生0611-11198966/13966808991', null, '0411-11198901');
INSERT INTO `khxx` VALUES ('185', '哈尔滨赫力电梯设备经销有限公司', '哈尔滨南岗区赣水路1号齐鲁大厦811', '赵丽君0611-86369636', null, '0411-82628180');
INSERT INTO `khxx` VALUES ('186', '哈尔滨天鹅电梯安装维修有限公司', '哈尔滨市南岗区东大直街151号', '杜万钧0611-83386630 /0611-89130930  王玉珉 13906803910 齐纯德13861066063 刘连英  13906613330', null, '0411-87130630/82286410');
INSERT INTO `khxx` VALUES ('187', '黑龙江省西奥电梯经销有限公司', '哈尔滨市香坊区香坊大街167号', '范彦彬13030018911彬有礼 0611-89931119/11660338', null, null);
INSERT INTO `khxx` VALUES ('188', '黑龙江电梯厂', '哈尔滨市香坊区巴安里街18号', 'EMS 侯权贵 13966839661 0611-83969968  王颜国18666363613', null, '0411-82949768');
INSERT INTO `khxx` VALUES ('189', '哈尔滨上菱电梯有限公司', null, '徐拥军', null, null);
INSERT INTO `khxx` VALUES ('190', '哈尔滨西奥电梯公司', '南岗区花园街201号', '0611-13636081冯驰139366699960611-83013939池学权13319118198丁立农0611-86968981', null, '0411-13626081');
INSERT INTO `khxx` VALUES ('191', '哈尔滨达鑫电梯有限公司', '哈尔滨市南岗区五瑞街10号', '李忠0611-86339966/88618018 霍焱0611-86339966/13696118308', null, '0411-86268604');
INSERT INTO `khxx` VALUES ('192', '黑龙江省利通电梯工程有限公司', null, null, null, '0411-13622478');
INSERT INTO `khxx` VALUES ('193', '哈尔滨铁梁电梯有限公司', '哈尔滨市南岗区汉广街41号', '13906103306张铁梁0611-86336639 86309986       徐宝琴13966033383李秀森13961699136', null, '0411-86372232');
INSERT INTO `khxx` VALUES ('194', '哈尔滨市日广电梯经销有限公司', '哈尔滨市道里区新阳路欧洲新城白D3-1-1', '董经理13836006388      0611-86838989', null, ' 0411-84828989');
INSERT INTO `khxx` VALUES ('195', '哈尔滨市天华(通昆)电梯有限公司', '哈尔滨市南岗区花园街304号恒运大厦B座2703室', '魏经理0611-13633093王晓丹', null, '0411-13634036');
INSERT INTO `khxx` VALUES ('196', '哈尔滨广日电梯有限公司', '哈尔滨市道里区买卖街105号太阳大厦2506', '吴崇 13996008313 0611-86196083', null, '0411-84194106');
INSERT INTO `khxx` VALUES ('197', '佳木斯新恒通电梯有限公司', '佳木斯友谊路110号', '荆加俊13836663001 0616-8196861李峰', null, null);
INSERT INTO `khxx` VALUES ('198', '黑龙江省力通电梯工程有限公司', '黑龙江省哈尔滨市香坊区和平路66号哈尔国际A座25层', '王继生13606106101 0611-13633698 王小姐', null, '0411-13622478');
INSERT INTO `khxx` VALUES ('199', '黑龙江福菱电梯设备有限公司', '哈尔滨市开发区轩辕东路22-4号盟科时代D栋3单元202室', '王福莹0611-83338666', null, '0411-13612217');
INSERT INTO `khxx` VALUES ('200', '绥化市至诚通用电梯服务有限公司', '黑龙江省绥化市祥和西街和谐嘉园G栋商服26号', '李加明0611-8399999', null, null);
INSERT INTO `khxx` VALUES ('201', '牡丹江万达电梯工程有限公司', '牡丹江市爱民区西祥伦街73号', '王卓艳13836366180  0613-6196966 8618133', null, '0413-6196966');
INSERT INTO `khxx` VALUES ('202', '大庆庆懋电梯机电工程有限公司', '大庆高新技术产业开发区', '于同彪13906193311', null, '0419-4667111');
INSERT INTO `khxx` VALUES ('203', '大庆永惠电梯有限公司', '大庆市萨尔图区东风新村纬二路', '赵怀军11006191398', null, '0419-6383037');
INSERT INTO `khxx` VALUES ('204', '哈尔滨友顺电梯工程有限公司', '哈尔滨市南岗区平准街59号', '杨麟13633611186', null, null);
INSERT INTO `khxx` VALUES ('205', '哈尔滨市永达电梯工程有限公司', '发票:哈尔滨市红旗大街289号龙', '夏维强13606880863 0611-89000811', null, '0411-87000833');
INSERT INTO `khxx` VALUES ('206', '鸿运物业', '哈尔滨市南岗区阿什河街10号恒运大厦C座物业管理部', '栗平13936663131', null, '0411-13632048');
INSERT INTO `khxx` VALUES ('207', '哈尔滨中美电梯公司', '哈尔滨南岗区木工街5号振轩电梯配件公司', '柴成涛13891989186', null, null);
INSERT INTO `khxx` VALUES ('208', '哈尔滨中美电梯公司大庆分公司', '大庆市东风新村百脑汇', '刘晓峰13806696311', null, null);
INSERT INTO `khxx` VALUES ('209', '李秀森13945699126', '哈尔滨市道里区友谊路392号远东大厦411室', '李琪13319866699', null, null);
INSERT INTO `khxx` VALUES ('210', '哈尔滨市教育局职教中心', '哈尔滨市南岗区学府路52号', '公利斌   13861061810', null, null);
INSERT INTO `khxx` VALUES ('211', '齐齐哈尔市杭奥电梯安装维修有限责任公司', '齐齐哈尔市龙沙区通达街青云小区综合楼', '孙辉13906616606 0613-3693638', null, '0412-2473638');
INSERT INTO `khxx` VALUES ('212', '齐齐哈尔医学院第一附属医院', '齐齐哈尔市富拉尔基向阳大街26号', '李华0613-6891963/13906133668', null, null);
INSERT INTO `khxx` VALUES ('213', '齐齐哈尔动力电梯销售有限公司', '齐齐哈尔站前大厅206号（齐铁电务段）', '林玉坤13996898316 11366616633', null, null);
INSERT INTO `khxx` VALUES ('214', '黑龙江海神电梯销售有限公司', '黑龙江省哈尔滨市南岗区海关街182号沪士大厦17F座', '刘晶11806636300', null, '0411-87131122');
INSERT INTO `khxx` VALUES ('215', '哈尔滨长江电梯安装有限公司', '哈尔滨市南岗区下夹树街144号', '李守梁 13836139930 0611-86330399', null, null);
INSERT INTO `khxx` VALUES ('216', '山东齐鲁味精集团', '山东仕平县山东齐鲁味精集团', '刘忠13969131118', null, null);
INSERT INTO `khxx` VALUES ('217', '山东高斯达电梯有限公司', '山东省章丘市辛寨乡辛中村13号 (副板)上海发货地址:上海基扬发货地址：上海松江区车墩镇回业路19号C1座 鲍继武   021-57602595', '纪荣彬0131-83161099 13116661989 发票EMS', null, '0131-83141079');
INSERT INTO `khxx` VALUES ('218', '山东百斯特电梯有限公司', '山东省济南市天桥区清河路57号', '孙安军(自动化)13189066611宋钦才(驱动)13969138383 0131-81900888-130 （副板发上海贝斯特 杨晓珍收）', null, '0131-81930168');
INSERT INTO `khxx` VALUES ('219', '山东德州百货大楼(集团)有限责任公司', '德州市德城区湖滨中大道118号德百写字楼16楼德百电梯维修科', '李书山0136-3693199 13189906911', null, '0134-2624960');
INSERT INTO `khxx` VALUES ('220', '青岛裕兴达东芝电梯工程有限公司', '青岛市市北区台东二路26号', '王财业   13301331161', null, null);
INSERT INTO `khxx` VALUES ('221', '青岛科达电梯有限公司', '青岛市市北区长山路52号甲', '潘淋淋13906399111', null, '0132-83820187');
INSERT INTO `khxx` VALUES ('222', '青岛德奥电梯有限公司', '青岛市李沧区金水路1057#26#-2单元-202室', '黄曙光13391189988 0133-89616199', null, null);
INSERT INTO `khxx` VALUES ('223', '山东东达电梯有限公司', '山东省济宁市中区开发区深圳西路', '党德亮13696390688 0139-3639988 3639666 3619888', null, '0137-2619896');
INSERT INTO `khxx` VALUES ('224', '淄博新世纪电梯工程有限公司', '淄博市金星大道299号 三玉生活区27-2号', '刘爱国13108913330/0133-3918988 3916000', null, '0133-3917111');
INSERT INTO `khxx` VALUES ('225', '淄博长城电梯工程有限公司', '淄博市开发区政通路145号', '刘爱宝13108913330/0133-6389333', null, '0133-6287322');
INSERT INTO `khxx` VALUES ('226', '威海云峰电梯有限公司', '山东省威海市顺河街220-5号  工厂地址：山东省荣成市港西镇海都热电厂西侧  杨玉强：13656309215', '0631-1866918李经理：13869068193  杨玉强：13616309311', null, null);
INSERT INTO `khxx` VALUES ('227', '东芝电梯（沈阳）有限公司青岛分公司', '青岛市市南区汇泉路17号东海国际大厦E-301室', '张德华13993660333 0133-83888311', null, null);
INSERT INTO `khxx` VALUES ('228', '海科电梯（富士工业（青岛）电梯制造有限公司）', '青岛李沧区李沧工业园内', '0133-89603311张健13618669309 0133-89606369于涛0133-83903303', null, '0132-87602177');
INSERT INTO `khxx` VALUES ('229', '青岛建秋电梯有限公司（博格）', '青岛胶州市胶州湾工业园二区8号路东段', '栾正武0133-81133383..13116896080', null, '0132-81123386');
INSERT INTO `khxx` VALUES ('230', '烟台', null, '赵静0131-6611109', null, '0131-6231278');
INSERT INTO `khxx` VALUES ('231', '淄博东屹工贸有限公司', '山东省淄博市张店区西二路200号', '张东13001109916 0133-6389369', null, '0133-6289269');
INSERT INTO `khxx` VALUES ('232', '上海莱普青岛分公司', null, '姜卫丰0133-83806116', null, '0132-82806116');
INSERT INTO `khxx` VALUES ('233', '临沂市兰山区兴华机电仪表站', '临沂市通达路327号', '朱学印13801391393 0139-8119801', null, null);
INSERT INTO `khxx` VALUES ('234', '临沂市胜军自动化设备有限公司', '山东省临沂市临西一路银宝机械市场北区二楼', '和湘胜13608990669/0139-9169396', null, '0139-7161276');
INSERT INTO `khxx` VALUES ('235', '临沂鑫达电梯公司', '临沂市兰山区腊庙街', '朱陆海13813936811', null, null);
INSERT INTO `khxx` VALUES ('236', '临沂电梯有限公司', '山东省临沂市金四路与中丘路交汇处埠东小区南院十号楼407室', '牛福然0139-3961118 13108996606', null, null);
INSERT INTO `khxx` VALUES ('237', '青岛称自达电梯有限公司', '青岛市市南区香港中路5号中国纺织工人疗养院光荣楼415室', '刘孟祥13310690638', null, null);
INSERT INTO `khxx` VALUES ('238', '青岛乘自达电梯有限公司', '青岛市香港中路5号工人纺织疗养院光荣楼215室', '尹莉11318969698 13391630998', null, '0132-83866212');
INSERT INTO `khxx` VALUES ('239', '青岛菱工电梯工程有限公司', '青岛市山东路52号华嘉大厦1307室', '徐丽0133-81013030', null, '0132-81013326');
INSERT INTO `khxx` VALUES ('240', '青岛富士田电梯销售有限公司', '发票:青岛山东路177号鲁邦广场B-508室 交货地址:青岛市四方区人民路99号2单元401室', '发票:于慧13061338000 高先成13386399003 于立明13386399009;0133-83999691/91 王凤', null, '0132-83717914');
INSERT INTO `khxx` VALUES ('241', '青岛富佳电梯有限公司', '青岛市山东路177号鲁邦广场B-508室   发货地址：山东省青岛市李沧区李村北崂路  收', '高先成  电话：13386399003发票：于慧13061338000', null, '0132-80931836');
INSERT INTO `khxx` VALUES ('242', '烟台鲁建电梯有限公司', '烟台市芝罘区向阳133-2号', '梁13606383838 姜敏0131-6636819', null, '0131-6624801');
INSERT INTO `khxx` VALUES ('243', '烟台迅菱奥', null, '0131-3133966', null, null);
INSERT INTO `khxx` VALUES ('244', '泰安市顺兴电梯有限公司 (货发泰山站)', '山东省泰安市望岳宾馆南楼106室', '马卫忠0138-8319690（兼传真）  13013833600赵建荣13003990110', null, null);
INSERT INTO `khxx` VALUES ('245', '烟台博汇电梯科技有限公司', '山东省烟台市建设路71号412室', '郝小燕 3991990 13396381163', null, null);
INSERT INTO `khxx` VALUES ('246', '济宁锐通电梯有限公司', '山东省济宁市环城西路13-3号', '陈民丰13601699399 0139-3318366 0139-3669399', null, '0137-2669399');
INSERT INTO `khxx` VALUES ('247', '山东济宁康达电梯公司', '收货:山东兖州共青团路邮政局宿舍2号楼303室 发票地址:山东省济宁市建设北路126号(劳务开发公司院内)', '收货:刘淑娟13608911930 0139-3611619收发票:徐保民13813963809', null, null);
INSERT INTO `khxx` VALUES ('248', '济宁百斯特电梯有限公司', '济宁市建设路锦都商务中心419室', '荣建设0139-3900918', null, '0137-2900728');
INSERT INTO `khxx` VALUES ('249', '山东三洋输送机械有限公司', '山东省齐河县经济开发区名嘉西路7号', '刘佳18913661300/0136-1039688', null, '0137-1027688');
INSERT INTO `khxx` VALUES ('250', '德州诺亚威特电梯有限公司', '山东省德州市东方红路24号市委招待所4楼', '张兰西11961363899', null, null);
INSERT INTO `khxx` VALUES ('251', '德州市百斯特电梯服务中心', '山东省德州市解放北路2号', '杨文彬0136-3698338 13611363116', null, null);
INSERT INTO `khxx` VALUES ('252', '德州市场天衢路棉麻公司', '山东省德州市天衢路1336号102室', '盖书永0136-3361889', null, null);
INSERT INTO `khxx` VALUES ('253', '潍坊快速美奥电梯有限公司', '山东省安丘市北区汶水路', '高冰18663609819', null, '0136-4398070');
INSERT INTO `khxx` VALUES ('254', '济南迅达电梯有限公司', '山东省济南市槐荫区振兴中街6-1号', '王敏13813198818 0131-89183916', null, null);
INSERT INTO `khxx` VALUES ('255', '济南孚典实业发展有限公司', '济南市历下区燕子山路2-2号燕翔大厦458室', '许彤生0131-88190099', null, null);
INSERT INTO `khxx` VALUES ('256', '潍坊奥潍电梯安装有限公司（山东三元）', '山东省潍坊市民生东街63号(市教委对面)', '卢洪泉13806661966 0136-8993331', null, '0136-8792331');
INSERT INTO `khxx` VALUES ('257', '潍坊世纪美联百货有限公司', '山东省潍坊市昌乐县城区', '吴继伟 0136-6313088 11613689399', null, null);
INSERT INTO `khxx` VALUES ('258', '王兴民', '山东省泰安市泰山区迎春小区68号楼一单元601室', '王兴民13183819363', null, null);
INSERT INTO `khxx` VALUES ('259', '潍坊菱业电梯有限公司', '潍坊市健康西街135号向阳大厦706室', '许晓娟0136-8383030', null, '0136-8317230');
INSERT INTO `khxx` VALUES ('260', '济南槐荫正利电梯配件维修处', '沈阳', '黄学全0131-89181099 13813193803', null, null);
INSERT INTO `khxx` VALUES ('261', '济南雪莲实业有限公司', '山东省济南市市中区英雄山路20号保健品批发市场', '侯广勇13913166398', null, null);
INSERT INTO `khxx` VALUES ('262', '淄博兴国设备安装有限公司', '山东省淄博市张店区洪沟路东首店子村', '范锋0133-3069811', null, null);
INSERT INTO `khxx` VALUES ('263', '山东博尔特', '山东省德州市宁津县银河经济开发区', '张景新11166916899', null, null);
INSERT INTO `khxx` VALUES ('264', '秦皇岛奥跃机械设备有限公司', '秦皇岛市山海关经济技术开发区上海西路27-7', '刘海涛1363338398/13191913393/0331-1089816', null, '0331-1080100');
INSERT INTO `khxx` VALUES ('265', '青岛润东', '青岛市南区香港中路6号世贸中心B座1702室。', '尹丽丽11318969698  唐方坤0136-1819111', null, '0134-1819111');
INSERT INTO `khxx` VALUES ('266', '青岛海亿通电梯有限公司', '山东省青岛市经济技术开发区江山南路377号楼1单元102室', '万国民 13316898911 0133-86808868', null, null);
INSERT INTO `khxx` VALUES ('267', '山东富士制御电梯', '山东省宁津县经济开发区泰山路南首', '张真真 11066631111  刘金凯11066610186   0136-1819111', null, '0134-1819111');
INSERT INTO `khxx` VALUES ('268', '山东奔速电梯', '山东省济南市高新区天辰路667号', '刘振涛', null, '0134-1819116');
INSERT INTO `khxx` VALUES ('269', '山东莱茵艾佳电梯有限公司', '山东省宁津县开发区泰山路南首', '梁斌18013609899', null, '0134-1819117');
INSERT INTO `khxx` VALUES ('270', '青岛建信电梯工程有限公司', '青岛市李沧区黑龙江中路2688号6号楼1单元601户', '冷建冰13316889893', null, null);
INSERT INTO `khxx` VALUES ('271', '唐山开滦建设集团有限责任公司', '唐山市路北区新华东道57号（开滦医院总务科）  唐山市路北区果园乡刘火新庄西', '郑凯13186919919 韩光群13930139696 吕长义11111968619 0311-3316988', null, null);
INSERT INTO `khxx` VALUES ('272', '唐山金维电梯机电有限公司', '唐山龙泽北路425号大陆阳光101楼12层', '周维民0311-3160101/3160111张树艳13633308601', null, '0311-83096022');
INSERT INTO `khxx` VALUES ('273', '华北制药奥奇德药业有限公司', '石家庄经济技术开发区扬子路18号', '张翔0311-83096033', null, '0311-86302118');
INSERT INTO `khxx` VALUES ('274', '石家庄市石菱电梯服务中心', '石家庄市中山东路126号 凯嘉大厦4A01', '蒋锡春0311-86039903 13603111318', null, '0311-87281182');
INSERT INTO `khxx` VALUES ('275', '河北格瑞特电力设备有限公司', '石家庄市建设北大街223号中浩11A', '赵光宇311-89381183', null, '0311-87022188');
INSERT INTO `khxx` VALUES ('276', '河北辽富电梯有限公司', '石家庄裕华西路166号联邦名都A座3203', '薛丽娜   13693136918 宋方奎0311-89883000/89033188/13933863366', null, '0311-86994461');
INSERT INTO `khxx` VALUES ('277', '石家庄市军创电梯安装维修服务中心', '石家庄市胜利北大街185号颐馨商务公寓6楼', '白静 0311-86031896', null, null);
INSERT INTO `khxx` VALUES ('278', '河北百斯特电梯服务中心', '石家庄市平安南大街14号6楼', '魏海政13693969330', null, '0311-7822192');
INSERT INTO `khxx` VALUES ('279', '石家庄冀铁昌华电梯有限公司', '石家庄市水源街89号冀铁集团603室', '罗平0311-89839166 13311189969 李广13931168113', null, '0311-87823916');
INSERT INTO `khxx` VALUES ('280', '石家庄冀铁昌华电梯有限公司', '石家庄市新华路100号', '高慧英 13933106306', null, null);
INSERT INTO `khxx` VALUES ('281', '沧州市宏达电梯有限公司', '河北省沧州市眼科医院东侧楼3单元301室', '传真/电话：0319-1303993 王凯立13013031081', null, '0311-81206111');
INSERT INTO `khxx` VALUES ('282', '石家庄星玛电梯有限公司', '石家庄康乐街14号祥源大厦1306室', '刘有倩0311-81306111', null, '孟庆波0319-2617806 13831910101');
INSERT INTO `khxx` VALUES ('283', '邢台市三环电梯有限责任公司', '邢台市桥西区北外环路邢台三环院内', '张丙须 13903391911 0319-3369113王敏', null, '0319-3060821');
INSERT INTO `khxx` VALUES ('284', '邢台安顺电梯安装有限公司', '邢台开发区英华大街英华学校对面', '郝立国13833961931', null, '0319-3191008');
INSERT INTO `khxx` VALUES ('285', '邢台金达电梯工程有限公司', '河北省邢台市新兴东大街186号', '苑文新0319-3191008', null, '0319-1912833');
INSERT INTO `khxx` VALUES ('286', '邢台市邢环电梯有限公司', '邢台市桥西区郭守敬大道2940号', '张军国 13831916668', null, '0319-2617806');
INSERT INTO `khxx` VALUES ('287', '唐山中迅电梯楼宇设备有限公司', '河北省唐山市路北区北新西道玫瑰庄园4单元1302室', '吴海燕(13013381313)', null, null);
INSERT INTO `khxx` VALUES ('288', '东方大学城公安分局', '河北省廊坊市东方大学城公安分局', '李', null, '0316-1906193');
INSERT INTO `khxx` VALUES ('289', '廊坊柏纳控制新技术有限公司', '河北省廊坊市金光道61号', '刘景辉0316-3969113', null, '0319-2120119');
INSERT INTO `khxx` VALUES ('290', '邢台辰光电梯有限责任公司', '河北省邢台市中兴西大街319号', '彭翠珍0319-3130183 13831969339', null, '0317-3191202');
INSERT INTO `khxx` VALUES ('291', '沧州市奥菱电梯有限公司', '河北省沧州市北环路嘉福园小区2-1-202', '吕增通  11833999360', null, null);
INSERT INTO `khxx` VALUES ('292', '高虹(苏州东方电梯有限公司)', '吴江市临沪经济区北厍工业园', '汝华0113-63368866', null, '0311-81687988');
INSERT INTO `khxx` VALUES ('293', '河北欧绅电气有限公司', '石家庄市开发区黄河大道105号九州科技楼319室', '采购0311-81681988 81689988', null, null);
INSERT INTO `khxx` VALUES ('294', '邯郸市长林电梯有限公司', '邯郸市丛台区常壹巷3号楼2单元4号', '张维芳13903309639', null, null);
INSERT INTO `khxx` VALUES ('295', '唐山丰润颢明机械安装维修有限公司', '唐山市丰润区丰韩路', '于靖11133139300 0311-1183316', null, null);
INSERT INTO `khxx` VALUES ('296', '衡水重工电梯起重设备有限公司', '河北省衡水市和平中路与中兴街交叉口 如家宾馆2楼', '郭会荣13363306199', null, null);
INSERT INTO `khxx` VALUES ('297', '曲阳光大机电有限公司', '河北省保定市高新区同美酒店B座115、116', '马海英0313-1919189', null, null);
INSERT INTO `khxx` VALUES ('298', '唐山杭奥电梯有限公司', '唐山市大里路68号', '居崇11096163063', null, null);
INSERT INTO `khxx` VALUES ('299', '唐国春', '石家庄市西里街76号5-303', '唐国春13833168139', null, '0319-2121933');
INSERT INTO `khxx` VALUES ('300', '邢台圣柯达电梯有限公司', '邢台市桥西区中华大街398#锦绣中华园物业公司二层1#', '王艳0319-3131933  11131369111', null, '0311-6631011');
INSERT INTO `khxx` VALUES ('301', '廊坊市赛孚电梯', '河北省 廊坊市 安次区仇庄建设工业园 东方国立院内', '王冬梅电话：0316-3196889手机：1383163019918603331310李海风18603331310', null, null);
INSERT INTO `khxx` VALUES ('302', '石家庄中迅', '河北省石家庄市中华南大街473号居然商务中心501室', '张工 13933081931', null, null);
INSERT INTO `khxx` VALUES ('303', '东莞西门子山西分公司', '太原市兴华北街15号金座公寓', '曾祥云 0311-6610888 13666833386', null, null);
INSERT INTO `khxx` VALUES ('304', '太原市津典电梯有限公司', '山西省太原市平阳路1号金茂国际数码中心B座25楼', '张效生13916800109 0311-6193933', null, '0311-6199822');
INSERT INTO `khxx` VALUES ('305', '太原市景山房屋设备有限公司', '太原市后王南街2号603室', '郭锦13831181113', null, null);
INSERT INTO `khxx` VALUES ('306', '太原市新星商贸有限公司', '太原市解放路66号', '常建明0311-6168698/6063098*13803613903', null, '7010421');
INSERT INTO `khxx` VALUES ('307', '山西立安电梯技术有限公司配件供应部', '太原市山西大学28楼4-401', '张保军13936306810', null, null);
INSERT INTO `khxx` VALUES ('308', '慧远达电梯有限公司', '太原市杏花岭区经园路374号五龙湾阳光海岸阳光区七号路305', '张什产 0311-6663088（兼传真） 米兰13936633096', null, '0311-7189726');
INSERT INTO `khxx` VALUES ('309', '山西沈东电梯营销有限公司', '太原市亲贤北街42号西八楼', '姬贵文经理0311-9189931/13903669113  13803693830苏智军13803693119', null, '0311-6061818');
INSERT INTO `khxx` VALUES ('310', '太原市世翔电梯制造有限公司', '太原市和平南路小井峪街26号', '孙经理0311-6061989', null, '0311-7189726');
INSERT INTO `khxx` VALUES ('311', '太原市通富电梯营销有限公司', '太原市亲贤北街148号', '姬高文13903669113   0311-9188366/9189939', null, '0310-3040881');
INSERT INTO `khxx` VALUES ('312', '忻州忻鑫电梯有限公司', '忻州市七一北路学府街北苑', '曹毅平 李彩俊   13931030891 0310-3060881', null, null);
INSERT INTO `khxx` VALUES ('313', '山西省忻州市建设北路1号广播电视局', '山西省忻州市建设北路1号', '杨玉峰   0310-3801999   13931013889', null, '0311-3126119');
INSERT INTO `khxx` VALUES ('314', '太原邦尼电梯工程有限公司', '山西省太原市五一路225号唐久大厦420室', '马邦虎13836316666', null, null);
INSERT INTO `khxx` VALUES ('315', '山西瑞莱博电梯服务有限公司', '山西省太原市金刚堰路68号捷利大厦508', '徐峰13603163366 0311-3311966', null, null);
INSERT INTO `khxx` VALUES ('316', '太原市富士电梯销售有限公司', '太原市府西街12号', '李勇胜13093100869  黄路珍13109931080', null, 'FAX：0471-6287184');
INSERT INTO `khxx` VALUES ('317', '苏州富佳恩科电梯有限公司太原分公司', '太原市学府街高新区科技街北美晶域蓝湾FB座1003号/太原市高新区产业路39号34楼1单元201号', '韩建胜 13996363666  0311-9033186', null, null);
INSERT INTO `khxx` VALUES ('318', '内蒙古中升实业有限公司', '内蒙古呼和浩特市中山路23号', '栗勇0691-6368330、13969198993张亚凤6399696', null, null);
INSERT INTO `khxx` VALUES ('319', '呼伦贝尔市恒达电梯销售有限责任公司', '内蒙古呼伦贝尔市海拉尔区伊敏大街26号', '王哲荣13868098116', null, null);
INSERT INTO `khxx` VALUES ('320', '内蒙古黎明电梯经销安装维修有限责任公司', '内蒙古呼和浩特市新城区海东路丽苑小区16号楼1单元102室', '武黎明13906913600 、0691-6191606', null, null);
INSERT INTO `khxx` VALUES ('321', '内蒙古帝亚杰电梯有限公司', '内蒙古呼和浩特市新城南街奈伦大厦三楼', '高吉祥13968816193/0691-3368388', null, '0474-3207444');
INSERT INTO `khxx` VALUES ('322', '内蒙古凯帝斯电梯制造有限公司', '内蒙古丰镇市轻工业科技园', '乔国富13936969183', null, null);
INSERT INTO `khxx` VALUES ('323', '包头市捷安电梯自动化有限责任公司', '内蒙古省包头市昆区青年路6号街坊8栋51号', '李晓春13868339689', null, null);
INSERT INTO `khxx` VALUES ('324', '内蒙古菱工电梯有限公司', '内蒙古呼和浩特市赛罕区昭乌达路山丹街商检小区4-2-202', '王琴 0696-6363813 13616916100', null, null);
INSERT INTO `khxx` VALUES ('325', '内蒙古精工电梯股份有限公司', '内蒙古包头市九原区兴胜经济开发区', '贺培基13868316131', null, null);
INSERT INTO `khxx` VALUES ('326', '洛阳益成电梯', '洛阳市凯旋东路60号', '马翠荣13838816333 0399-63313110', null, null);
INSERT INTO `khxx` VALUES ('327', '河北上海三菱', '石家庄市裕华西路67号', '范淑萍13081003396', null, null);
INSERT INTO `khxx` VALUES ('328', '哈尔滨南方', '哈尔滨中山路166号512室', '李秋晶0611-83613818', null, null);
INSERT INTO `khxx` VALUES ('329', '天津鑫宝龙', '天津市西青区杨柳青镇柳口路与津静公路交口西侧精成路', '赵新祥189030313630', null, null);
INSERT INTO `khxx` VALUES ('330', '沈阳新程', null, '程林13998866198 11803639999', null, null);
INSERT INTO `khxx` VALUES ('331', '长春奥利夫', '发票地址：长春市西安大路2389号七楼；发货地址：吉林省公主岭市怀德镇双榆树村街道奥利夫电梯有限公司一分厂', '马洪良13396696198', null, '0434-6110113-8000');
INSERT INTO `khxx` VALUES ('332', '上海三洋', '上海市南汇区新场坦直工业区古丹路26号', '蒋林031-38011396-8103/牛建新（技术）031-38011366-8011', null, null);
INSERT INTO `khxx` VALUES ('333', '北京顺迅', '北京市顺义区怡馨家园29号楼201室', '郑敬敏13911131639', null, null);
INSERT INTO `khxx` VALUES ('334', '中船重工', '沈阳市和平区浑河民族开发区民旺路18号辽海机械厂院内', '郝新民13960066938 张宗岱11960191619', null, null);
INSERT INTO `khxx` VALUES ('335', '辽宁科瑞特电梯有限公司', '沈阳市皇姑区鸭绿江街198-26号', '曹金州13860303398/036-86690991', null, '024-86670771');
INSERT INTO `khxx` VALUES ('336', '北京海迅进出口有限公司', '北京市丰台区马家堡西路15号时代风帆大厦1-2206室', '冯娜13661013103/010-89969933-8308', null, '010-87747978');
INSERT INTO `khxx` VALUES ('337', '辽宁富士电梯有限公司', '皇姑区崇山东路鸭绿江街49号', '杨永帅13998313010', null, '86617044');
INSERT INTO `khxx` VALUES ('338', '沈阳三洋电梯有限公司', '沈阳市大东区东北大马路272号', '张舫13889800093', null, '88093432');
INSERT INTO `khxx` VALUES ('339', '浙江韦伯', '浙江省湖州市南浔经济开发区东翔同辛村', '郑婵0193-3993983', null, null);
INSERT INTO `khxx` VALUES ('340', '怡达快速', '湖州市南浔318国道北侧（经济开发区1号门）', '技术 0193-3063339方工0193-3063338/3060896沈钰 周祝华 手机 13919063061  座机电话0193-3060896   滕梁：0193-3063331', null, null);
INSERT INTO `khxx` VALUES ('341', '恒达富士', '浙江湖州南浔镇人瑞西路南侧', '张振华13906936618    0193-3610303/3061303小何    张振华0193-3061883/13906936618', null, null);
INSERT INTO `khxx` VALUES ('342', '浙江南奥', '浙江湖州市南浔经济开发区强华路6号', '沈小弟：18901931960  0193-3809030 3809010 潘女士：0193-3809030   13969396636', null, null);
INSERT INTO `khxx` VALUES ('343', '浙江联合', '浙江湖州市南洵经济开发区织洵大道68号', '张利华:0193-3989331 陆利英:0193-3919390', null, null);
INSERT INTO `khxx` VALUES ('344', '苏州帝奥', '吴江市震泽镇八都太湖大道', '\n小王：座机现改为0113-63991396', null, null);
INSERT INTO `khxx` VALUES ('345', '苏州菱怡电梯', '苏州吴江市震泽大船港开发区大道', '俞吴新：13969383066/0113-63988838', null, null);
INSERT INTO `khxx` VALUES ('346', '巨人通力', '浙江省湖州市南浔经济开发区织浔大道88号', '吴洁：11088366916  0193-3989998 0193-3989836 11088366916 沈焰月：0193-3989098  徐惠鑫：0193-3989098', null, null);
INSERT INTO `khxx` VALUES ('347', '湖州南浔电气', '浙江省湖州市南浔镇压同心路晶典花苑四幢二单元302', '钱建强13169369881', null, null);
INSERT INTO `khxx` VALUES ('348', '浙江屹立', '浙江省湖州市南浔经济开发区综园路8号', '洪月仙0193-3013011/3998011/何伟芳3999313', null, null);
INSERT INTO `khxx` VALUES ('349', '苏州法奥', '江苏省吴江震泽镇镇西开发区 朱家浜村', '张红13169996111倪总 0113-63988918-8088 :0113-63988931吕剑名                         自动化采购 张红 18363199093     0113-66988136\n驱动采购     贝月秋 18363199093  0113-63988680', null, null);
INSERT INTO `khxx` VALUES ('350', '沃克斯中国电梯', '浙江南浔科技工业园区西泰路8号', '刘斌：11088330939  传真：86-193-3019931 电话：86-193-3099311  宋丽娟：0193-3019901  王英：0193-3010338', null, null);
INSERT INTO `khxx` VALUES ('351', '苏州通用', '江苏省吴江市七都镇港东开发区', '13906311603 孙海荣 0113-63818169', null, null);
INSERT INTO `khxx` VALUES ('352', '苏州迪欧达改名头 （波士顿电梯（苏州）有限公司）', '吴江桃源梵香工业区', '13919311669虞成0113-63866331', null, null);
INSERT INTO `khxx` VALUES ('353', '浙江快奥', '浙江省湖州市南浔经济开发区丁家港东村', ' 李小姐 13169333663严金礼  电话：0193-3061611', null, null);
INSERT INTO `khxx` VALUES ('354', '苏州克莱斯', '吴江市七都镇临浙经济区', '崔建华0113-63833066', null, null);
INSERT INTO `khxx` VALUES ('355', '湖州安灵', '浙江省湖州市南浔经济开发区1区2号路(东段)', '李建根0193-3060313/3808638/13901931001', null, null);
INSERT INTO `khxx` VALUES ('356', '苏州富士佳', '苏州市吴江桃源梵香工业区', '严友法:0113-63868088 小倪:0113-63960631/13863109301', null, null);
INSERT INTO `khxx` VALUES ('357', '湖州中菱', '浙江南浔开发区工业园区适园西路1688号', '张绍有13189396639/0193-3030900', null, null);
INSERT INTO `khxx` VALUES ('358', '浙江巨奥', '湖州市南浔镇横三路128号\n王勇新   13905721962', 'TEL：0193-3013888', null, null);
INSERT INTO `khxx` VALUES ('359', '杭州奥立达', '浙江省建德市三河建兰路6号', '罗卓娅13819130013/小陈0191-66166891蒋正芳0191-66166891', null, null);
INSERT INTO `khxx` VALUES ('360', '杭州顺达伯耐特电梯有限公司（杭州顺达）', '杭州市余杭区崇贤镇北庄村', '俞富杨0191-86019601/86019969', null, null);
INSERT INTO `khxx` VALUES ('361', '浙江西尼', '浙江杭州市萧山经济开发区桥南7号路东(北环路南)（新地址：萧山南阳开发区阳城路31号）', '干巧娣13188199183   彭青18319193136/0191-19163601\n 曳引机随机文件收件人：：李兴花/电话：131-8813-3689 原点值接收人：：jiangan@syney.net\n 余丽：11918169096 0191-19163603 吴海鱼：  13639691663', null, null);
INSERT INTO `khxx` VALUES ('362', '建德天和', '建德市新安江镇城东科技工业园', '黄利洪0191-66963166/13116836696/0191-66963918叶树刚（应兰芳）0191-66963919', null, null);
INSERT INTO `khxx` VALUES ('363', '杭州新马', '浙江省建德市新安江镇城东区', '郭勇:13188310399  小邵    0191-66963963', null, null);
INSERT INTO `khxx` VALUES ('364', '杭州恒丰', '杭州萧山区靖江街道工业园区', '戴建军0191-83190000/13819691303', null, null);
INSERT INTO `khxx` VALUES ('365', '浙江比奇', '杭州市萧山区党山镇前兴工业区', '傅庆0191-83133388/13188601396', null, null);
INSERT INTO `khxx` VALUES ('366', '江西富士', '江西省吉安市吉水县城西工业园', '钟远平0996-3313839/13119069893/孟仲贤18909969989', null, null);
INSERT INTO `khxx` VALUES ('367', '杭州通达', '杭州市莫干山路493号5-105室', '沈斌0191-88803393', null, null);
INSERT INTO `khxx` VALUES ('368', '杭州太阳电气', '杭州市西湖区文三路90号东部软件园科技大厦4楼B408室(只寄发票到这个地址).仓库(收发货)杭州市江干区机场路277号20号楼(货与货和发票寄此地址)', '叶花:0191-81911399-339;仓库:0191-81066318/81069106', null, null);
INSERT INTO `khxx` VALUES ('369', '杭州锐志智能', '发货址：杭州下沙开发区海杭路128号曼斯顿电梯有限公司内 发票地址:杭州市新塘路99号天翔凤起时代大厦2002室', '王荣飞/0191-38033381 收货人:汪建华  0191-86999083/86999093', null, null);
INSERT INTO `khxx` VALUES ('370', '浙江富控', '温州市经济开发区滨海园区十五路五道519号', '孟仲贤18909969989/收货：黎小峰11018913099 采购部   周燕手机18011666113   QQ613310113\n工程：翁志华：18906610633 质量部 何倪 电话：0199-81839361手机：11383188933', null, null);
INSERT INTO `khxx` VALUES ('371', '深圳铃木平湖工厂', '浙江省平湖市平湖太道独黎路口 (现收货地址)', '张艳红0193-81396666转8081', null, null);
INSERT INTO `khxx` VALUES ('372', '温州奥德斯(浙江富奥）', '温州市乐清柳市翁洋镇华新工业区', '聂都奎11088998363/0199-63803933/杨志丹13919981116 0199-63803986', null, null);
INSERT INTO `khxx` VALUES ('373', '浙江梅轮电梯', '浙江省绍兴县齐贤镇梅林村（收货地址：浙江绍兴柯北工业园区梅中路576号 莫雅莉 0575-85591819', '采购：陈锋。朱虹0191-81660138/小高:0191-81660131 技术张慧:13819190613（倪金祥0191-81660138）陈亮（0191-81660036 13919108303）', null, null);
INSERT INTO `khxx` VALUES ('374', '浙江飞亚', '金华市金圆路1199号', '技术雯经理 0199-83366610/张建0199-89196893', null, null);
INSERT INTO `khxx` VALUES ('375', '浙江威尔金森电梯', '浙江省永康市五金工业园四期群升科技园  郑作枫13858932444/0579-87153733\n', '0199-89116189黄俊武  （发票） 13106996106', null, null);
INSERT INTO `khxx` VALUES ('376', '乐清迅达电梯', '浙江省乐清市虹桥镇虹河西路212号 三元公司', '赵元勇：13868988166', null, null);
INSERT INTO `khxx` VALUES ('377', '浙江振涯西屋电梯', '浙江省绍兴县湖塘街道宾舍村', '收货：钱根苗 11918116991/0191-86386313/13 收货:徐国萍0191-86386313/13191168909', null, null);
INSERT INTO `khxx` VALUES ('378', '浙江诺比克', '浙江温州市龙湾区永强大道八甲工业区章家桥3号曳引机收货地址：浙江温州龙湾区八甲工业区章家桥3号；杨俊孝 15888723456  0577-86908668', '吴晓明0199-86908668/0199-86908668  FAX：0199-86908333 杨俊孝', null, null);
INSERT INTO `khxx` VALUES ('379', '台州富士', '浙江台州市椒江区东南大道富士工业园', '11019630990 许艳 0196-88660999-86    88660188', null, null);
INSERT INTO `khxx` VALUES ('380', '宁波南方电梯', '宁波市灵桥路219号A座二路', '吴国创:0196-89303186', null, null);
INSERT INTO `khxx` VALUES ('381', '宁波五星电梯', '浙江宁波北仑区春晓工业园洋沙山西十路180号', '曾新明0196-86869391', null, null);
INSERT INTO `khxx` VALUES ('382', '浙江金华同创', '浙江省金华市婺州街星月花园690号', '周建庭11306180933   0199-83313098', null, null);
INSERT INTO `khxx` VALUES ('383', '浙江安利索电梯', '浙江省台州经济开发区经一路108-3号', '0196-8303188李先锋13186083163/13186083613', null, null);
INSERT INTO `khxx` VALUES ('384', '温州圣普电梯', '温州市瓯海经济开发区翠柏路2号', '0199-86369133施小姐', null, null);
INSERT INTO `khxx` VALUES ('385', '浙江丽水菱奥电梯', '浙江省丽水市白云山口48号/水阁工业区石牛路262号', '陈建饶13886336636', null, null);
INSERT INTO `khxx` VALUES ('386', '金华同创', null, '0199-8331313813906818396', null, null);
INSERT INTO `khxx` VALUES ('387', '嘉兴富士', null, '陆先生 13186399938', null, null);
INSERT INTO `khxx` VALUES ('388', '浙江威特电梯', '浙江省义乌市经济开发区杨村路335号', '联系人：蒋化林\n电话：0199-81810110\n手机：11918993890\n', null, null);
INSERT INTO `khxx` VALUES ('389', '台州市鸿升电梯', '浙江省台州市路桥桐屿坝头工业区', '吴仲龚：13616696381', null, null);
INSERT INTO `khxx` VALUES ('390', '上海富士', '上海大叶公路7505-7515号', '吴天忠13311691819  031- 19113606', null, null);
INSERT INTO `khxx` VALUES ('391', '武汉鑫元上海办事处', '地址：上海市浦东新区张杨路228号汤臣中心A座1917室', '胡毅刚电话：13919198669', null, null);
INSERT INTO `khxx` VALUES ('392', '上海德驰电扶梯成套配件有限公司(阿尔法)', '上海市共和新路966号1603室 姜志航地址:上海市宝山区富联二路198号顾村1号工业园区', '孙环霖 13901809969  031-36063300-6091', null, null);
INSERT INTO `khxx` VALUES ('393', '上海阿尔法电梯厂', '上海市宝山区富联二路198号顾村工业园区', '钱宝岐13901903163\\031-36066130', null, null);
INSERT INTO `khxx` VALUES ('394', '上海贝思特', '上海市浦东新区航头镇大麦弯工业园区航帆路2号徐毅 13918062045  邬雪明/18602106698/021-58223128/58225564   胡洁：021-58223789', '姚立波031-18339603/方卫红小灵通031-39391631 /13818086368/031-18333800 纪红031-18331168 /3668FAX:031-18333138  /13311961698', null, null);
INSERT INTO `khxx` VALUES ('395', '上海统一精工机械有限公司', '上海市青浦工业园区新区路409号', '技术金秋峰13136193638 031-69311868830工程部谭工 金叶13816893966 叶英', null, null);
INSERT INTO `khxx` VALUES ('396', '上海鹏沪电梯有限公司（登梯斯）', '嘉定区南翔镇嘉前路928号', '谢奕031-69199983     13966119311   /69199189常工13916313369 财务谢佳华(发票)031-69199986', null, null);
INSERT INTO `khxx` VALUES ('397', '上海时备莱(埃神)赵辉', '上海市浦东新区金港路333号16楼1619室', '031-11998990 赵辉13819836188\\031-66936998传 罗军(发票)', null, null);
INSERT INTO `khxx` VALUES ('398', '上海浦东开灵电梯厂', '上海浦东合庆跃东路300号', '丁为民13801630913\\031-68901030/031-68909669传/68903613财务 奚厂长68900193传', null, null);
INSERT INTO `khxx` VALUES ('399', '上海台菱', '发货地址：上海南汇临港新城书院都市产业圆丽正路1659号   陶爱明（系统）  021-58198866-832/13601904105；朱慧超（曳引机）021-58198866-817', null, null, null);
INSERT INTO `khxx` VALUES ('400', '石狮洋阳电梯贸易有限公司', '福建省石狮市子芳路691号巷43.45.47', '李志阳1300683391/0191-8888111/8883391', null, null);
INSERT INTO `khxx` VALUES ('401', '上海鸥开电梯配件有限公司', '上海市南汇区临港万祥都市产业区万达路208号', '丁志明031-18089930总机/18089981总   储华13386033996   倪春燕 仓库-33丁小姐39333191/38016319', null, null);
INSERT INTO `khxx` VALUES ('402', '上海昌菱', '上海市青浦区大盈镇青赵公路5899号', '张育广：031-19331336/13916860890', null, null);
INSERT INTO `khxx` VALUES ('403', '上海贤友机械制造有限公司', '上海市奉贤区奉城镇大叶公路蔡桥路168号(上海富士电梯斜对面)', '收货人：吴丽华031-69119198/13816163160', null, null);
INSERT INTO `khxx` VALUES ('404', '上海三洋电梯有限公司', '上海市南汇区新场坦直工业区古丹路26号', '佟肖(曳引机)031-38011396-8103/蔡燕红(系统)031-38011396-8103', null, null);
INSERT INTO `khxx` VALUES ('405', '上海凯钟进出口贸易有限公司', '上海市镇宁路200号欣安大厦东楼15层B座', '张佳瑜031-63891863-33  13611999001 陈经理13801691110', null, null);
INSERT INTO `khxx` VALUES ('406', '上海日宽', '上海市嘉定区黄渡镇聊群村383号', '翟方生 13101931311 031-69193390', null, null);
INSERT INTO `khxx` VALUES ('407', '上海三荣（昌华）电梯制造有限公司', '021-56863030宝山区月罗路2120号邮编201908', '采购经理：陈芹13801893018/16863030-8313/李海霞 电话 031-16866688-8308', null, null);
INSERT INTO `khxx` VALUES ('408', '上海长江斯迈普电梯有限公司', '上海市曹安路3939号', '林禄保13061661883/031-39198800-8066', null, null);
INSERT INTO `khxx` VALUES ('409', '上海三荣电梯工程有限公司', '上海市阳城路183号', '余雷031-16613633', null, null);
INSERT INTO `khxx` VALUES ('410', '上海中迅赛勒瓦电梯厂（上海双达  张文钱经理 安元路372号）', '上海市普陀区镇坪路赵家宅25号310室 石泉工业园区 近中山北路 石泉路）', '张文钱厂长  徐亚芬女士031-63168136 11060631 63669186 19166861 19918991-31   19169191(褚振华)13919399036收货人:董宁巍13919991963', null, null);
INSERT INTO `khxx` VALUES ('411', '上海爱默生', '上海市普陀区志丹路260弄1号楼201室', '向明华031-66109080', null, null);
INSERT INTO `khxx` VALUES ('412', '上海磊嘉机电设备工程有限公司', '上海市嘉定区城南路1128号C118', '031-69139160-101薛士部', null, null);
INSERT INTO `khxx` VALUES ('413', '上海日洋电梯有限公司', '上海市浦东高行镇东靖路1831号803室', '吴友文031-68998900-33', null, null);
INSERT INTO `khxx` VALUES ('414', '上海铃木电梯销售有限公司', '普陀区中山北路2318号104室', '史国华13361916101/031-63010906（张锡善）13601610313', null, null);
INSERT INTO `khxx` VALUES ('415', '上海广烨', '上海市新闸路84号后门', '张永富  031-63933110  13818311191', null, null);
INSERT INTO `khxx` VALUES ('416', '上海佳登曼电梯有限公司', '上海市嘉定区徐行镇新建二路328号', '郑总031-19116666-808', null, null);
INSERT INTO `khxx` VALUES ('417', '上海伊森', '上海阳城路183号永和大厦7楼', '沈健031-66311833', null, null);
INSERT INTO `khxx` VALUES ('418', '上海房屋设备有限公司', '上海市普陀区三源路200号', '夏巍巍031-13818816-311/13691166986', null, null);
INSERT INTO `khxx` VALUES ('419', '武汉世纪菱达', '上海市浦东新区张扬路228号汤臣中心A座1917室', '胡毅刚  13919198669 TEL：031-18999939', null, null);
INSERT INTO `khxx` VALUES ('420', '上海国泰电梯有限公司', '上海市青浦区凤溪镇民兴工业区民兴三路128号', '徐逾伽 13801900393 63308696', null, null);
INSERT INTO `khxx` VALUES ('421', '上海凌天', '上海市肇嘉浜路212号明珠饭店815室', '徐艳031-66111391   13181900963', null, null);
INSERT INTO `khxx` VALUES ('422', '上海中迅电梯南市销售安装工程有限公司', '上海银行豫园支行    316120--00067267250  税号:310101132444172  地址:陆家浜路468弄30号2301室 电话:33762424', null, null, null);
INSERT INTO `khxx` VALUES ('423', '上海哲科', '南通市人民东路金路大厦C座408室。', '俞为民 13901689966', null, null);
INSERT INTO `khxx` VALUES ('424', '允成机电科技（上海）有限公司', '上海市嘉定区黄渡镇春归路585号', '031-69190960 胡小丽', null, null);
INSERT INTO `khxx` VALUES ('425', '奥克斯快速（苏州）有限公司', null, '王建琴 0113-81191983', null, null);
INSERT INTO `khxx` VALUES ('426', '上海三胜康恩得', '上海市奉贤区柘公路733号18幢', '金国平 TEL：031-19190131-813', null, null);
INSERT INTO `khxx` VALUES ('427', '上海爱默生', null, '向明华 1380191906', null, null);
INSERT INTO `khxx` VALUES ('428', '苏州菱怡', null, '于工0113-63988838 13969383066', null, null);
INSERT INTO `khxx` VALUES ('429', '上海中迅实业电梯工程公司经营部', null, '金正中 031-16338130', null, null);
INSERT INTO `khxx` VALUES ('430', '浙江奥特', null, '周先生 0193-3016161 13919088111', null, null);
INSERT INTO `khxx` VALUES ('431', '上海巨立', null, '丁先生 13818133189', null, null);
INSERT INTO `khxx` VALUES ('432', '嵊州日通电梯', null, '钱学强 0191-83036633', null, null);
INSERT INTO `khxx` VALUES ('433', '上海谷坑', '莘朱路1258号1号楼101室', '张丽娟 031-61111003-116', null, null);
INSERT INTO `khxx` VALUES ('434', '浙江威特', '浙江省义乌市杨村路335号', '马美燕 0199-83810901 FAX：0199-81633309', null, null);
INSERT INTO `khxx` VALUES ('435', '宁波器材一厂', '宁波市北仑区大港虎业城天目山16号', '陈春生 13906863309 0196-86100619', null, null);
INSERT INTO `khxx` VALUES ('436', '上海三盛康恩得', null, '金国平 031-19190131-813  FAX：031-19190133', null, null);
INSERT INTO `khxx` VALUES ('437', '温州天力', null, '李秀荣  18818931999   FAX：0199-69308810', null, null);
INSERT INTO `khxx` VALUES ('438', '上海中富', null, 'FAX：031-11308099  TEL：031-11308088', null, null);
INSERT INTO `khxx` VALUES ('439', '浙江浙奥（原台州浙奥）', '台州市椒江机场东路108号 飞跃工业园E3幢   傅燕飞：15381862510', '罗静 0196-81839388  0196-88313169 傅燕飞：11381863110', null, null);
INSERT INTO `khxx` VALUES ('440', '上海立扶特电梯有限公司', '上海奉贤区南桥镇运河路576号', ' 瞿正华  收  11300991318\n', null, null);
INSERT INTO `khxx` VALUES ('441', '浙江快速', '湖州南浔镇生力路601号（老汽车站对面）', '孙勋（采购部负责人）手机：18619318100\n传真：0193-3063919\nQQ:  11133699\n邮箱：xun.sun@zjks-elevator.com刘志琴：电话：0193-3063639\n手机：18906933806\n传真：0193-3063919\nQQ:  1966993996\n邮箱：zhiqin.liu@zjks-elevator.com', null, null);
INSERT INTO `khxx` VALUES ('442', '浙江喜来登电梯有限公司', '浙江省温州市瓯北镇东瓯工业区', '袁秀友：11383191111/18019931100  0199-66991118  朱小姐18919969938', null, null);
INSERT INTO `khxx` VALUES ('443', '上海凌天', '上海市肇嘉浜路212号明珠饭店815室', '徐艳031-66111391 13181900963', null, null);
INSERT INTO `khxx` VALUES ('444', '上海上奥', '上海市金山区金山卫镇新卫公路838号', '陆彩英 电话：60893111转3039   瞿工：13311916100', null, null);
INSERT INTO `khxx` VALUES ('445', '东芝?梯(中国)有限公司　维修部维修营业科', '上海市宝山区?川路685号', '盛　颉 031－16808888#301', null, null);
INSERT INTO `khxx` VALUES ('446', '亚洲富士长林电梯(新余)', '江西省新余市北湖西路长林工业园', '冯桂敏：0990-6363961 13809903996 罗城刚：13899093366 技术：聂世杰013969383693', null, null);
INSERT INTO `khxx` VALUES ('447', '苏州建新', '吴江市汾湖镇莘塔社区芦莘公路518号曳引机收货地址：江苏吴江市汾湖镇莘塔社区莘周公路666号（鼎升企业内）：陈新妹  15206258392', '陈建新 0113-83099696  13963101118', null, null);
INSERT INTO `khxx` VALUES ('448', '苏州迅电', '江苏省吴江市汾湖镇龙江路888号', '蔡冰冰13811363133', null, null);
INSERT INTO `khxx` VALUES ('449', '湖州三荣电梯', '浙江省湖州市南浔世纪名都8幢1单元301', '邱芳萍 0193-3030311', null, null);
INSERT INTO `khxx` VALUES ('450', '浙江西沃电梯有限公司', '浙江湖州南浔古英公路西侧68号', '0193-3890338 沈建群 18919393391 莫永良 0193-38903338 18919393399', null, null);
INSERT INTO `khxx` VALUES ('451', '宁波江东宇达', '宁波江东百丈南路61号（1-4）―', '陆爱君  0196-89896611', null, null);
INSERT INTO `khxx` VALUES ('452', '赣州市鑫安机电', '江西省赣州市伍州大道28号明珠苑B栋103室', '王晓13969966886', null, null);
INSERT INTO `khxx` VALUES ('453', '浙江法斯特电梯', '浙江湖州南浔古英公路西侧', '施云杰   薄彩红 13336813130', null, null);
INSERT INTO `khxx` VALUES ('454', '杭州霍普曼', '杭州市桐庐县瑶淋镇琴溪村', '郑菲 0191-66399611 13869119030', null, null);
INSERT INTO `khxx` VALUES ('455', '上海从太电子科技', '上海市闵行区瓶安路 1600弄19号 1002室', '朱金伟 13331968661', null, null);
INSERT INTO `khxx` VALUES ('456', '松日电梯', null, '潘总18363193333', null, null);
INSERT INTO `khxx` VALUES ('457', '上海鹏阳电梯有限公司', '收发票地址上海市大渡河路648号510室 发货地址见订单', ' 采购部联系人：陆晨强 18016610316  031-11308016', null, null);
INSERT INTO `khxx` VALUES ('458', '杭州捷巧电子', '杭州滨江区滨安路1181号电梯集团大楼4楼', '金文方 11818310813', null, null);
INSERT INTO `khxx` VALUES ('459', '苏州奥玛斯', '江苏省吴江市七都镇虹桥东路88号（双塔集团内）', '潘济欣 电话0113-63833883  13869398198（收货和发票同一收件人）', null, null);
INSERT INTO `khxx` VALUES ('460', '上海盖普', '上海市金山区枫泾镇建定路78号', ' 鲁静 11931633196', null, null);
INSERT INTO `khxx` VALUES ('461', '浙江富奥（新）', '浙江嘉兴市海盐县大桥经济开发区棕榈路999号', '张静0193-86868663  18019366631', null, null);
INSERT INTO `khxx` VALUES ('462', '松日电梯（中国）有限公司', '江苏省吴江市七都镇人民西路北侧', '顾超（总经理助理sir@srielevator.com）0113-63131813 13991699399', null, null);
INSERT INTO `khxx` VALUES ('463', '苏州默顿电梯', '苏州市桃源镇梵香经济开发区99号  0512-63760118   杨小英', '0113-63960118   杨小英', null, null);
INSERT INTO `khxx` VALUES ('464', '上海贝淳经贸', '上海市闸北区天通庵路413号108室', '周炎培 18916913136  13311913136  031-16636303', null, null);
INSERT INTO `khxx` VALUES ('465', '浙江圣普', '浙江温州市瓯海经济开发区翠柏路2号', '施小莲  0199-86939191', null, null);
INSERT INTO `khxx` VALUES ('466', '浙江伯爵电梯', '江苏吴江市七都镇虹桥东路', '邵来好 18363163113    0113-63183131', null, null);
INSERT INTO `khxx` VALUES ('467', '浙江德尔法', '浙江湖州市吴兴区环渚路915号', '张荣华0193-33011168  18001931111', null, null);
INSERT INTO `khxx` VALUES ('468', '浙江快客电梯', '浙江杭州市萧山区南阳街道阳城路66号 田涛 13486396242', '田涛13686396363', null, null);
INSERT INTO `khxx` VALUES ('469', '上海崇友', '上海市嘉定区浏翔公路2555号', '冯晓萍031-19111610', null, null);
INSERT INTO `khxx` VALUES ('470', '浙江汉诺威电梯', '浙江省桐庐县经济开发区柴梅路777号', '陈国杰18868969333', null, null);
INSERT INTO `khxx` VALUES ('492', '苏州铃木', null, null, null, null);
INSERT INTO `khxx` VALUES ('493', '台州富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('494', '台州浙奥', null, null, null, null);
INSERT INTO `khxx` VALUES ('495', '沃克斯电梯', null, null, null, null);
INSERT INTO `khxx` VALUES ('496', '浙江西尼', null, null, null, null);
INSERT INTO `khxx` VALUES ('497', '浙江喜来登', null, null, null, null);
INSERT INTO `khxx` VALUES ('498', '成都康力', null, null, null, null);
INSERT INTO `khxx` VALUES ('499', '大连得利', null, null, null, null);
INSERT INTO `khxx` VALUES ('500', '大众电梯', null, null, null, null);
INSERT INTO `khxx` VALUES ('501', '德尔法电梯', null, null, null, null);
INSERT INTO `khxx` VALUES ('502', '德森克', null, null, null, null);
INSERT INTO `khxx` VALUES ('503', '东莞快意', null, null, null, null);
INSERT INTO `khxx` VALUES ('504', '佛山住友富士', null, null, null, null);
INSERT INTO `khxx` VALUES ('505', '江苏广日', null, null, null, null);
INSERT INTO `khxx` VALUES ('506', '康力', null, null, null, null);
INSERT INTO `khxx` VALUES ('507', '奥利夫', '', '', '', '');
INSERT INTO `khxx` VALUES ('508', '奥玛斯电梯（苏州）', '', '', '', '');
INSERT INTO `khxx` VALUES ('509', '奥瑞斯电梯', '', '', '', '');
INSERT INTO `khxx` VALUES ('510', '北方个人', '', '', '', '');
INSERT INTO `khxx` VALUES ('511', '长沙能达电梯', '', '', '', '');
INSERT INTO `khxx` VALUES ('512', '广州广日', '', '', '', '');
INSERT INTO `khxx` VALUES ('513', '大连李尔', '', '', '', '');
INSERT INTO `khxx` VALUES ('514', '东奥克虏伯', '', '', '', '');
INSERT INTO `khxx` VALUES ('515', '东莞华图仕', '', '', '', '');
INSERT INTO `khxx` VALUES ('516', '东莞三洋', '', '', '', '');
INSERT INTO `khxx` VALUES ('517', '佛山南海赛奇', '', '', '', '');
INSERT INTO `khxx` VALUES ('518', '广东广船', '', '', '', '');
INSERT INTO `khxx` VALUES ('519', '广东华凯', '', '', '', '');
INSERT INTO `khxx` VALUES ('520', '广东皇朝富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('521', '广东莱孚', '', '', '', '');
INSERT INTO `khxx` VALUES ('522', '广东朗格斯', '', '', '', '');
INSERT INTO `khxx` VALUES ('523', '广东联合富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('524', '广东联合通用', '', '', '', '');
INSERT INTO `khxx` VALUES ('525', '广东铃木', '', '', '', '');
INSERT INTO `khxx` VALUES ('526', '广东辛格林', '', '', '', '');
INSERT INTO `khxx` VALUES ('527', '广东新力欧菲尔', '', '', '', '');
INSERT INTO `khxx` VALUES ('528', '广东亚太西奥', '', '', '', '');
INSERT INTO `khxx` VALUES ('529', '广州东方', '', '', '', '');
INSERT INTO `khxx` VALUES ('530', '广州永日', '', '', '', '');
INSERT INTO `khxx` VALUES ('531', '广州日创', '', '', '', '');
INSERT INTO `khxx` VALUES ('532', '广州日新', '', '', '', '');
INSERT INTO `khxx` VALUES ('533', '珠江中富', '', '', '', '');
INSERT INTO `khxx` VALUES ('534', '常州电梯厂', '', '', '', '');
INSERT INTO `khxx` VALUES ('535', '成都环通机电', '', '', '', '');
INSERT INTO `khxx` VALUES ('536', '成都兴世纪', '', '', '', '');
INSERT INTO `khxx` VALUES ('537', '华东二个人', '', '', '', '');
INSERT INTO `khxx` VALUES ('538', '江苏鼎顺电梯', '', '', '', '');
INSERT INTO `khxx` VALUES ('539', '江苏菱智', '', '', '', '');
INSERT INTO `khxx` VALUES ('540', '江苏美佳', '', '', '', '');
INSERT INTO `khxx` VALUES ('541', '江苏中群', '', '', '', '');
INSERT INTO `khxx` VALUES ('542', '金华市盛帝斯电梯有限公司', '', '', '', '');
INSERT INTO `khxx` VALUES ('543', '凯斯博电梯有限公司', '', '', '', '');
INSERT INTO `khxx` VALUES ('544', '湖北正野', '', '', '', '');
INSERT INTO `khxx` VALUES ('545', '湖南信达', '', '', '', '');
INSERT INTO `khxx` VALUES ('546', '湖州南浔宏德', '', '', '', '');
INSERT INTO `khxx` VALUES ('547', '惠州富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('548', '惠州通力', '', '', '', '');
INSERT INTO `khxx` VALUES ('549', '吉林瀚翔', '', '', '', '');
INSERT INTO `khxx` VALUES ('550', '江苏伯爵', '', '', '', '');
INSERT INTO `khxx` VALUES ('551', '连云港西德电梯有限公司(江苏西继)', '', '', '', '');
INSERT INTO `khxx` VALUES ('552', '李程个人（广州广日）', '', '', '', '');
INSERT INTO `khxx` VALUES ('553', '李程个人（广州永日）', '', '', '', '');
INSERT INTO `khxx` VALUES ('554', '辽宁富士(安徽）', '', '', '', '');
INSERT INTO `khxx` VALUES ('555', '四川科莱', '', '', '', '');
INSERT INTO `khxx` VALUES ('556', '苏州富士制御电梯', '', '', '', '');
INSERT INTO `khxx` VALUES ('557', '齐齐哈尔建华', '', '', '', '');
INSERT INTO `khxx` VALUES ('558', '沈阳三洋安装', '', '', '', '');
INSERT INTO `khxx` VALUES ('559', '苏州银海机电科技有限公司', '', '', '', '');
INSERT INTO `khxx` VALUES ('560', '沃克斯电梯（上海腾能）', '', '', '', '');
INSERT INTO `khxx` VALUES ('561', '西威电梯江苏有限公司', '', '', '', '');
INSERT INTO `khxx` VALUES ('562', '苏州富士精工', '', '', '', '');
INSERT INTO `khxx` VALUES ('563', '许昌富士通电梯有限公司(许昌德瑞电梯有限公司)', '', '', '', '');
INSERT INTO `khxx` VALUES ('564', '中原智能', '', '', '', '');
INSERT INTO `khxx` VALUES ('565', '苏州立达中远（南浔）', '', '', '', '');
INSERT INTO `khxx` VALUES ('566', '重庆淮淳', '', '', '', '');
INSERT INTO `khxx` VALUES ('567', '杭州天奥电梯', '', '', '', '');
INSERT INTO `khxx` VALUES ('568', '苏州歌拉瑞', '', '', '', '');
INSERT INTO `khxx` VALUES ('569', '天津宏翔', '', '', '', '');
INSERT INTO `khxx` VALUES ('570', '浙江汉诺威', '', '', '', '');
INSERT INTO `khxx` VALUES ('571', '韩国富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('572', '浙江快客', '', '', '', '');
INSERT INTO `khxx` VALUES ('573', '博林特', '', '', '', '');
INSERT INTO `khxx` VALUES ('574', '浙江怡达', '', '', '', '');
INSERT INTO `khxx` VALUES ('575', '辽宁富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('576', '山东百斯特', '', '', '', '');
INSERT INTO `khxx` VALUES ('577', '山东富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('578', '山东莱茵艾佳', '', '', '', '');
INSERT INTO `khxx` VALUES ('579', '沈阳三洋', '', '', '', '');
INSERT INTO `khxx` VALUES ('580', '山西铃木', '', '', '', '');
INSERT INTO `khxx` VALUES ('581', '东莞富士', '', '', '', '');
INSERT INTO `khxx` VALUES ('582', '沈阳菱诺', '', '', '', '');
INSERT INTO `khxx` VALUES ('583', '浙江西直门', '', '', '', '');
INSERT INTO `mpzlxx` VALUES ('1', '');
INSERT INTO `mpzlxx` VALUES ('132', '珠江富士（中国）铭牌，载重打1050KG');
INSERT INTO `mpzlxx` VALUES ('133', '珠江富士（中国）铭牌');
INSERT INTO `mpzlxx` VALUES ('134', '蓝光铭牌，载重打900KG');
INSERT INTO `mpzlxx` VALUES ('135', '蓝光铭牌');
INSERT INTO `mpzlxx` VALUES ('136', '辽宁富士铭牌');
INSERT INTO `mpzlxx` VALUES ('137', '广日铭牌，作业号：16818488E 载重打印825KG1.75梯速打1.75/1.5');
INSERT INTO `mpzlxx` VALUES ('138', '广东亚太西奥铭牌');
INSERT INTO `mpzlxx` VALUES ('139', '蓝光铭牌，载重打1050KG');
INSERT INTO `mpzlxx` VALUES ('140', '蓝光铭牌,铭牌载重打1050KG');
INSERT INTO `mpzlxx` VALUES ('141', '沃克斯铭牌MP-93检验报告');
INSERT INTO `mpzlxx` VALUES ('142', '怡达快速铭牌检验报告');
INSERT INTO `mpzlxx` VALUES ('143', '蓝光铭牌检验报告');
INSERT INTO `mpzlxx` VALUES ('144', '蓝光英文铭牌');
INSERT INTO `mpzlxx` VALUES ('145', '怡达快速铭牌 铭牌打1250KG检验报告');
INSERT INTO `mpzlxx` VALUES ('146', '怡达快速铭牌,铭牌打4;1 2000KG 0.5M/S        检验报告');
INSERT INTO `mpzlxx` VALUES ('147', '蓝光铭牌，铭牌打1050kg检验报告');
INSERT INTO `mpzlxx` VALUES ('148', '航天金羊铭牌型号RT20/出场编码AJEC  （Y机型号RT40)');
INSERT INTO `mpzlxx` VALUES ('149', '航天金羊铭牌型号RT20/出场编码AJEC');
INSERT INTO `mpzlxx` VALUES ('150', '沈阳三洋铭牌');
INSERT INTO `mpzlxx` VALUES ('151', '蓝光英文铭牌及随机资料');
INSERT INTO `mpzlxx` VALUES ('152', '恒达富士铭牌MP-118');
INSERT INTO `mpzlxx` VALUES ('153', '怡达快速铭牌');
INSERT INTO `mpzlxx` VALUES ('154', '广日铭牌，作业号：16814997E');
INSERT INTO `mpzlxx` VALUES ('155', '广日铭牌，作业号：16812648G');
INSERT INTO `mpzlxx` VALUES ('156', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文  SM-S');
INSERT INTO `mpzlxx` VALUES ('157', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文  SM-T');
INSERT INTO `mpzlxx` VALUES ('158', '蓝光铭牌，载重打印825KG');
INSERT INTO `mpzlxx` VALUES ('159', '蓝光铭牌，铭牌载重1050KG');
INSERT INTO `mpzlxx` VALUES ('160', '广日铭牌，作业号：16812648F');
INSERT INTO `mpzlxx` VALUES ('161', ' 蓝光铭牌');
INSERT INTO `mpzlxx` VALUES ('162', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文(SM-T)');
INSERT INTO `mpzlxx` VALUES ('163', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文SM-T');
INSERT INTO `mpzlxx` VALUES ('164', '苏州铃木铭牌（SSEC版本）');
INSERT INTO `mpzlxx` VALUES ('165', '韩国富士铭牌');
INSERT INTO `mpzlxx` VALUES ('166', '广日铭牌，作业号：16806565D');
INSERT INTO `mpzlxx` VALUES ('167', '蓝光铭牌主机铭牌随资料不安装在机器上');
INSERT INTO `mpzlxx` VALUES ('168', '蓝光英文铭牌，铭牌打1250KG');
INSERT INTO `mpzlxx` VALUES ('169', '蓝光铭牌SM-S');
INSERT INTO `mpzlxx` VALUES ('170', '广日铭牌，作业号：16818488K');
INSERT INTO `mpzlxx` VALUES ('171', '大众铭牌系列型号DM-WYT');
INSERT INTO `mpzlxx` VALUES ('172', '西威铭牌，悬挂比4:1,2300KG,0.75m/s');
INSERT INTO `mpzlxx` VALUES ('173', '蓝光铭牌，铭牌打400KG');
INSERT INTO `mpzlxx` VALUES ('174', '蓝光铭牌，铭牌载重打印为525KG');
INSERT INTO `mpzlxx` VALUES ('175', '广日铭牌，作业号：16814997A');
INSERT INTO `mpzlxx` VALUES ('176', '广日铭牌，作业号：16814997B');
INSERT INTO `mpzlxx` VALUES ('177', '广日英文铭牌，作业号：16806705A');
INSERT INTO `mpzlxx` VALUES ('178', '蓝光铭牌，铭牌载重打600KG主机铭牌随资料不安装在机器上');
INSERT INTO `mpzlxx` VALUES ('179', '奥立达铭牌1.1版本ALDWYT-T');
INSERT INTO `mpzlxx` VALUES ('180', '奥立达铭牌1.1版本 铭牌打“3000KG 0.5M/S”4：1     ALDWYT-U');
INSERT INTO `mpzlxx` VALUES ('181', '凯斯博铭牌（主机铭牌凯斯博）制动器上行铭牌用蓝光  KA-JLS');
INSERT INTO `mpzlxx` VALUES ('182', '凯斯博铭牌');
INSERT INTO `mpzlxx` VALUES ('183', '德森克铭牌，出厂编码打K2029系列型号DSK-TB-II');
INSERT INTO `mpzlxx` VALUES ('184', '广日铭牌，作业号：16815735L');
INSERT INTO `mpzlxx` VALUES ('185', '蓝光铭牌,载重打1250KG');
INSERT INTO `mpzlxx` VALUES ('186', '蓝光铭牌，铭牌载重825KG');
INSERT INTO `mpzlxx` VALUES ('187', '广日铭牌作业号：16806564F');
INSERT INTO `mpzlxx` VALUES ('188', '蓝光铭牌，铭牌打印：载重525KG,速度1.5M/S，曳引比1：1');
INSERT INTO `mpzlxx` VALUES ('189', '蓝光铭牌，铭牌载重打印为825KG');
INSERT INTO `mpzlxx` VALUES ('190', '恒达富士英文铭牌MP-118A');
INSERT INTO `mpzlxx` VALUES ('191', '康力铭牌');
INSERT INTO `mpzlxx` VALUES ('192', '歌拉瑞中文铭牌，型号打：GWZ01A-02');
INSERT INTO `mpzlxx` VALUES ('193', '歌拉瑞英文铭牌，型号打：GWZ01A-02');
INSERT INTO `mpzlxx` VALUES ('194', '东莞三洋监制铭牌');
INSERT INTO `mpzlxx` VALUES ('195', '蓝光铭牌SM-U');
INSERT INTO `mpzlxx` VALUES ('196', '广日铭牌，作业号：16815735J，载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('197', '广日铭牌，铭牌载重打印1050KG，作业号：16812648C');
INSERT INTO `mpzlxx` VALUES ('198', '广日铭牌，铭牌载重打印825KG，作业号：16812648B');
INSERT INTO `mpzlxx` VALUES ('199', '韩国富士铭牌,需要贴韩国富士专用KTL贴（TA1.0B的）');
INSERT INTO `mpzlxx` VALUES ('200', '蓝光英文铭牌检验报告');
INSERT INTO `mpzlxx` VALUES ('201', '恒达富士铭牌MP-118 铭牌打 1.5M/S');
INSERT INTO `mpzlxx` VALUES ('202', '蓝光铭牌  铭牌打2000KG 0.5M/S 4:1');
INSERT INTO `mpzlxx` VALUES ('203', '德森克铭牌，出厂编码打D2143系列型号DSK-TB-II');
INSERT INTO `mpzlxx` VALUES ('204', '蓝光铭牌，铭牌梯速打1.5M/S');
INSERT INTO `mpzlxx` VALUES ('205', '广日铭牌，作业号：16806564B');
INSERT INTO `mpzlxx` VALUES ('206', '德森克铭牌，出厂编码打D2287系列型号DSK-TB-II');
INSERT INTO `mpzlxx` VALUES ('207', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文  SM-U');
INSERT INTO `mpzlxx` VALUES ('208', '广日铭牌，作业号：16806564G');
INSERT INTO `mpzlxx` VALUES ('209', '广日铭牌，作业号：16818488A');
INSERT INTO `mpzlxx` VALUES ('210', '蓝光铭牌，铭牌梯速打印1.5M/S');
INSERT INTO `mpzlxx` VALUES ('211', '珠江中富铭牌');
INSERT INTO `mpzlxx` VALUES ('212', '西威铭牌');
INSERT INTO `mpzlxx` VALUES ('213', '江苏广日德科铭牌');
INSERT INTO `mpzlxx` VALUES ('214', '苏州歌拉瑞中文铭牌，型号打：GWZ01A-02');
INSERT INTO `mpzlxx` VALUES ('215', '广日铭牌，作业号：16804638G');
INSERT INTO `mpzlxx` VALUES ('216', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文    SM-S');
INSERT INTO `mpzlxx` VALUES ('217', '蓝光铭牌，悬挂比4:1，铭牌打：2000KG,梯速：0.75m/s');
INSERT INTO `mpzlxx` VALUES ('218', '浙江富控英文铭牌（MP-120A）');
INSERT INTO `mpzlxx` VALUES ('219', '蓝光英文铭牌，铭牌打印545KG');
INSERT INTO `mpzlxx` VALUES ('220', '蓝光英文铭牌，铭牌打印750KG');
INSERT INTO `mpzlxx` VALUES ('221', '蓝光中文铭牌，英文随机资料');
INSERT INTO `mpzlxx` VALUES ('222', '广日铭牌.作业号：16827721B 载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('223', '浙江富控英文铭牌（MP-116）');
INSERT INTO `mpzlxx` VALUES ('224', '凯斯博铭牌KA-JLY');
INSERT INTO `mpzlxx` VALUES ('225', '蓝光铭牌,铭牌打2000KG,1.0M/S 4:1');
INSERT INTO `mpzlxx` VALUES ('226', '奥立达铭牌1.1版本 奥利达ALDWYT-S');
INSERT INTO `mpzlxx` VALUES ('227', '广日铭牌，作业号：16806564E');
INSERT INTO `mpzlxx` VALUES ('228', '蓝光英文铭牌，载重打1050KG');
INSERT INTO `mpzlxx` VALUES ('229', '蓝光铭牌，铭牌载重2000KG，速度1.0M/S，曳引比4：1');
INSERT INTO `mpzlxx` VALUES ('230', '蓝光铭牌，');
INSERT INTO `mpzlxx` VALUES ('231', '蓝光铭牌，铭牌载重3000KG，速度1.75M/S，曳引比4：1');
INSERT INTO `mpzlxx` VALUES ('232', '广日铭牌，作业号：16818488D 载重打印825KG');
INSERT INTO `mpzlxx` VALUES ('233', '蓝光铭牌，铭牌打1.5m/s                 检验报告');
INSERT INTO `mpzlxx` VALUES ('234', 'DOVER英文铭牌,主机型号打印为SC80L,载重打印2050kg');
INSERT INTO `mpzlxx` VALUES ('235', ' 蓝光英文铭牌');
INSERT INTO `mpzlxx` VALUES ('236', '蓝光铭牌，铭牌打印为载重1050KG,功率14KW');
INSERT INTO `mpzlxx` VALUES ('237', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文SM-U');
INSERT INTO `mpzlxx` VALUES ('238', '蓝光铭牌，铭牌打印为载重1050KG,功率14.1KW.');
INSERT INTO `mpzlxx` VALUES ('239', '蓝光英文铭牌 ,载重打400KG检验报告');
INSERT INTO `mpzlxx` VALUES ('240', '苏州铃木铭牌（SSEC版本）。');
INSERT INTO `mpzlxx` VALUES ('241', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文 sm-s');
INSERT INTO `mpzlxx` VALUES ('242', '广日铭牌，作业号：16806636F');
INSERT INTO `mpzlxx` VALUES ('243', '怡达快速铭牌，铭牌载重1250KG检验报告');
INSERT INTO `mpzlxx` VALUES ('244', '松日铭牌MP-117');
INSERT INTO `mpzlxx` VALUES ('245', '蓝光铭牌 载重打1050KG              检验报告');
INSERT INTO `mpzlxx` VALUES ('246', '广日铭牌，作业号：16806636D');
INSERT INTO `mpzlxx` VALUES ('247', '广日铭牌，作业号：16818488G 载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('248', '蓝光铭牌，铭牌载重打印为1250KG');
INSERT INTO `mpzlxx` VALUES ('249', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文SM-S');
INSERT INTO `mpzlxx` VALUES ('250', '主机用西德中文铭牌，制动器和上行超速铭牌用蓝光中文，载重打：1050KG SM-T');
INSERT INTO `mpzlxx` VALUES ('251', '奥立达铭牌1.1版本   ALDWYT-T');
INSERT INTO `mpzlxx` VALUES ('252', '广日铭牌，作业号：16814992A');
INSERT INTO `mpzlxx` VALUES ('253', '广日铭牌，作业号：16815735A');
INSERT INTO `mpzlxx` VALUES ('254', '广日铭牌，作业号：16814992D');
INSERT INTO `mpzlxx` VALUES ('255', '广日铭牌，铭牌载重打印825KG，作业号：16815735D');
INSERT INTO `mpzlxx` VALUES ('256', '广日铭牌，作业号：16814992G');
INSERT INTO `mpzlxx` VALUES ('257', '广日铭牌，作业号：16815735G，载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('258', '广日铭牌,作业号：16814992B');
INSERT INTO `mpzlxx` VALUES ('259', '广日铭牌作业号：16815735B');
INSERT INTO `mpzlxx` VALUES ('260', '广日铭牌，作业号：16814992E');
INSERT INTO `mpzlxx` VALUES ('261', '广日铭牌，铭牌载重打印825KG，作业号：16815735E');
INSERT INTO `mpzlxx` VALUES ('262', '广日铭牌，作业号：16814992H');
INSERT INTO `mpzlxx` VALUES ('263', '广日铭牌，铭牌载重打印1050K，作业号：16815735H');
INSERT INTO `mpzlxx` VALUES ('264', '蓝光铭牌                   检验报告');
INSERT INTO `mpzlxx` VALUES ('265', '蓝光铭牌，铭牌打印为载重825KG,功率5.7KW，');
INSERT INTO `mpzlxx` VALUES ('266', '蓝光铭牌，铭牌打印为载重1050KG,功率7KW.');
INSERT INTO `mpzlxx` VALUES ('267', '蓝光铭牌，铭牌打印为载重825KG,功率8.5KW，');
INSERT INTO `mpzlxx` VALUES ('268', '蓝光铭牌，铭牌打印为载重1050KG,功率10.6KW.');
INSERT INTO `mpzlxx` VALUES ('269', '蓝光铭牌，铭牌打印为载重825KG,功率10KW，');
INSERT INTO `mpzlxx` VALUES ('270', '蓝光铭牌，铭牌打印为载重1050KG,功率12.3KW.');
INSERT INTO `mpzlxx` VALUES ('271', '广日铭牌，作业号：16818488H 载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('272', '广日铭牌，铭牌载重打印825KG，作业号：16812648A');
INSERT INTO `mpzlxx` VALUES ('273', '蓝光铭牌，载重打印1050KG');
INSERT INTO `mpzlxx` VALUES ('274', '广日铭牌，作业号：16814997F');
INSERT INTO `mpzlxx` VALUES ('275', '蓝光英文铭牌,铭牌载重打印400KG');
INSERT INTO `permission` VALUES ('ADMIN', '1', '1', '1', '1', '1', '1', '1', '1');
INSERT INTO `permission` VALUES ('JHLEADER', '0', '1', '0', '1', '0', '1', '1', '1');
INSERT INTO `permission` VALUES ('USER', '0', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `permission` VALUES ('YWLEADER', '1', '0', '1', '0', '1', '0', '1', '1');
INSERT INTO `serialnumber` VALUES ('1', '146');
INSERT INTO `serialnumber` VALUES ('2', '144');
INSERT INTO `user` VALUES ('Admin', 'e10adc3949ba59abbe56e057f20f883e', '其他', 'ADMIN');
INSERT INTO `user` VALUES ('刘明东', 'f371509140318d5e8d8d13fb41bd7d7e', '计划科', 'USER');
INSERT INTO `user` VALUES ('刘艳萍', '710e3927efc1c4665f6aab3e2e2470b6', '业务部', 'USER');
INSERT INTO `user` VALUES ('卢文俏', '567c28a96d246361f7243166fdfa3bbd', '业务部', 'USER');
INSERT INTO `user` VALUES ('吴勇霞', '15e98db15f19957d693c28dfbcbd8de4', '业务部', 'USER');
INSERT INTO `user` VALUES ('周海越', 'fd60b3300c62589939c50e67bc86f33c', '业务部', 'YWLEADER');
INSERT INTO `user` VALUES ('喻杰', 'f2dd566036fda39d00e123469dbfeeff', '业务部', 'USER');
INSERT INTO `user` VALUES ('孙海龙', '9357a48c43befc9d5cd6b234aa43a1e6', '其他', 'ADMIN');
INSERT INTO `user` VALUES ('孙莹莹', '1d9cc76095161e6962a8d1ada194313a', '业务部', 'USER');
INSERT INTO `user` VALUES ('曲鸣悦', '9e00a76ed85b359722e5715c34aca8d4', '业务部', 'USER');
INSERT INTO `user` VALUES ('曹文俊', '8cae54aec61a07a1b3bee684749ae397', '计划科', 'USER');
INSERT INTO `user` VALUES ('李建华', 'df460fc622944186adad86ce853458ae', '业务部', 'USER');
INSERT INTO `user` VALUES ('杨鹏', '4bc5fe2359397342d998606ecd31ae87', '其他', 'ADMIN');
INSERT INTO `user` VALUES ('王亚明', '482031ace798a4fd00651ec507e78b10', '业务部', 'USER');
INSERT INTO `user` VALUES ('王宇博', '86f703e4f084cbac0e44060d02e77c06', '其他', 'ADMIN');
INSERT INTO `user` VALUES ('王玺', 'df63c879f0739e5b329b83d64dbc6f49', '计划科', 'USER');
INSERT INTO `user` VALUES ('王超', '7e72fb27fc800c6e906557baee4ed1dc', '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('王颖', '1285384ddfb057814bad78127bc789be', '业务部', 'USER');
INSERT INTO `user` VALUES ('白艳玲', 'de14eb8ed5316b565495b43444146fb8', '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('苏璇', 'bb7822fdf4eb5fff6dba132a10cdc36a', '业务部', 'USER');
INSERT INTO `user` VALUES ('谭福进', 'e56db61130dcce6012f9bf518f5499ba', '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('陈静', '0b4b8fdb33bc1700c1d1ba6254c55b2f', '业务部', 'USER');
INSERT INTO `user` VALUES ('陈鹤', '1956f2a1e48cca88c3194d5e7f2de48d', '业务部', 'USER');
INSERT INTO `user` VALUES ('高珊', 'c08199dc9290811a9e761e3f813a9862', '业务部', 'USER');
INSERT INTO `user` VALUES ('高英', 'e1a7cae0ea57092c97cc165440776e95', '计划科', 'JHLEADER');
INSERT INTO `yylggflxx` VALUES ('1', '');
INSERT INTO `yylggflxx` VALUES ('2', '410*12*10*14-3F(A)');
INSERT INTO `yylggflxx` VALUES ('3', '480*6*12*18-3');
INSERT INTO `yylggflxx` VALUES ('4', '480*7*10*16-3G');
INSERT INTO `yylggflxx` VALUES ('5', '480*10*12*15-3F(C)');
INSERT INTO `yylggflxx` VALUES ('6', '480*12*12*15-3F(C)');
INSERT INTO `yylggflxx` VALUES ('7', '400*6*10*16-3G');
INSERT INTO `yylggflxx` VALUES ('8', '400*5*10*16-2(SB)');
INSERT INTO `yylggflxx` VALUES ('9', '400*4*10*16-2(SA)');
INSERT INTO `yylggflxx` VALUES ('10', '480*10*12*15-3F(D)');
INSERT INTO `yylggflxx` VALUES ('11', '480*7*12*18-3D');
INSERT INTO `yylggflxx` VALUES ('12', '410*6*10*16-3E');
INSERT INTO `yylggflxx` VALUES ('13', '480*14*12*16-3F(P)');
INSERT INTO `yylggflxx` VALUES ('14', '410*5*10*16-3C');
INSERT INTO `yylggflxx` VALUES ('15', '480*8*12*18-3D');
INSERT INTO `yylggflxx` VALUES ('16', '340*8*8*12-3');
INSERT INTO `yylggflxx` VALUES ('17', '400*3*10*16-3W');
INSERT INTO `yylggflxx` VALUES ('18', '410*6*10*16-3');
INSERT INTO `yylggflxx` VALUES ('19', '410*5*10*16-3E');
INSERT INTO `yylggflxx` VALUES ('20', '480*6*10*16-3J');
INSERT INTO `yylggflxx` VALUES ('21', '480*12*10*14-3F(F)');
INSERT INTO `yylggflxx` VALUES ('22', '480*10*10*14-3F(F)');
INSERT INTO `yylggflxx` VALUES ('23', '400*6*10*16-2(SB)');
INSERT INTO `yylggflxx` VALUES ('24', '400*6*10*15-3AC');
INSERT INTO `yylggflxx` VALUES ('25', '410*6*10*16-3N');
INSERT INTO `yylggflxx` VALUES ('26', '410*7*10*16-3C');
INSERT INTO `yylggflxx` VALUES ('27', '480*4*12*20.5-2E');
INSERT INTO `yylggflxx` VALUES ('28', '480*7*10*16-2B');
INSERT INTO `yylggflxx` VALUES ('29', '480*7*12*18-3L');
INSERT INTO `yylggflxx` VALUES ('30', '410*6*10*16-3C');
INSERT INTO `yylggflxx` VALUES ('31', '480*6*12*18-3D');
INSERT INTO `yylggflxx` VALUES ('32', '480*8*12*18-3I');
INSERT INTO `yylggflxx` VALUES ('33', '400*5*10*16-2J');
INSERT INTO `yylggflxx` VALUES ('34', '480*6*10*16-2D');
INSERT INTO `yylggflxx` VALUES ('35', '410*8*10*16-3P');
INSERT INTO `yylggflxx` VALUES ('36', '480*7*10*16-2D');
INSERT INTO `yylggflxx` VALUES ('37', '410*8*10*16-3C');
INSERT INTO `yylggflxx` VALUES ('38', '410*8*10*14-3F(A)');
INSERT INTO `yylggflxx` VALUES ('39', '480*12*11*15-3F(N)');
INSERT INTO `yylggflxx` VALUES ('40', '400*5*10*16-3T');
INSERT INTO `yylggflxx` VALUES ('41', '400*5*10*16-3N');
INSERT INTO `yylggflxx` VALUES ('42', '410*10*10*14-3F(A)');
INSERT INTO `yylggflxx` VALUES ('43', '400*6*10*16-2E');
INSERT INTO `yylggflxx` VALUES ('44', '410*6*10*16-Y.1-8B');
INSERT INTO `yylggflxx` VALUES ('45', '480*5*10*16-3AD');
INSERT INTO `yylggflxx` VALUES ('46', '480*6*10*16-3AD');
INSERT INTO `yylggflxx` VALUES ('47', '410*6*10*16-3C');
INSERT INTO `yylggflxx` VALUES ('48', '480*8*10*16-3J');
INSERT INTO `yylggflxx` VALUES ('49', '480*8*10*15-2C');
INSERT INTO `yylggflxx` VALUES ('50', '480*7*10*16-2G');
INSERT INTO `yylggflxx` VALUES ('51', '400*5*8*12-2F');
INSERT INTO `yylggflxx` VALUES ('52', '410*6*10*16-PM-1');
INSERT INTO `yylggflxx` VALUES ('53', '480*5*10*16-3U');
INSERT INTO `yylggflxx` VALUES ('54', '410*9*10*16-3DD');
INSERT INTO `yylggflxx` VALUES ('55', '400*4*8*12-2F');
INSERT INTO `yylggflxx` VALUES ('56', '480*4*10*16-3U');
INSERT INTO `yylggflxx` VALUES ('57', 'V480*7*10*16-2G');
INSERT INTO `yylggflxx` VALUES ('58', '530*10*12*15-3F(Q)');
INSERT INTO `yylggflxx` VALUES ('59', '400*6*10*16-2I');
INSERT INTO `yylggflxx` VALUES ('60', '480*14*10*15-3F(D)');
INSERT INTO `yylggflxx` VALUES ('61', '410*6*10*16-3K');
INSERT INTO `yylggflxx` VALUES ('62', '480*5*10*16-3J');
INSERT INTO `yylggflxx` VALUES ('63', '480*8*10*16-2D');
INSERT INTO `yylggflxx` VALUES ('64', '480*12*10*14-3F(R)');
INSERT INTO `yylggflxx` VALUES ('65', '410*7*10*16-3Q');
INSERT INTO `yylggflxx` VALUES ('66', '400*5*10*16-2K');
INSERT INTO `yylggflxx` VALUES ('67', '410*8*10*16-3Q');
INSERT INTO `yylggflxx` VALUES ('68', '400*4*8*16-3R');
INSERT INTO `yylggflxx` VALUES ('69', '410*6*10*16-3R');
INSERT INTO `yylggflxx` VALUES ('70', '400*6*10*16-3AE');
INSERT INTO `yylggflxx` VALUES ('71', '480*7*10*16-3S');
INSERT INTO `yylggflxx` VALUES ('72', '400*4*10*16-3AF');
INSERT INTO `yylggflxx` VALUES ('73', '480*12*12*15-3F（C）');
INSERT INTO `yylggflxx` VALUES ('74', '400*5*10*16-3AF');
INSERT INTO `yylggflxx` VALUES ('75', '480*7*12*18-2A');
INSERT INTO `yylggflxx` VALUES ('76', '480*14*10*14-3F(S)');
INSERT INTO `yylggflxx` VALUES ('77', '410*6*10*16-8B');
INSERT INTO `yylggflxx` VALUES ('78', '400*5*10*16-2C');
INSERT INTO `yylggflxx` VALUES ('79', '480*7*10*16-3U');
INSERT INTO `yylggflxx` VALUES ('80', '480*16*10*14-3F（H）');
INSERT INTO `yylggflxx` VALUES ('81', '400*6*10*16-3AG');
INSERT INTO `yylggflxx` VALUES ('82', '480*6*12*18-3M');
INSERT INTO `yylggflxx` VALUES ('83', '480*12*10*14-3F（F）');
INSERT INTO `yylggflxx` VALUES ('84', '410*6*10*16-6B');
INSERT INTO `yylggflxx` VALUES ('85', '480*9*12*18-3P');
INSERT INTO `yylggflxx` VALUES ('86', '480*7*10*16-3W');
INSERT INTO `yylggflxx` VALUES ('87', '400*6*8*14-2L');
INSERT INTO `yylggflxx` VALUES ('88', '400*5*10*16-2H');
INSERT INTO `yylggflxx` VALUES ('89', '480*7*10*16-3H');
INSERT INTO `yylggflxx` VALUES ('90', '410*8*10*16-3R');
INSERT INTO `yylggflxx` VALUES ('91', 'V410*6*10*16-3T');
INSERT INTO `yylggflxx` VALUES ('92', '410*5*10*16-3');
INSERT INTO `yylggflxx` VALUES ('93', '480*10*12*15-3F（C）');
INSERT INTO `yylggflxx` VALUES ('94', '480*3*12*20.5-2G');
INSERT INTO `yylggflxx` VALUES ('95', '480*10*12*18-3F（E）');
INSERT INTO `yylggflxx` VALUES ('96', '480*9*10*16-3N');
INSERT INTO `yylggflxx` VALUES ('97', '480*12*12*15-3F（C)');
INSERT INTO `yylggflxx` VALUES ('98', '480*6*10*16-3AI');
INSERT INTO `yylggflxx` VALUES ('99', '400*5*10*16-2B');
INSERT INTO `yylggflxx` VALUES ('100', '325*5*8*12-2A');
INSERT INTO `yylggflxx` VALUES ('101', '410*9*10*16-3X');
INSERT INTO `yylggflxx` VALUES ('102', '410*7*10*16-3R');
INSERT INTO `yylggflxx` VALUES ('103', '480*7*12*18-3M');
INSERT INTO `yylggflxx` VALUES ('104', '400*5*10.2*16-2(XN）');
INSERT INTO `yylggflxx` VALUES ('105', 'V400*6*8*14-2L');
INSERT INTO `yylggflxx` VALUES ('106', '340*6*8*13-3');
INSERT INTO `yylggflxx` VALUES ('107', '400*4*10*16-2C');
INSERT INTO `yylggflxx` VALUES ('108', '410*7*10*16-3T');
INSERT INTO `yylggflxx` VALUES ('109', '480*14*12*16-3F(K)');
INSERT INTO `yylggflxx` VALUES ('110', '480*10*12.4*15-3F(T)');
INSERT INTO `yylggflxx` VALUES ('111', '480*6*12*18-3Y');
INSERT INTO `yylggflxx` VALUES ('112', '400*5*8*14-2M');
INSERT INTO `yylggflxx` VALUES ('113', 'V480*6*10*16-2H');
INSERT INTO `yylggflxx` VALUES ('114', 'V480*5*10*16-2H');
INSERT INTO `yylggflxx` VALUES ('115', 'V480*7*10*16-2I');
INSERT INTO `yylggflxx` VALUES ('116', '480*10*10*15-3F(H)');
INSERT INTO `yylggflxx` VALUES ('117', 'V400*5*8*14-2M');
INSERT INTO `yylggflxx` VALUES ('118', '480*7*10*16-2J');
INSERT INTO `yylggflxx` VALUES ('119', '400*6*8*12-2F');
INSERT INTO `yylggflxx` VALUES ('120', '480*7*10*14-2K');
INSERT INTO `yylggflxx` VALUES ('121', '480*8*10*15-3Q');
INSERT INTO `yylggflxx` VALUES ('122', '400*5*10*16');
INSERT INTO `yylggflxx` VALUES ('123', '400*4*10*16');
INSERT INTO `yylggflxx` VALUES ('124', '480*7*12*18');
INSERT INTO `yylggflxx` VALUES ('125', 'V400*5*10*16');
INSERT INTO `yylggflxx` VALUES ('126', '480*5*10*16');
INSERT INTO `yylggflxx` VALUES ('127', '480*6*12*18');
INSERT INTO `yylggflxx` VALUES ('128', '325*4*8*12');
INSERT INTO `yylggflxx` VALUES ('129', 'V400*4*10*16');
INSERT INTO `yylggflxx` VALUES ('130', 'WYT-SB.2');
INSERT INTO `yylggflxx` VALUES ('131', 'WYT-TA.3-YA');
INSERT INTO `yylggflxx` VALUES ('132', '325*5*8*12');
INSERT INTO `yylggflxx` VALUES ('133', 'WYT-TA.3');
INSERT INTO `yylggflxx` VALUES ('134', '480*8*12*18');
INSERT INTO `zcxx` VALUES ('1', '');
INSERT INTO `zcxx` VALUES ('2', 'MC');
INSERT INTO `zcxx` VALUES ('3', 'BWW');
INSERT INTO `zcxx` VALUES ('4', 'BCW');
INSERT INTO `zcxx` VALUES ('5', 'CWW');
INSERT INTO `zcxx` VALUES ('6', 'DWW');
INSERT INTO `zcxx` VALUES ('7', 'DWN');
INSERT INTO `zcxx` VALUES ('8', 'EWW');
INSERT INTO `zcxx` VALUES ('9', 'BCC');
INSERT INTO `zcxx` VALUES ('10', 'MM');
INSERT INTO `zcxx` VALUES ('11', 'BNN');
INSERT INTO `zcxx` VALUES ('12', 'AWW');
INSERT INTO `zcxx` VALUES ('13', 'BCN');
INSERT INTO `zcxx` VALUES ('14', 'BWN');
INSERT INTO `zcxx` VALUES ('15', 'MW');
INSERT INTO `zcxx` VALUES ('16', 'TA');
INSERT INTO `zcxx` VALUES ('17', 'DNN');
INSERT INTO `zcxx` VALUES ('18', 'CNN');
INSERT INTO `zcxx` VALUES ('19', 'DCC');
INSERT INTO `zcxx` VALUES ('20', 'MN');
INSERT INTO `zcxx` VALUES ('21', 'ANN');
INSERT INTO `zcxx` VALUES ('22', 'ENN');
INSERT INTO `zdqdyflxx` VALUES ('1', '');
INSERT INTO `zdqdyflxx` VALUES ('2', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('3', 'DC220V');
INSERT INTO `zdqdyflxx` VALUES ('4', 'AC110V');
INSERT INTO `zdqdyflxx` VALUES ('5', 'AC220V');
INSERT INTO `zdqdyflxx` VALUES ('6', 'DC90V');
INSERT INTO `zdqdyflxx` VALUES ('7', ' DC110V');
INSERT INTO `zdqxh` VALUES ('1', '');
INSERT INTO `zdqxh` VALUES ('2', 'DZE-14EB2');
INSERT INTO `zdqxh` VALUES ('3', 'DZE-14EA');
INSERT INTO `zdqxh` VALUES ('4', 'DZE-14EB2S');
INSERT INTO `zdqxh` VALUES ('5', 'DZE-14EAS');
INSERT INTO `zdqxh` VALUES ('6', 'DZE-16E3B2(上出线）');
INSERT INTO `zdqxh` VALUES ('7', 'DZE-16E3B2(下出线）');
INSERT INTO `zdqxh` VALUES ('8', 'DZE-16E3B2A(上出线）');
INSERT INTO `zdqxh` VALUES ('9', 'DZE-16E3B2A(下出线）');
INSERT INTO `zdqxh` VALUES ('10', 'WYT-TA.3（10簧）');
INSERT INTO `zdqxh` VALUES ('11', 'WYT-TA.3（12簧）');
INSERT INTO `zdqxh` VALUES ('12', 'WYT－TA.3A（8簧）');
INSERT INTO `zdqxh` VALUES ('13', 'WYT－TA.3A（10簧）');
INSERT INTO `zdqxh` VALUES ('14', 'WYT-TA.3-YA');
INSERT INTO `zdqxh` VALUES ('15', 'WYT-U.3');
INSERT INTO `zdqxh` VALUES ('16', 'WYT-U.3（2吨以下）');
INSERT INTO `zdqxh` VALUES ('17', '16E3B2A');
INSERT INTO `zdqxh` VALUES ('18', 'BLB');
INSERT INTO `zdqxh` VALUES ('19', '14EB2');
INSERT INTO `zdqxh` VALUES ('20', '14EA');
INSERT INTO `zdqxh` VALUES ('21', '16E3B2');
INSERT INTO `zdqxh` VALUES ('22', 'WYT-U.3(2T以下）');
INSERT INTO `zdqxh` VALUES ('23', 'DZE-16E3B2A');
INSERT INTO `zdqxh` VALUES ('24', 'DZE-16E3B2');
INSERT INTO `zdqxh` VALUES ('25', 'WYT-U.3(2T）');
INSERT INTO `zdqxh` VALUES ('26', 'WYT-TAM.3');
INSERT INTO `zjdy` VALUES ('1', '');
INSERT INTO `zjdy` VALUES ('2', '220');
INSERT INTO `zjdy` VALUES ('3', '380');
INSERT INTO `zjdy` VALUES ('4', 'AC220V');
INSERT INTO `zjdy` VALUES ('5', 'AC380V');
INSERT INTO `zjdy` VALUES ('6', 'AC380');
INSERT INTO `zjys` VALUES ('1', '');
INSERT INTO `zjys` VALUES ('2', '红色');
INSERT INTO `zjys` VALUES ('3', '中酞兰');
INSERT INTO `zjys` VALUES ('4', '黄色');
INSERT INTO `zjys` VALUES ('5', '开普蓝RAL5019');
INSERT INTO `zjys` VALUES ('6', '银灰色');
INSERT INTO `zjys` VALUES ('7', '电机灰（船牌色卡号510）');
INSERT INTO `zjys` VALUES ('8', '豆绿色');
INSERT INTO `zjys` VALUES ('9', '煤灰色-黑色水性漆（RAL7016）');
INSERT INTO `zjys` VALUES ('10', '朱红色（GSB05-1426-2001 61R02）');
INSERT INTO `zjys` VALUES ('11', '信号黑色-黑色水性漆（RAL9004）');
INSERT INTO `zjys` VALUES ('12', '墨绿色');
INSERT INTO `zjys` VALUES ('13', '信号黑色');
INSERT INTO `zjys` VALUES ('14', '电机灰');
INSERT INTO `zjys` VALUES ('15', '银灰');
INSERT INTO `zjys` VALUES ('16', '煤灰色');
INSERT INTO `zjys` VALUES ('17', 'BG04鲜绿色');
INSERT INTO `zjys` VALUES ('18', '海蓝环保水性自干漆');
INSERT INTO `zjys` VALUES ('19', '煤灰色红色接线盒');
INSERT INTO `zjys` VALUES ('20', '煤灰色接线盒红色');
INSERT INTO `zjys` VALUES ('21', '煤灰色 红色接线盒');
INSERT INTO `zzs` VALUES ('1', '');
INSERT INTO `zzs` VALUES ('2', '抚顺');
INSERT INTO `zzs` VALUES ('3', '佛山');
INSERT INTO `zzs` VALUES ('4', '苏州');
