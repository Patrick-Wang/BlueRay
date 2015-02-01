/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50621
Source Host           : localhost:3306
Source Database       : bluelightplm

Target Server Type    : MYSQL
Target Server Version : 50621
File Encoding         : 65001

Date: 2015-01-31 22:02:46
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
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of bmqxhflxx
-- ----------------------------
INSERT INTO `bmqxhflxx` VALUES ('1', '');
INSERT INTO `bmqxhflxx` VALUES ('2', '海1387');
INSERT INTO `bmqxhflxx` VALUES ('3', '多8192');
INSERT INTO `bmqxhflxx` VALUES ('4', '海1313');
INSERT INTO `bmqxhflxx` VALUES ('5', '海1321');
INSERT INTO `bmqxhflxx` VALUES ('6', '无');

-- ----------------------------
-- Table structure for bpqxhflxx
-- ----------------------------
DROP TABLE IF EXISTS `bpqxhflxx`;
CREATE TABLE `bpqxhflxx` (
  `bpqxhID` int(11) NOT NULL AUTO_INCREMENT,
  `bpqxh` char(100) NOT NULL,
  PRIMARY KEY (`bpqxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of bpqxhflxx
-- ----------------------------
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

-- ----------------------------
-- Table structure for bzxdtgg
-- ----------------------------
DROP TABLE IF EXISTS `bzxdtgg`;
CREATE TABLE `bzxdtgg` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `bzxdtgg` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of bzxdtgg
-- ----------------------------
INSERT INTO `bzxdtgg` VALUES ('1', '');
INSERT INTO `bzxdtgg` VALUES ('2', 'WYT-S包装底盘(170)');
INSERT INTO `bzxdtgg` VALUES ('3', 'Y2D包装箱底盘');
INSERT INTO `bzxdtgg` VALUES ('4', 'WYT-S包装底盘(140)');
INSERT INTO `bzxdtgg` VALUES ('5', 'WYT－U－BZX.1包装底盘');
INSERT INTO `bzxdtgg` VALUES ('6', 'WYT-TA包装底盘(170)');
INSERT INTO `bzxdtgg` VALUES ('7', 'BOMCO4(H)-BZX.1包装底盘');
INSERT INTO `bzxdtgg` VALUES ('8', 'WYT-TA主机包装箱(免熏蒸)(170)');
INSERT INTO `bzxdtgg` VALUES ('9', 'WYT-S包装箱(出口)(140)');
INSERT INTO `bzxdtgg` VALUES ('10', 'WYT-S包装箱(出口)(170)');
INSERT INTO `bzxdtgg` VALUES ('11', 'WYT-TA/T出口主机包装箱(140)');
INSERT INTO `bzxdtgg` VALUES ('12', 'Y1C包装箱底盘');
INSERT INTO `bzxdtgg` VALUES ('13', 'WYT-TA/T出口主机包装箱(170)');
INSERT INTO `bzxdtgg` VALUES ('14', 'WYT-Y1C出口主机包装箱');
INSERT INTO `bzxdtgg` VALUES ('15', 'WYT-Y2D出口主机包装箱');
INSERT INTO `bzxdtgg` VALUES ('16', 'WYT-TA三洋包装底盘');
INSERT INTO `bzxdtgg` VALUES ('17', 'WYT-S主机包装箱(康力出口)(170)');
INSERT INTO `bzxdtgg` VALUES ('18', 'WYT-S主机包装箱(康力)(170)');
INSERT INTO `bzxdtgg` VALUES ('19', 'WYT-Y1C主机包装箱(康力出口)');
INSERT INTO `bzxdtgg` VALUES ('20', 'WYT-Y2D主机包装箱(康力出口)');
INSERT INTO `bzxdtgg` VALUES ('21', 'WYT-S主机包装箱(康力)(140)');
INSERT INTO `bzxdtgg` VALUES ('22', 'WYT-TA主机包装箱(免熏蒸)(140)');
INSERT INTO `bzxdtgg` VALUES ('23', 'WYT-S主机包装箱(康力出口)(140)');
INSERT INTO `bzxdtgg` VALUES ('24', 'WYT-Y1AS出口主机包装箱(单绕)');
INSERT INTO `bzxdtgg` VALUES ('25', 'TA包装箱底盘(通用)(140)');
INSERT INTO `bzxdtgg` VALUES ('26', 'TA包装箱底盘(通用)(170)');
INSERT INTO `bzxdtgg` VALUES ('27', 'TA出口包装箱(2层)(140)');
INSERT INTO `bzxdtgg` VALUES ('28', 'TA出口包装箱(2层)(170)');
INSERT INTO `bzxdtgg` VALUES ('29', 'S出口包装箱(2层)(140)');
INSERT INTO `bzxdtgg` VALUES ('30', 'S出口包装箱(2层)(170)');
INSERT INTO `bzxdtgg` VALUES ('31', '康力U机出口包装箱');
INSERT INTO `bzxdtgg` VALUES ('32', 'WYT-U出口包装箱(2层)');
INSERT INTO `bzxdtgg` VALUES ('33', 'TAM包装箱（锁扣）');
INSERT INTO `bzxdtgg` VALUES ('34', 'Y2D出口包装箱（2层）');
INSERT INTO `bzxdtgg` VALUES ('35', 'Y1C出口包装箱（2层）');
INSERT INTO `bzxdtgg` VALUES ('36', '三洋TA出口包装箱(2层)');
INSERT INTO `bzxdtgg` VALUES ('37', 'TAM出口包装箱（2层）');
INSERT INTO `bzxdtgg` VALUES ('38', 'U包装箱底盘（舌扣）');
INSERT INTO `bzxdtgg` VALUES ('39', '舌扣包装底盘（140）');
INSERT INTO `bzxdtgg` VALUES ('40', '舌扣包装底盘（170）');
INSERT INTO `bzxdtgg` VALUES ('41', 'TAM出口免熏蒸包装箱');



-- ----------------------------
-- Table structure for cpggxhxx
-- ----------------------------
DROP TABLE IF EXISTS `cpggxhxx`;
CREATE TABLE `cpggxhxx` (
  `cpggxhID` int(11) NOT NULL AUTO_INCREMENT,
  `gg` char(100) NOT NULL,
  PRIMARY KEY (`cpggxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=517 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of cpggxhxx
-- ----------------------------
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
-- Records of ddztb
-- ----------------------------
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
  `zjdyID` int(11) DEFAULT NULL,
  `zjysID` int(11) DEFAULT NULL,
  `zdqxhID` int(11) DEFAULT NULL,
  `zyz` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT 'Y',
  `bzxdtggID` int(11) DEFAULT NULL,
  `gh` char(16) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `zzsID` int(11) DEFAULT NULL,
  `khqyID` int(11) DEFAULT NULL,
  `sftgywsh` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `sftgjhsh` char(1) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  `yxj` int(8) DEFAULT '10',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of htxx
-- ----------------------------

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
-- Records of khcyxxb
-- ----------------------------
INSERT INTO `khcyxxb` VALUES ('1', '1', '1', 'Y', '1', '1', 'Y', '1', '1', '5m', '8m', '蓝光英文');

-- ----------------------------
-- Table structure for khqy
-- ----------------------------
DROP TABLE IF EXISTS `khqy`;
CREATE TABLE `khqy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `khqy` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of khqy
-- ----------------------------
INSERT INTO `khqy` VALUES ('1', '');
INSERT INTO `khqy` VALUES ('2', 'YA');
INSERT INTO `khqy` VALUES ('3', 'YE1');
INSERT INTO `khqy` VALUES ('4', 'YE2');
INSERT INTO `khqy` VALUES ('5', 'YN');
INSERT INTO `khqy` VALUES ('6', 'YS');
INSERT INTO `khqy` VALUES ('7', 'YW');

-- ----------------------------
-- Table structure for khxx
-- ----------------------------
DROP TABLE IF EXISTS `khxx`;
CREATE TABLE `khxx` (
  `clientID` int(11) NOT NULL AUTO_INCREMENT,
  `khmc` char(255) NOT NULL,
  `khcz` char(255) DEFAULT NULL,
  `lxr` char(255) DEFAULT NULL,
  `lxdh` char(255) DEFAULT NULL,
  `qtnr` char(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`clientID`)
) ENGINE=InnoDB AUTO_INCREMENT=492 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of khxx
-- ----------------------------
INSERT INTO `khxx` VALUES ('1', '北京航天金羊电梯有限公司', '北京通州区永乐经济开发区(河北省廊坊市)', '徐智健1113969966 赵爽1383369631', null, '010-80114178');
INSERT INTO `khxx` VALUES ('2', '北京升华电梯有限公司', '北京市顺义区京密路西牛栏山段7号', '孙峰 1366363860  010-1138899-1103传真 舒薇熹010-1398899-1101', null, '010-69410840');
INSERT INTO `khxx` VALUES ('3', '北京升华北京分公司', '北京市朝阳区大郊亭中街2号院华腾国际甲5#2楼', '罗学铸 010-1836903 1101036169', null, '010-87912909');
INSERT INTO `khxx` VALUES ('4', '北京九方基业电梯设备有限公司', '北京市丰台区嘉园一里3号楼601室', '010-8916318朱方伍', null, null);
INSERT INTO `khxx` VALUES ('5', '北京宏立电梯服务中心', '北京市岩庆县东外大街建业胡同经济委员会1楼电梯服务公司', '李臣勇1390131939', null, '010-87893084');
INSERT INTO `khxx` VALUES ('6', '北京恒富隆机电部设备安装有限公司', '北京通州区马驹桥新海东路2号院8号楼722', '010-6019810杜力亚1380166988', null, '010-60193811');
INSERT INTO `khxx` VALUES ('7', '北京雍和瑞景物业管理有限公司', '北京东城区安定门东大街28号B座15层', '蔡鹏飞13901101838', null, '010-64079983');
INSERT INTO `khxx` VALUES ('8', '华升富士达', '北京东城区新中街68号聚龙花园8A楼102室', '010-61116688崔学工', null, '010-61122332');
INSERT INTO `khxx` VALUES ('9', '北京燕园图新电梯自动化技术有限公司', '北京海淀区上地南路10号院1号楼首层12-6号', '刘媛010-83903810', null, '010-62978231');
INSERT INTO `khxx` VALUES ('10', '北京金前锋电梯有限公司第三技术服务有限公司', '北京', null, null, null);
INSERT INTO `khxx` VALUES ('11', '莫尼克电梯制造(北京)有限公司', '亦庄经济技术开发区东区同和路', '周法国010-89396910', null, null);
INSERT INTO `khxx` VALUES ('12', '莫尼克电梯制造(北京)有限公司', '北京市朝阳区广汇门外大街8号优士阁西座12B10', '010-18613911', null, null);
INSERT INTO `khxx` VALUES ('13', '广东台日电梯有限公司北京分公司', '北京市丰台区三路居凤凰嘴53号', '任宏13911166383', null, '010-66011801');
INSERT INTO `khxx` VALUES ('14', '北京百斯特尔电梯有限公司', '北京市丰台区华源三里16号楼3单元101', '夏经理13901001933', null, '010-63379733');
INSERT INTO `khxx` VALUES ('15', '北京雍和瑞景物业管理有限公司(时代龙和代)', '北京市东城区秦老胡同甲16号', '贾炜   13366396998', null, null);
INSERT INTO `khxx` VALUES ('16', '北京多嘉通电梯有限公司', '北京朝阳区潘家园松榆西里五十六楼四门202室(发票接收)', '李世晓139-01306691 王树苹(发票)010-69366193', null, '010-87390662');
INSERT INTO `khxx` VALUES ('17', '北京中铁电梯工程有限公司', '北京市丰台区张仪村路16号中铁建设集团办公西区电梯公司', '李祖章13601019681 010-11881301', null, '010-11881268');
INSERT INTO `khxx` VALUES ('18', '北京挚诚恒远电梯有限责任公司', '北京市朝阳区小营路10号阳明广场C座9F', '艾宪岭13901311330', null, null);
INSERT INTO `khxx` VALUES ('19', '北京金宇联合设备安装有限公司', '北京市海淀区中关村南大街12号卉园大楼A401', '康建\0Z010-63139389', null, null);
INSERT INTO `khxx` VALUES ('20', '北京首都电梯厂', '北京市朝阳区东坝乡娘娘庙后街', '丰毅武010-61693661', null, null);
INSERT INTO `khxx` VALUES ('21', '北京佳友恒泰机电设备有限公司', '北京市丰台区友安门外开阳里三区1号楼3单元101号', '刘继林010-63163916 13901093911', null, null);
INSERT INTO `khxx` VALUES ('22', '北京优力维特电梯有限公司(与佳友恒泰一家)', '北京市丰台区友安门外开阳里三区1号楼3单元101号', '刘继林010-63163916 13901093911', null, null);
INSERT INTO `khxx` VALUES ('23', '北京怡达和谐电梯有限责任公司', '北京市朝阳区望花路西八间北里163号楼三层', '水文13810963398 010-66961936', null, '010-64741724');
INSERT INTO `khxx` VALUES ('24', '北京南方恒力电梯工程有限公司', '北京市朝阳区北苑路大屯里小区115楼2409室', '管建民13301301806 010-86803866', null, null);
INSERT INTO `khxx` VALUES ('25', '北京升华电梯集团有限公司黑龙江省分公司', '哈尔滨市南岗区长江路65号723室', '王威0611-83031989 马明艳0611-83031899', null, '0411-83021767');
INSERT INTO `khxx` VALUES ('26', '北京金菱恒达电梯设备有限公司', '北京市朝阳区西大望路平乐园10号', '刘会玲010-69980130', null, null);
INSERT INTO `khxx` VALUES ('27', '北京北安时代电梯安装公司', '北京市朝阳区百子湾南二路76号院7号楼3单元', '黄建峰13901086100', null, '0379-63216612');
INSERT INTO `khxx` VALUES ('28', '北京北方鑫奥电梯有限公司', '北京市朝阳区西大望路19号金港园国际8栋1单元103号', '顾爱民13901399366 010-89916908-606/010-89916918-606', null, '010-87716416');
INSERT INTO `khxx` VALUES ('29', '北京安捷利达', '北京市西城区黄寺大街23号6号楼1层3号（德胜园区）', '段晓林010-83339631/13311316918', null, null);
INSERT INTO `khxx` VALUES ('30', '北京捷尔斯', '北京市丰台区南顶路6号院', '周海军13910919981', null, null);
INSERT INTO `khxx` VALUES ('31', '北京斯迈普电梯有限公司', '北京市丰台区右安门外大街2号楼迦南大厦1303室', '史永明010-6319 1830  18910633930', null, null);
INSERT INTO `khxx` VALUES ('32', '北京华菱鑫奥电梯有限公司', '北京市大兴区西红门宏盛园22-4-102', '袁志伦13311119381', null, null);
INSERT INTO `khxx` VALUES ('33', '北京铂铠星奥电梯设备有限公司', '北京市丰台区星河苑1号院24号楼501', '李德志 010-69136133 13011398361', null, null);
INSERT INTO `khxx` VALUES ('34', '苏州飞腾北京分公司', '北京市西城区三里河路40号院4号楼502', '梁小波13601300339', null, null);
INSERT INTO `khxx` VALUES ('35', '北京广船伟华机电设备有限公司', '北京市海淀区龙翔路4号1611', '廉振英 13910836636  010-83098969', null, null);
INSERT INTO `khxx` VALUES ('36', '天津宏翔电梯有限公司', '天津市西青区辛口镇水高庄工业园2号院', '陈龙033-36396363  13803019913', null, '022-26374243');
INSERT INTO `khxx` VALUES ('37', '天津市盛诚电梯装璜有限公司', '天津市河北区宜白路玉琢里后下卫道88号', '周大立13103136189', null, '022-26710338');
INSERT INTO `khxx` VALUES ('38', '天津中江公司', '天津市河西区福建路福盛花园物业办公楼', '孟德艳033-33330318', null, null);
INSERT INTO `khxx` VALUES ('39', '天津奥富特电梯有限公司', '天津市北辰区津围公路LG电子对面 北辰科技园 景观路', '吴刚11803396069', null, '022-86313711');
INSERT INTO `khxx` VALUES ('40', '天津市澳士达电梯销售有限公司', '天津市南开区庆丰路十号', '辛云刚13831619008', null, null);
INSERT INTO `khxx` VALUES ('41', '天津市塘沽区同正电梯有限公司', '塘沽区贻成东园13号楼1门102', '程恩全13930136339   033-66361099（传真）', null, '022-21301614说明给同正发传真');
INSERT INTO `khxx` VALUES ('42', '天津市得利信电梯有限公司', '收货地址:天津市西青区张窝(津涞公路距津沧高速公路200米)于建军 13920176035', '张书信033-38368666*13930830190', null, '022-28348646');
INSERT INTO `khxx` VALUES ('43', '天津玉泰实业有限公司', '天津东丽开发区三纬路与一经路交口', '刘士琴033-36991999', null, null);
INSERT INTO `khxx` VALUES ('44', '天津市盛强电梯有限公司', '北辰区宜兴埠津围公路107号', '033-86313309 魏有祥', null, null);
INSERT INTO `khxx` VALUES ('45', '天津东南电梯销售有限公司', '天津河西区友谊路增进道22号', '发票:杨伟颖033-38369983-83 毛卫兵033-38369983-803', null, '022-28367880');
INSERT INTO `khxx` VALUES ('46', '天津市康通电梯销售有限公司', '天津市河西区黑牛城道纪发公寓增1号', '赵玉娟 033-33916919 33963960王建才 38333131', null, '022-28322121');
INSERT INTO `khxx` VALUES ('47', '天津市津翔电梯厂巨星机电工程公司', '天津市北辰区双街镇郎园工业区', '孙岳云86816938-8006陈祥义033-36980916', null, '022-26980912');
INSERT INTO `khxx` VALUES ('48', '天津市津翔巨星电梯制造有限公司', '天津市北辰区双街镇郎园工业区', '吴凤来11900369136 座机18930911861 033-36980919 033-36980913', null, '022-26980912');
INSERT INTO `khxx` VALUES ('49', '天津市中迅赛勒瓦电梯有限公司', '河西区紫金山路澳隆花园C-5-601', '033-88391361龚健13116130199', null, '022-88294944');
INSERT INTO `khxx` VALUES ('50', '天津市三志电梯有限公司', '西青区大寺镇北口村', '周惠亭033-33990313*33960010', null, '022-23970213');
INSERT INTO `khxx` VALUES ('51', '天津市同兴电梯有限公司', '天津市河东区12经路13号501-506室', '韩金旭13903193131  033-36319363 宋经理13830991116', null, '022-24317376');
INSERT INTO `khxx` VALUES ('52', '天津莱茵克拉电梯有限公司', null, '39363100', null, '022-29229100');
INSERT INTO `khxx` VALUES ('53', '天津奥斯达电梯有限公司', '天津市大寺镇北里八口村', '（收货 EMS发票）黄文朝033-83983313*13803003311 王利花11033063663', null, '022-83983313');
INSERT INTO `khxx` VALUES ('54', '天津津奥电梯有限公司', '天津市河西区宾馆南道4号', '陆毅 13633091600 033-38310806', null, null);
INSERT INTO `khxx` VALUES ('55', '柏岱斯蒂(天津)机械有限公司', '天津市北辰开发区双源科技园', '万宁033-3698098 0    0698     0981', null, '022-26980983');
INSERT INTO `khxx` VALUES ('56', '天津西玛格电梯制造有限公司', '天津北辰区宜兴埠京津塘高速公路东', '033-86311911/033-86313911 赵跃华(13830019681 033-86816393)', null, '022-86311911');
INSERT INTO `khxx` VALUES ('57', '天津西玛格电梯有限公司', '天津市东丽区金钟街南孙庄新河北', '董玉斌033-86816393/13003333666', null, null);
INSERT INTO `khxx` VALUES ('58', '天津联恒克劳斯电梯有限公司', '天津大港经济开发区安和路433号', '郭鑫义13831191383/033-19918319', null, '022-19718360');
INSERT INTO `khxx` VALUES ('59', '天津市恒晟自动化工程有限公司', '天津红桥区丁字沽一号路泛洋大厦2-2206室', '刘淞033-36110030/36168313', null, '022-26148312');
INSERT INTO `khxx` VALUES ('60', '天津市联星电梯有限公司', '天津市河北区胜利路琴海公寓1号楼1门1007室', '王吉元13116089989/033-60131968', null, '022-60131749');
INSERT INTO `khxx` VALUES ('61', '天津市恒利电梯技术开发有限公司', '发票寄天津办（张冠健） 刘斌去取', '刘斌13683003988', null, '022-60111012');
INSERT INTO `khxx` VALUES ('62', '天津市永诚电梯有限公司', '天津市津南区双港工业园一号路', '范连成13803061069', null, '28171166');
INSERT INTO `khxx` VALUES ('63', '天津冠辉安装工程有限公司', '天津市河西区友谊北路广银大厦1209室', '李俊祥 13683198038  李强13831981636  033-33361999', null, '022-23233101-82');
INSERT INTO `khxx` VALUES ('64', '天津海通电梯有限公司', null, '刘11900318116', null, '022-23122078');
INSERT INTO `khxx` VALUES ('65', '天津永成电梯有限公司', '天津市津南区梨双路双港工业园区1号路2号', '033-38191333 范瑞成(13389039999)', null, null);
INSERT INTO `khxx` VALUES ('66', '天津赛福伟业电梯技术有限公司', '天津市西青区侯台村碧欣园B区2号楼3门302', '翟军13930801666', null, null);
INSERT INTO `khxx` VALUES ('67', '天津市新奥翔电梯安装维修配件中心', '天津市河北区三马路77号', '郭玉武13803091139', null, '022-26663291');
INSERT INTO `khxx` VALUES ('68', '天津菱奥宏达电梯有限公司', '天津市北辰区文化中心图书馆B座509室', '李辉13903133399 033-36838169', null, null);
INSERT INTO `khxx` VALUES ('69', '天津市中颖电梯有限公司', '天津市南开区北城街金轩商务中心1号楼2505室', '张洋18930611999', null, '022-86660722');
INSERT INTO `khxx` VALUES ('70', '天津泰福电梯安装工程有限公司', '天津市和平区青海路46号', '梅纯13930809933', null, '022-27819110');
INSERT INTO `khxx` VALUES ('71', '天津西北电梯安装有限公司', '天津市河西区友谊路增进道22号', '办公室033-38138396', null, '022-28367782');
INSERT INTO `khxx` VALUES ('72', '天津市奥博电梯销售有限公司', '天津市河东区中山门互助南里23-4号底商 发票地址:河东区华兴道月光园6-2-101', '李永财033-86361933 李小姐(发票)13913983016', null, null);
INSERT INTO `khxx` VALUES ('73', '天津辽富电梯有限公司', '天津市河北区王串场五号路盛宇里15号110门305室', '刘恒宇13313039983', null, null);
INSERT INTO `khxx` VALUES ('74', '天津市欧科电梯有限公司', '天津市北辰区铁东路(铁东北路)天盈道16号', '王志祥13930910809 刘戈雷：13803089311', null, '022-26992331');
INSERT INTO `khxx` VALUES ('75', '天津铃木电梯工程有限公司', '发票:天津市南开区西湖道风荷园1号楼4门902室', '张丽明033-39610338', null, null);
INSERT INTO `khxx` VALUES ('76', '天津方景电梯工程有限公司', '天津市东丽区昆仑路临月里6号楼2门501室', '李蓓  13831118601', null, null);
INSERT INTO `khxx` VALUES ('77', '天津市科苑电梯配件有限公司', '天津市河西区大沽南路洪泽花园7号楼1门101', '于艳民033-88363808', null, '022-88262808');
INSERT INTO `khxx` VALUES ('78', '天津市茗熔机电设备销售中心', '天津市南开区密云路与黄河道交汇西南侧北方城一区36栋105', '金先生033-39361180、13803061601', null, null);
INSERT INTO `khxx` VALUES ('79', '天津宏大', '天津市河北区养鱼池路3号（第二印染厂院内）', '赵宏光13930661996', null, null);
INSERT INTO `khxx` VALUES ('80', '天津唯思电梯技术服务有限公司', '天津市河西区九华山路蓝水园1-2-601', '陈化平033-83831113  18019193   18930691393', null, '022-83831113');
INSERT INTO `khxx` VALUES ('81', '天津奥瑞克机电有限公司', '天津东丽开发区五纬路与一经路交口', '王炳清033-36991999', null, null);
INSERT INTO `khxx` VALUES ('82', '天津合峰电梯有限公司', '天津市和平区西康路赛顿中心C座12层通力电梯公司', '段秀兰13913610068', null, null);
INSERT INTO `khxx` VALUES ('83', '辽宁北富电梯有限公司（原铁岭北方富士）', '铁岭县新台子镇懿路工业园区', '总经理:张洪举13960696801                                  常帅036-98811830、8811831', null, '024-8811820');
INSERT INTO `khxx` VALUES ('84', '铁岭北方富士电梯有限公司（驻沈阳办事处）-收货 发票', '沈阳市大东区老瓜堡西路14-5号8门', '赵杨杨13860061610 常小姐 036-88316663/036-98811830', null, null);
INSERT INTO `khxx` VALUES ('85', '沈阳申菱电梯维修有限公司', '沈阳市沈河区北站路78号邮政大厦转电梯何连华', '何连华33193339', null, null);
INSERT INTO `khxx` VALUES ('86', '沈阳沃可斯电梯有限公司', '沈阳市于洪区银山路59号', '方坤89331398 董智聪(收货） 孙斌 王雪（发票）86613631 李沛收 86693390', null, '024-86673891');
INSERT INTO `khxx` VALUES ('87', '沈阳捷迅电梯有限公司（沈阳泰特电梯有限公司）', '辽宁省抚顺市经济开发区中兴大街（七号街西侧B4b区）', '庞丽丹036-13818899', null, '13818811');
INSERT INTO `khxx` VALUES ('88', '沈阳长城电梯厂', '沈阳市沈河区方家栏路76号甲', '曲界殊13806998899  36316818 发票:财务吉明淑 81306009/36318398', null, null);
INSERT INTO `khxx` VALUES ('89', '沈阳西菱奥电梯工程有限公司', '沈阳市铁西区兴工街93-3  9门兴隆苑', '周龙18609816169', null, null);
INSERT INTO `khxx` VALUES ('90', '沈阳菱诺自动化设备有限公司', '沈阳市浑南新区高科路39号', '宋阳13960001398 王晓冬13960091989', null, '024-23783919');
INSERT INTO `khxx` VALUES ('91', '沈阳翰溟先达', '沈阳市沈河区惠工街157号362', '张海雁   13333610391', null, null);
INSERT INTO `khxx` VALUES ('92', '沈阳优力维特电梯制造厂', '沈阳市和平区十三纬路23号邵文君23857536/81090222                      发货地址：沈阳市东陵区民族经济开发区民旺路18号辽海机械厂院内（绕城高速下河湾收费口左转）', '吴绍东036-33896619`33896613  *13960660690   33909131技术杨玉海13136306106采购王宇13960068831 33909131 传真：33909131', null, '23707121  23876419');
INSERT INTO `khxx` VALUES ('93', '沈阳市横滨电梯厂', '铁西云峰街88506146-809财务', '周国刚88111880 13906039866                      周国强13106991399//88101331', null, '88106140');
INSERT INTO `khxx` VALUES ('94', '沈阳西奥电梯制造有限公司', '沈阳大东区大北街86-92号魅力大厦6楼', '陈文国13906039699 81196911 马桂英11860309666', null, '024-88106140');
INSERT INTO `khxx` VALUES ('95', '沈阳三洋电梯安装分公司', null, '胡宽胜13906006601 38909890 王美清13666061190', null, '024-88097893');
INSERT INTO `khxx` VALUES ('96', '辽宁三洋', '沈阳市于洪区银山路59号5楼', '马学杰 86606989 13998833386', null, '024-86601391');
INSERT INTO `khxx` VALUES ('97', '辽宁三洋(营口)', '营口市西市区科飞路33号', '李元春 13960911381  沈锦营11961911968', null, '0417-6669161');
INSERT INTO `khxx` VALUES ('98', '辽宁北方三洋电梯制造有限公司', '沈阳市皇姑区百花山路1-4号', '焦清惠（焦总）13906018339 86118691 86131963', null, '86121743');
INSERT INTO `khxx` VALUES ('99', '沈阳博林特电梯有限公司（老厂区）', '沈阳市东陵区东陵路30-2号', '杨恒88616986 11006060691 88616696 88616618              唐行涛 88616918   13019391016', null, '88416420');
INSERT INTO `khxx` VALUES ('100', '沈阳博林特电梯有限公司(新厂区)', '沈阳市经济技术开发区开发大道27#(16号街 博林特电梯) 发票都寄到新厂区', '杨恒11006060691  兰天 31163936  13889399133', null, '21162110');
INSERT INTO `khxx` VALUES ('101', '沈阳正通电梯配件有限公司', '沈阳虎石台经济开发区兴隆街26号', '郑徽13313633333/89913819张工 63331199', null, '89712819');
INSERT INTO `khxx` VALUES ('102', '沈阳市兰菱电梯维修中心', '沈阳市北站路78号邮政大厦转电梯', '何联华13386880608', null, null);
INSERT INTO `khxx` VALUES ('103', '沈阳富士电梯有限公司', '于洪区凌东街153号', '于学光13860331309姜在峰（86891311 86601333 13998181119 传真：86601333）红楼一楼  姜思伦 86601681 13898116833', null, '22733918');
INSERT INTO `khxx` VALUES ('104', '沈阳川菱', '沈阳和平区青年大街386号华阳国际大厦A座D957 发票地址:沈阳市东陵区浑河民族经济技术开发区新立8号', '孙桂芝33180196*33918666总经理刘湛13333669969', null, '23718068*23180196');
INSERT INTO `khxx` VALUES ('105', '沈阳金都饭店', null, '高学鹏13898166099', null, null);
INSERT INTO `khxx` VALUES ('106', '沈阳百越电梯公司', null, '33313969岳13003613306', null, null);
INSERT INTO `khxx` VALUES ('107', '沈阳多维自控技术有限公司', null, '王晓光86396099', null, null);
INSERT INTO `khxx` VALUES ('108', '沈阳元和电梯有限公司', '沈阳市市府大路290号1-11-3摩根凯利', '于志刚13998161069', null, '024-22743922');
INSERT INTO `khxx` VALUES ('109', '沈阳蓝兴电梯公司', null, '张岩13900031199/81869901', null, '86241818');
INSERT INTO `khxx` VALUES ('110', '沈阳东迅电梯有限公司', null, '万经理13898169633/89139891', null, '89139871');
INSERT INTO `khxx` VALUES ('111', '沈阳市菱通电梯服务中心', '沈阳市大东区沈铁路52号5门', '梁昆莉88339119 88096163', null, null);
INSERT INTO `khxx` VALUES ('112', '沈阳新圣亚超硬合金工具有限公司', '沈阳市和平区文化路44号', '马红梅13386836199 33898968', null, null);
INSERT INTO `khxx` VALUES ('113', '沈阳智健精工电梯装饰有限公司', '沈阳市于洪区陵东乡田义村  发货地址：于洪区鸭绿江北街（过二环打电话）', '董仲军13860019810 63609691', null, '024-62609671');
INSERT INTO `khxx` VALUES ('114', '沈阳凤翥楼宇工程有限公司', '发票地址:沈阳市和平区南京南街80号B座1402', '徐红13698868366 33111169', null, null);
INSERT INTO `khxx` VALUES ('115', '辽宁杭奥电梯工程有限公司', '沈阳市皇姑区陵东街83巷10甲号', '肖琦 31303610 发票:于洪耀13998836361', null, null);
INSERT INTO `khxx` VALUES ('116', '辽宁信达电梯有限公司（鑫一达）', '沈阳市皇姑区华山路215号1门4楼财务部', '蒋辉收81191690陈晓龙81819313李长虹13998893999技术吕守彬33939811 13136366333', null, '88072283/78');
INSERT INTO `khxx` VALUES ('117', '辽宁鑫一达电梯有限公司', '沈阳市大东区前进乡大志村', '齐闯88093383张兆旭13806008191', null, '');
INSERT INTO `khxx` VALUES ('118', '沈阳三洋电梯杭州工程有限公司', '杭州市下城区环城北路63号财富中心1703室', '张纯良0191-81863380 13093906019', null, '0171-81863336');
INSERT INTO `khxx` VALUES ('119', '辽宁豪华电梯安装有限公司', '沈阳市和平区西塔北街1号', '高金城11803660606 33691196', null, null);
INSERT INTO `khxx` VALUES ('120', '沈阳汇成电缆集团有限公司', '沈阳市于洪区青海西路41号', null, null, null);
INSERT INTO `khxx` VALUES ('121', '沈阳德信控制设备有限公司', '沈阳市皇姑区陵北街37巷7号', '马丽新036-86313018 13960138086', null, '024-86212018');
INSERT INTO `khxx` VALUES ('122', '沈阳南迅电梯', '沈阳市沈河区北京街19-3号3单元6楼2号', '胡丽民33961911', null, null);
INSERT INTO `khxx` VALUES ('123', '沈阳辽富电梯销售有限公司', null, '于洋13860319966', null, null);
INSERT INTO `khxx` VALUES ('124', '沈阳三洋电梯工程设备有限公司', '沈阳市东北大马路272号', '车金凤13960199010 036-86890636', null, '86908801');
INSERT INTO `khxx` VALUES ('125', '鸿彤园', '大东区204和睦北三路鸿彤园A座3单元9楼', '吴颖 11806060908 11806060896', null, null);
INSERT INTO `khxx` VALUES ('126', '沈阳新力电梯有限公司', '沈阳市皇姑区昆山中路2号18-1', '姜跃权 13306000839', null, null);
INSERT INTO `khxx` VALUES ('127', '辽宁富士袁总', '沈阳市皇姑区银山路59号307室', '王小姐86609618  韩工 13889363133  袁英芳（发票）', null, null);
INSERT INTO `khxx` VALUES ('128', '辽宁富士张总', '沈阳市于洪区银山路59号309室', '张松岩13909839033', null, null);
INSERT INTO `khxx` VALUES ('129', '大连方州电梯工程有限公司', '大连市中山区民生街宏爱巷1号18楼1号', '王洪新', null, null);
INSERT INTO `khxx` VALUES ('130', '大连富士电梯有限公司', '大连市沙河口区连胜街82号城市公园A座1506室', '范本吏13313391199 0611-86133999', null, '0411-84121327');
INSERT INTO `khxx` VALUES ('131', '大连得利电梯制造有限公司', '瓦房店市得利寺镇', '倪云春13963839360', null, '0411-81320028');
INSERT INTO `khxx` VALUES ('132', '大连通用电梯公司(大连正华电梯有限公司)', '中山区大众街9号', '邵力0611-83906309 13906380980                  蒋红敏13961138899                              李树博13863618936  0611-83931330', null, '0411-82704207');
INSERT INTO `khxx` VALUES ('133', '大连顺达电梯有限公司', '沙河口区工华街17号三丰大厦326房', '刘绍亮  13998616098  0611-86899088/89                        刘绍钦83989139', null, '0411-86897088');
INSERT INTO `khxx` VALUES ('134', '大连亨泰机电工程有限公司', '大连沙河口区西南路304号三门栋5楼3号', '王振有13906083613 13333318090 0611-86331333', null, '0411-87681000');
INSERT INTO `khxx` VALUES ('135', '大连力伏特电梯', '大连市沙河口区中山路538号新希望花园物业转电梯公司', '毛珉   0611-86313300   13960833109', null, null);
INSERT INTO `khxx` VALUES ('136', '大连志诚机电设备有限公司', '大连市中山区北斗街98号', '董世涛(经理)13333303896 0611-83983161 83983163', null, '0411-82783160');
INSERT INTO `khxx` VALUES ('137', '大连百菱电梯有限公司', '大连市西岗区鞍山路13号兴业广场B座308室', '王丽0611-83988033', null, null);
INSERT INTO `khxx` VALUES ('138', '大连凯天机电设备有限公司', '大连市甘井子泉水D1区25号2-1-1', '王盛勋 13963661669  0611-86699160', null, '0411-86477160');
INSERT INTO `khxx` VALUES ('139', '丹东三菱电梯销售有限公司', '丹东市振兴区九纬路85号(辽东宾馆)', '王广林13961138811/0611-3168330', null, null);
INSERT INTO `khxx` VALUES ('140', '丹东浩天经贸有限公司', '丹东市元宝区福海小区2号楼4单元209室', '于忠君13306310968 收货:隋志刚13900118699 0611-3883089', null, null);
INSERT INTO `khxx` VALUES ('141', '丹东盛华电梯服务有限公司', '丹东市振兴区体育馆路上域国际608室', '姜元军18861109966', null, '0411-2216212');
INSERT INTO `khxx` VALUES ('142', '丹东安达电梯厂', '丹东市振兴区福春街24号', '张连生13861181136 0611-3863916 收件人:曲衍模', null, '0411-3862713');
INSERT INTO `khxx` VALUES ('143', '鞍山市商业银行(鞍山市永生电梯服务有限公司)', '鞍山市铁东区五一路15号1515室', '邓永生011906130068   0613-3800931', null, '0412-2231794');
INSERT INTO `khxx` VALUES ('144', '鞍山五环酒店', '鞍山市铁西区南胜利路4号', '张辉13106136991', null, null);
INSERT INTO `khxx` VALUES ('145', '抚顺石化自动化系统技贸有限公司', null, '刘建13106339168', null, '0413-2660812');
INSERT INTO `khxx` VALUES ('146', '朝阳辽西沈阳东芝电梯有限公司', '朝阳市和平街60-9号', '皮井国 张庆国13191863991 0631-3398310 0631-3933666', null, '0421/3273666 0421-6688862');
INSERT INTO `khxx` VALUES ('147', '朝阳三菱电梯销售公司', '朝阳大街2段78号 龙腾商厦', '徐振忠0631-3806119徐世军 13188193030', null, '0421-2819111');
INSERT INTO `khxx` VALUES ('148', '营口航天稀土电机有限公司', '营口市高新技术开发区科飞路33号', '何忠意0619-8883993 财务0619-6893193', null, '0417-6669161');
INSERT INTO `khxx` VALUES ('149', '吉林建兴电梯有限公司', '长春晨光国际大厦B座1116室', '谢万锋13119138611/13119131919/0631-88969991', null, '0431-87821717');
INSERT INTO `khxx` VALUES ('150', '吉林市吉特电梯工程处', '吉林市松江中路65号市政府5号楼', '夏云秀   13963399661   0633-3699088', null, null);
INSERT INTO `khxx` VALUES ('151', '延边天禹电梯有限公司', '延吉市长白路6号怡华家园4楼3单元201室', '何英13116638368 0633-3336168', null, '0433-2236178');
INSERT INTO `khxx` VALUES ('152', '长春锐智电梯销售有限公司', '吉林省长春市经济开发区二区8栋102', '马英慧11963013990', null, null);
INSERT INTO `khxx` VALUES ('153', '长春市利达电梯有限公司', '长春二道区吉盛小区2-5栋', '刘江龙13116310111*0631-86919811', null, '0431-86706104.041184317448');
INSERT INTO `khxx` VALUES ('154', '长春市利升快速机电工程有限公司', '南关区卫星广场民航花园4栋3门102室', '肖刚13863136831/0631-81339689', null, '0431-81081184');
INSERT INTO `khxx` VALUES ('155', '吉林省现代电梯工程有限公司', '长春市宽城区白菊路10号白菊时代华庭4单元807室', '李长庆0631-83993899', null, null);
INSERT INTO `khxx` VALUES ('156', '吉林万里购物广场', '金先生13252523555', null, null, '0432-2412388');
INSERT INTO `khxx` VALUES ('157', '四平交通宾馆', '四平市铁西区站前交通大厦', '姜彪13896606139    普通发票', null, null);
INSERT INTO `khxx` VALUES ('158', '长春东日电梯有限公司', '长春市朝阳经济开发区硅谷大街与超强街交汇 西行200米。', '收货人胡鹏飞13966199313/王和忠(技术条件)13866091369/于婧18963631636', null, '0431-87017318');
INSERT INTO `khxx` VALUES ('159', '长春科达电梯工程有限公司', '寄发票地址:长春市普阳街副81号长春市特种设备监督检验中心', '王鹏云13806661638', null, '0431-8736811/7609976于小姐');
INSERT INTO `khxx` VALUES ('160', '四平凯利特电梯有限公司', '四平市铁东区南一委六马路', '赵生辉13636361096', null, null);
INSERT INTO `khxx` VALUES ('161', '吉林省四平电梯制造有限公司', '吉林省四平铁西区迎宾街北段(红嘴开发区)', '赵生辉0636-3301310朱文龙13606368383', null, '0434-3201210');
INSERT INTO `khxx` VALUES ('162', '四平市庆利电梯设备有限公司', '发货地址:长春经济技术开发区金州街1号宏泰宾馆1210室 发票地址:四平众达塑料纺织有限公司四平铁东区长发路1380号', '王雁飞13331608866 弄阳13863661139/0631-86831133', null, '0431-86821133');
INSERT INTO `khxx` VALUES ('163', '吉林百斯特电梯有限公司', '长春市自由大路4848号北方大厦8层', '潘巨春13019101319/0631-1839999韩光13316306991', null, null);
INSERT INTO `khxx` VALUES ('164', '中油吉林销售分公司', '吉林省白山市通江路24号', '邵国山0639-8993990', null, '0439-3214914');
INSERT INTO `khxx` VALUES ('165', '吉林省海神电梯销售服务有限公司', '长春市百草路221号2栋306室', '李建锋13866060311', null, '0431-88942711');
INSERT INTO `khxx` VALUES ('166', '吉林省委(吉林省事务管理局办公用房维修处)', '吉林省委院内577号', '袁铁峰0631-88903911', null, null);
INSERT INTO `khxx` VALUES ('167', '吉林省世博机电设备安装工程有限责任公司', '长春市普阳街2066号中天大厦308室', '钟玉波0631-81086966', null, null);
INSERT INTO `khxx` VALUES ('168', '吉林省三荣电梯工程有限公司', '吉林省长春市皓月大路739号标记大厦A5-1511室', '邓春艳0631-89831133 13196398880', null, '0431-87821133');
INSERT INTO `khxx` VALUES ('169', '长春福达电梯有限公司', '长春市皓月大路739号标记大厦4单元709室', '崔利萍0631-89936633', null, null);
INSERT INTO `khxx` VALUES ('170', '吉林省国土资源开发集团电梯工程有限公司', '发货：吉林省白城市爱国街2号 白城宾馆 发票：长春市经济开发区仙台大街1468号', '刘长青13106690918', null, null);
INSERT INTO `khxx` VALUES ('171', '长春莱茵电梯有限公司', '长春市长江路69号双龙大厦C单元1208室', '马国平0631-86988911', null, '0431-86788733');
INSERT INTO `khxx` VALUES ('172', '吉林省菱电电梯有限公司', '长春市宽城区辽宁路春铁大厦Ｂ座７０４室', '王焱森13366096999/0631-86099339', null, null);
INSERT INTO `khxx` VALUES ('173', '吉林省榆树市交通小区', '吉林省榆树市港榆小区2号楼7单元302', '刘朝春13316396863 0631-83630311', null, null);
INSERT INTO `khxx` VALUES ('174', '吉林市万星物业管理有限公司', '吉林市厦门街高新2号路亲亲家园北区物业办公室', '韩冰11136131611 0633-66669363', null, null);
INSERT INTO `khxx` VALUES ('175', '哈尔滨市东华机电设备有限公司', '哈尔滨市道外区承德街241号', '任伟东 财务:0611-88380119', null, '0411-83397868');
INSERT INTO `khxx` VALUES ('176', '黑龙江九隆科技开发有限公司', '黑龙江省哈尔滨市香坊区香大街167号', '0611-11666088付振海88113099*13103613099', null, '0411-11646088');
INSERT INTO `khxx` VALUES ('177', '齐齐哈尔东林电梯有限公司', '齐齐哈尔市站前大街206号（齐铁电务段）', '康秀东13100830916。发票：林玉坤13996898316', null, '0412-8061710');
INSERT INTO `khxx` VALUES ('178', '齐齐哈尔建华电梯有限公司', '齐齐哈尔市双华路1号', '13009913999*陈守君3611369', null, '0412-2614746');
INSERT INTO `khxx` VALUES ('179', '哈尔滨莱茵电梯有限公司', '哈尔滨市香坊区哈成路323号', '0611-83010931-861郝绩业83011918齐海1381866991崔经理13009908638代志刚13996008009', null, '0411-82011104');
INSERT INTO `khxx` VALUES ('180', '哈尔滨东方电梯安装工程处', null, '杜福臣13306803308', null, '0411-86229122');
INSERT INTO `khxx` VALUES ('181', '哈尔滨市东北电梯经销有限责任公司', '哈尔滨市道里区钢铁街1号楼', '韩金池0611-86811311', null, '0411-84811822');
INSERT INTO `khxx` VALUES ('182', '哈尔滨市恒益电梯厂', '南岗区哈西大街109号', '崔岳明厂长13906101366 0611-86663638           孙琪86663638/86693639 13903636163', null, '0411-86692429');
INSERT INTO `khxx` VALUES ('183', '哈尔滨中兆迪康电梯制造有限公司', '哈尔滨香坊区中山路162-1号迪康财富大厦7楼', '关春生0611-11198966/13966808991', null, '0411-11198901');
INSERT INTO `khxx` VALUES ('184', '哈尔滨赫力电梯设备经销有限公司', '哈尔滨南岗区赣水路1号齐鲁大厦811', '赵丽君0611-86369636', null, '0411-82628180');
INSERT INTO `khxx` VALUES ('185', '哈尔滨天鹅电梯安装维修有限公司', '哈尔滨市南岗区东大直街151号', '杜万钧0611-83386630 /0611-89130930  王玉珉 13906803910 齐纯德13861066063 刘连英  13906613330', null, '0411-87130630/82286410');
INSERT INTO `khxx` VALUES ('186', '黑龙江省西奥电梯经销有限公司', '哈尔滨市香坊区香坊大街167号', '范彦彬13030018911彬有礼 0611-89931119/11660338', null, null);
INSERT INTO `khxx` VALUES ('187', '黑龙江电梯厂', '哈尔滨市香坊区巴安里街18号', 'EMS 侯权贵 13966839661 0611-83969968  王颜国18666363613', null, '0411-82949768');
INSERT INTO `khxx` VALUES ('188', '哈尔滨上菱电梯有限公司', null, '徐拥军', null, null);
INSERT INTO `khxx` VALUES ('189', '哈尔滨西奥电梯公司', '南岗区花园街201号', '0611-13636081冯驰139366699960611-83013939池学权13319118198丁立农0611-86968981', null, '0411-13626081');
INSERT INTO `khxx` VALUES ('190', '哈尔滨达鑫电梯有限公司', '哈尔滨市南岗区五瑞街10号', '李忠0611-86339966/88618018 霍焱0611-86339966/13696118308', null, '0411-86268604');
INSERT INTO `khxx` VALUES ('191', '黑龙江省利通电梯工程有限公司', null, null, null, '0411-13622478');
INSERT INTO `khxx` VALUES ('192', '哈尔滨铁梁电梯有限公司', '哈尔滨市南岗区汉广街41号', '13906103306张铁梁0611-86336639 86309986       徐宝琴13966033383李秀森13961699136', null, '0411-86372232');
INSERT INTO `khxx` VALUES ('193', '哈尔滨市日广电梯经销有限公司', '哈尔滨市道里区新阳路欧洲新城白D3-1-1', '董经理13836006388      0611-86838989', null, ' 0411-84828989');
INSERT INTO `khxx` VALUES ('194', '哈尔滨市天华(通昆)电梯有限公司', '哈尔滨市南岗区花园街304号恒运大厦B座2703室', '魏经理0611-13633093王晓丹', null, '0411-13634036');
INSERT INTO `khxx` VALUES ('195', '哈尔滨广日电梯有限公司', '哈尔滨市道里区买卖街105号太阳大厦2506', '吴崇 13996008313 0611-86196083', null, '0411-84194106');
INSERT INTO `khxx` VALUES ('196', '佳木斯新恒通电梯有限公司', '佳木斯友谊路110号', '荆加俊13836663001 0616-8196861李峰', null, null);
INSERT INTO `khxx` VALUES ('197', '黑龙江省力通电梯工程有限公司', '黑龙江省哈尔滨市香坊区和平路66号哈尔国际A座25层', '王继生13606106101 0611-13633698 王小姐', null, '0411-13622478');
INSERT INTO `khxx` VALUES ('198', '黑龙江福菱电梯设备有限公司', '哈尔滨市开发区轩辕东路22-4号盟科时代D栋3单元202室', '王福莹0611-83338666', null, '0411-13612217');
INSERT INTO `khxx` VALUES ('199', '绥化市至诚通用电梯服务有限公司', '黑龙江省绥化市祥和西街和谐嘉园G栋商服26号', '李加明0611-8399999', null, null);
INSERT INTO `khxx` VALUES ('200', '牡丹江万达电梯工程有限公司', '牡丹江市爱民区西祥伦街73号', '王卓艳13836366180  0613-6196966 8618133', null, '0413-6196966');
INSERT INTO `khxx` VALUES ('201', '大庆庆懋电梯机电工程有限公司', '大庆高新技术产业开发区', '于同彪13906193311', null, '0419-4667111');
INSERT INTO `khxx` VALUES ('202', '大庆永惠电梯有限公司', '大庆市萨尔图区东风新村纬二路', '赵怀军11006191398', null, '0419-6383037');
INSERT INTO `khxx` VALUES ('203', '哈尔滨友顺电梯工程有限公司', '哈尔滨市南岗区平准街59号', '杨麟13633611186', null, null);
INSERT INTO `khxx` VALUES ('204', '哈尔滨市永达电梯工程有限公司', '发票:哈尔滨市红旗大街289号龙\0|花园A座404室 收货:嵩山路118号(哈尔滨超高压局)', '夏维强13606880863 0611-89000811', null, '0411-87000833');
INSERT INTO `khxx` VALUES ('205', '鸿运物业', '哈尔滨市南岗区阿什河街10号恒运大厦C座物业管理部', '栗平13936663131', null, '0411-13632048');
INSERT INTO `khxx` VALUES ('206', '哈尔滨中美电梯公司', '哈尔滨南岗区木工街5号振轩电梯配件公司', '柴成涛13891989186', null, null);
INSERT INTO `khxx` VALUES ('207', '哈尔滨中美电梯公司大庆分公司', '大庆市东风新村百脑汇', '刘晓峰13806696311', null, null);
INSERT INTO `khxx` VALUES ('208', '李秀森13945699126', '哈尔滨市道里区友谊路392号远东大厦411室', '李琪13319866699', null, null);
INSERT INTO `khxx` VALUES ('209', '哈尔滨市教育局职教中心', '哈尔滨市南岗区学府路52号', '公利斌   13861061810', null, null);
INSERT INTO `khxx` VALUES ('210', '齐齐哈尔市杭奥电梯安装维修有限责任公司', '齐齐哈尔市龙沙区通达街青云小区综合楼', '孙辉13906616606 0613-3693638', null, '0412-2473638');
INSERT INTO `khxx` VALUES ('211', '齐齐哈尔医学院第一附属医院', '齐齐哈尔市富拉尔基向阳大街26号', '李华0613-6891963/13906133668', null, null);
INSERT INTO `khxx` VALUES ('212', '齐齐哈尔动力电梯销售有限公司', '齐齐哈尔站前大厅206号（齐铁电务段）', '林玉坤13996898316 11366616633', null, null);
INSERT INTO `khxx` VALUES ('213', '黑龙江海神电梯销售有限公司', '黑龙江省哈尔滨市南岗区海关街182号沪士大厦17F座', '刘晶11806636300', null, '0411-87131122');
INSERT INTO `khxx` VALUES ('214', '哈尔滨长江电梯安装有限公司', '哈尔滨市南岗区下夹树街144号', '李守梁 13836139930 0611-86330399', null, null);
INSERT INTO `khxx` VALUES ('215', '山东齐鲁味精集团', '山东仕平县山东齐鲁味精集团', '刘忠13969131118', null, null);
INSERT INTO `khxx` VALUES ('216', '山东高斯达电梯有限公司', '山东省章丘市辛寨乡辛中村13号 (副板)上海发货地址:上海基扬发货地址：上海松江区车墩镇回业路19号C1座 鲍继武   021-57602595', '纪荣彬0131-83161099 13116661989 发票EMS', null, '0131-83141079');
INSERT INTO `khxx` VALUES ('217', '山东百斯特电梯有限公司', '山东省济南市天桥区清河路57号', '孙安军(自动化)13189066611宋钦才(驱动)13969138383 0131-81900888-130 （副板发上海贝斯特 杨晓珍收）', null, '0131-81930168');
INSERT INTO `khxx` VALUES ('218', '山东德州百货大楼(集团)有限责任公司', '德州市德城区湖滨中大道118号德百写字楼16楼德百电梯维修科', '李书山0136-3693199 13189906911', null, '0134-2624960');
INSERT INTO `khxx` VALUES ('219', '青岛裕兴达东芝电梯工程有限公司', '青岛市市北区台东二路26号', '王财业   13301331161', null, null);
INSERT INTO `khxx` VALUES ('220', '青岛科达电梯有限公司', '青岛市市北区长山路52号甲', '潘淋淋13906399111', null, '0132-83820187');
INSERT INTO `khxx` VALUES ('221', '青岛德奥电梯有限公司', '青岛市李沧区金水路1057#26#-2单元-202室', '黄曙光13391189988 0133-89616199', null, null);
INSERT INTO `khxx` VALUES ('222', '山东东达电梯有限公司', '山东省济宁市中区开发区深圳西路', '党德亮13696390688 0139-3639988 3639666 3619888', null, '0137-2619896');
INSERT INTO `khxx` VALUES ('223', '淄博新世纪电梯工程有限公司', '淄博市金星大道299号 三玉生活区27-2号', '刘爱国13108913330/0133-3918988 3916000', null, '0133-3917111');
INSERT INTO `khxx` VALUES ('224', '淄博长城电梯工程有限公司', '淄博市开发区政通路145号', '刘爱宝13108913330/0133-6389333', null, '0133-6287322');
INSERT INTO `khxx` VALUES ('225', '威海云峰电梯有限公司', '山东省威海市顺河街220-5号  工厂地址：山东省荣成市港西镇海都热电厂西侧  杨玉强：13656309215', '0631-1866918李经理：13869068193  杨玉强：13616309311', null, null);
INSERT INTO `khxx` VALUES ('226', '东芝电梯（沈阳）有限公司青岛分公司', '青岛市市南区汇泉路17号东海国际大厦E-301室', '张德华13993660333 0133-83888311', null, null);
INSERT INTO `khxx` VALUES ('227', '海科电梯（富士工业（青岛）电梯制造有限公司）', '青岛李沧区李沧工业园内', '0133-89603311张健13618669309 0133-89606369于涛0133-83903303', null, '0132-87602177');
INSERT INTO `khxx` VALUES ('228', '青岛建秋电梯有限公司（博格）', '青岛胶州市胶州湾工业园二区8号路东段', '栾正武0133-81133383..13116896080', null, '0132-81123386');
INSERT INTO `khxx` VALUES ('229', '烟台', null, '赵静0131-6611109', null, '0131-6231278');
INSERT INTO `khxx` VALUES ('230', '淄博东屹工贸有限公司', '山东省淄博市张店区西二路200号', '张东13001109916 0133-6389369', null, '0133-6289269');
INSERT INTO `khxx` VALUES ('231', '上海莱普青岛分公司', null, '姜卫丰0133-83806116', null, '0132-82806116');
INSERT INTO `khxx` VALUES ('232', '临沂市兰山区兴华机电仪表站', '临沂市通达路327号', '朱学印13801391393 0139-8119801', null, null);
INSERT INTO `khxx` VALUES ('233', '临沂市胜军自动化设备有限公司', '山东省临沂市临西一路银宝机械市场北区二楼', '和湘胜13608990669/0139-9169396', null, '0139-7161276');
INSERT INTO `khxx` VALUES ('234', '临沂鑫达电梯公司', '临沂市兰山区腊庙街', '朱陆海13813936811', null, null);
INSERT INTO `khxx` VALUES ('235', '临沂电梯有限公司', '山东省临沂市金四路与中丘路交汇处埠东小区南院十号楼407室', '牛福然0139-3961118 13108996606', null, null);
INSERT INTO `khxx` VALUES ('236', '青岛称自达电梯有限公司', '青岛市市南区香港中路5号中国纺织工人疗养院光荣楼415室', '刘孟祥13310690638', null, null);
INSERT INTO `khxx` VALUES ('237', '青岛乘自达电梯有限公司', '青岛市香港中路5号工人纺织疗养院光荣楼215室', '尹莉11318969698 13391630998', null, '0132-83866212');
INSERT INTO `khxx` VALUES ('238', '青岛菱工电梯工程有限公司', '青岛市山东路52号华嘉大厦1307室', '徐丽0133-81013030', null, '0132-81013326');
INSERT INTO `khxx` VALUES ('239', '青岛富士田电梯销售有限公司', '发票:青岛山东路177号鲁邦广场B-508室 交货地址:青岛市四方区人民路99号2单元401室', '发票:于慧13061338000 高先成13386399003 于立明13386399009;0133-83999691/91 王凤', null, '0132-83717914');
INSERT INTO `khxx` VALUES ('240', '青岛富佳电梯有限公司', '青岛市山东路177号鲁邦广场B-508室   发货地址：山东省青岛市李沧区李村北崂路  收', '高先成  电话：13386399003发票：于慧13061338000', null, '0132-80931836');
INSERT INTO `khxx` VALUES ('241', '烟台鲁建电梯有限公司', '烟台市芝罘区向阳133-2号', '梁13606383838 姜敏0131-6636819', null, '0131-6624801');
INSERT INTO `khxx` VALUES ('242', '烟台迅菱奥', null, '0131-3133966', null, null);
INSERT INTO `khxx` VALUES ('243', '泰安市顺兴电梯有限公司 (货发泰山站)', '山东省泰安市望岳宾馆南楼106室', '马卫忠0138-8319690（兼传真）  13013833600赵建荣13003990110', null, null);
INSERT INTO `khxx` VALUES ('244', '烟台博汇电梯科技有限公司', '山东省烟台市建设路71号412室', '郝小燕 3991990 13396381163', null, null);
INSERT INTO `khxx` VALUES ('245', '济宁锐通电梯有限公司', '山东省济宁市环城西路13-3号', '陈民丰13601699399 0139-3318366 0139-3669399', null, '0137-2669399');
INSERT INTO `khxx` VALUES ('246', '山东济宁康达电梯公司', '收货:山东兖州共青团路邮政局宿舍2号楼303室 发票地址:山东省济宁市建设北路126号(劳务开发公司院内)', '收货:刘淑娟13608911930 0139-3611619收发票:徐保民13813963809', null, null);
INSERT INTO `khxx` VALUES ('247', '济宁百斯特电梯有限公司', '济宁市建设路锦都商务中心419室', '荣建设0139-3900918', null, '0137-2900728');
INSERT INTO `khxx` VALUES ('248', '山东三洋输送机械有限公司', '山东省齐河县经济开发区名嘉西路7号', '刘佳18913661300/0136-1039688', null, '0137-1027688');
INSERT INTO `khxx` VALUES ('249', '德州诺亚威特电梯有限公司', '山东省德州市东方红路24号市委招待所4楼', '张兰西11961363899', null, null);
INSERT INTO `khxx` VALUES ('250', '德州市百斯特电梯服务中心', '山东省德州市解放北路2号', '杨文彬0136-3698338 13611363116', null, null);
INSERT INTO `khxx` VALUES ('251', '德州市场天衢路棉麻公司', '山东省德州市天衢路1336号102室', '盖书永0136-3361889', null, null);
INSERT INTO `khxx` VALUES ('252', '潍坊快速美奥电梯有限公司', '山东省安丘市北区汶水路', '高冰18663609819', null, '0136-4398070');
INSERT INTO `khxx` VALUES ('253', '济南迅达电梯有限公司', '山东省济南市槐荫区振兴中街6-1号', '王敏13813198818 0131-89183916', null, null);
INSERT INTO `khxx` VALUES ('254', '济南孚典实业发展有限公司', '济南市历下区燕子山路2-2号燕翔大厦458室', '许彤生0131-88190099', null, null);
INSERT INTO `khxx` VALUES ('255', '潍坊奥潍电梯安装有限公司（山东三元）', '山东省潍坊市民生东街63号(市教委对面)', '卢洪泉13806661966 0136-8993331', null, '0136-8792331');
INSERT INTO `khxx` VALUES ('256', '潍坊世纪美联百货有限公司', '山东省潍坊市昌乐县城区', '吴继伟 0136-6313088 11613689399', null, null);
INSERT INTO `khxx` VALUES ('257', '王兴民', '山东省泰安市泰山区迎春小区68号楼一单元601室', '王兴民13183819363', null, null);
INSERT INTO `khxx` VALUES ('258', '潍坊菱业电梯有限公司', '潍坊市健康西街135号向阳大厦706室', '许晓娟0136-8383030', null, '0136-8317230');
INSERT INTO `khxx` VALUES ('259', '济南槐荫正利电梯配件维修处', '沈阳', '黄学全0131-89181099 13813193803', null, null);
INSERT INTO `khxx` VALUES ('260', '济南雪莲实业有限公司', '山东省济南市市中区英雄山路20号保健品批发市场', '侯广勇13913166398', null, null);
INSERT INTO `khxx` VALUES ('261', '淄博兴国设备安装有限公司', '山东省淄博市张店区洪沟路东首店子村', '范锋0133-3069811', null, null);
INSERT INTO `khxx` VALUES ('262', '山东博尔特', '山东省德州市宁津县银河经济开发区', '张景新11166916899', null, null);
INSERT INTO `khxx` VALUES ('263', '秦皇岛奥跃机械设备有限公司', '秦皇岛市山海关经济技术开发区上海西路27-7', '刘海涛1363338398/13191913393/0331-1089816', null, '0331-1080100');
INSERT INTO `khxx` VALUES ('264', '青岛润东', '青岛市南区香港中路6号世贸中心B座1702室。', '尹丽丽11318969698  唐方坤0136-1819111', null, '0134-1819111');
INSERT INTO `khxx` VALUES ('265', '青岛海亿通电梯有限公司', '山东省青岛市经济技术开发区江山南路377号楼1单元102室', '万国民 13316898911 0133-86808868', null, null);
INSERT INTO `khxx` VALUES ('266', '山东富士制御电梯', '山东省宁津县经济开发区泰山路南首', '张真真 11066631111  刘金凯11066610186   0136-1819111', null, '0134-1819111');
INSERT INTO `khxx` VALUES ('267', '山东奔速电梯', '山东省济南市高新区天辰路667号', '刘振涛', null, '0134-1819116');
INSERT INTO `khxx` VALUES ('268', '山东莱茵艾佳电梯有限公司', '山东省宁津县开发区泰山路南首', '梁斌18013609899', null, '0134-1819117');
INSERT INTO `khxx` VALUES ('269', '青岛建信电梯工程有限公司', '青岛市李沧区黑龙江中路2688号6号楼1单元601户', '冷建冰13316889893', null, null);
INSERT INTO `khxx` VALUES ('270', '唐山开滦建设集团有限责任公司', '唐山市路北区新华东道57号（开滦医院总务科）  唐山市路北区果园乡刘火新庄西', '郑凯13186919919 韩光群13930139696 吕长义11111968619 0311-3316988', null, null);
INSERT INTO `khxx` VALUES ('271', '唐山金维电梯机电有限公司', '唐山龙泽北路425号大陆阳光101楼12层', '周维民0311-3160101/3160111张树艳13633308601', null, '0311-83096022');
INSERT INTO `khxx` VALUES ('272', '华北制药奥奇德药业有限公司', '石家庄经济技术开发区扬子路18号', '张翔0311-83096033', null, '0311-86302118');
INSERT INTO `khxx` VALUES ('273', '石家庄市石菱电梯服务中心', '石家庄市中山东路126号 凯嘉大厦4A01', '蒋锡春0311-86039903 13603111318', null, '0311-87281182');
INSERT INTO `khxx` VALUES ('274', '河北格瑞特电力设备有限公司', '石家庄市建设北大街223号中浩11A', '赵光宇311-89381183', null, '0311-87022188');
INSERT INTO `khxx` VALUES ('275', '河北辽富电梯有限公司', '石家庄裕华西路166号联邦名都A座3203', '薛丽娜   13693136918 宋方奎0311-89883000/89033188/13933863366', null, '0311-86994461');
INSERT INTO `khxx` VALUES ('276', '石家庄市军创电梯安装维修服务中心', '石家庄市胜利北大街185号颐馨商务公寓6楼', '白静 0311-86031896', null, null);
INSERT INTO `khxx` VALUES ('277', '河北百斯特电梯服务中心', '石家庄市平安南大街14号6楼', '魏海政13693969330', null, '0311-7822192');
INSERT INTO `khxx` VALUES ('278', '石家庄冀铁昌华电梯有限公司', '石家庄市水源街89号冀铁集团603室', '罗平0311-89839166 13311189969 李广13931168113', null, '0311-87823916');
INSERT INTO `khxx` VALUES ('279', '石家庄冀铁昌华电梯有限公司', '石家庄市新华路100号', '高慧英 13933106306', null, null);
INSERT INTO `khxx` VALUES ('280', '沧州市宏达电梯有限公司', '河北省沧州市眼科医院东侧楼3单元301室', '传真/电话：0319-1303993 王凯立13013031081', null, '0311-81206111');
INSERT INTO `khxx` VALUES ('281', '石家庄星玛电梯有限公司', '石家庄康乐街14号祥源大厦1306室', '刘有倩0311-81306111', null, '孟庆波0319-2617806 13831910101');
INSERT INTO `khxx` VALUES ('282', '邢台市三环电梯有限责任公司', '邢台市桥西区北外环路邢台三环院内', '张丙须 13903391911 0319-3369113王敏', null, '0319-3060821');
INSERT INTO `khxx` VALUES ('283', '邢台安顺电梯安装有限公司', '邢台开发区英华大街英华学校对面', '郝立国13833961931', null, '0319-3191008');
INSERT INTO `khxx` VALUES ('284', '邢台金达电梯工程有限公司', '河北省邢台市新兴东大街186号', '苑文新0319-3191008', null, '0319-1912833');
INSERT INTO `khxx` VALUES ('285', '邢台市邢环电梯有限公司', '邢台市桥西区郭守敬大道2940号', '张军国 13831916668', null, '0319-2617806');
INSERT INTO `khxx` VALUES ('286', '唐山中迅电梯楼宇设备有限公司', '河北省唐山市路北区北新西道玫瑰庄园4单元1302室', '吴海燕(13013381313)', null, null);
INSERT INTO `khxx` VALUES ('287', '东方大学城公安分局', '河北省廊坊市东方大学城公安分局', '李\0Z13180361166', null, '0316-1906193');
INSERT INTO `khxx` VALUES ('288', '廊坊柏纳控制新技术有限公司', '河北省廊坊市金光道61号', '刘景辉0316-3969113', null, '0319-2120119');
INSERT INTO `khxx` VALUES ('289', '邢台辰光电梯有限责任公司', '河北省邢台市中兴西大街319号', '彭翠珍0319-3130183 13831969339', null, '0317-3191202');
INSERT INTO `khxx` VALUES ('290', '沧州市奥菱电梯有限公司', '河北省沧州市北环路嘉福园小区2-1-202', '吕增通  11833999360', null, null);
INSERT INTO `khxx` VALUES ('291', '高虹(苏州东方电梯有限公司)', '吴江市临沪经济区北厍工业园', '汝华0113-63368866', null, '0311-81687988');
INSERT INTO `khxx` VALUES ('292', '河北欧绅电气有限公司', '石家庄市开发区黄河大道105号九州科技楼319室', '采购0311-81681988 81689988', null, null);
INSERT INTO `khxx` VALUES ('293', '邯郸市长林电梯有限公司', '邯郸市丛台区常壹巷3号楼2单元4号', '张维芳13903309639', null, null);
INSERT INTO `khxx` VALUES ('294', '唐山丰润颢明机械安装维修有限公司', '唐山市丰润区丰韩路', '于靖11133139300 0311-1183316', null, null);
INSERT INTO `khxx` VALUES ('295', '衡水重工电梯起重设备有限公司', '河北省衡水市和平中路与中兴街交叉口 如家宾馆2楼', '郭会荣13363306199', null, null);
INSERT INTO `khxx` VALUES ('296', '曲阳光大机电有限公司', '河北省保定市高新区同美酒店B座115、116', '马海英0313-1919189', null, null);
INSERT INTO `khxx` VALUES ('297', '唐山杭奥电梯有限公司', '唐山市大里路68号', '居崇11096163063', null, null);
INSERT INTO `khxx` VALUES ('298', '唐国春', '石家庄市西里街76号5-303', '唐国春13833168139', null, '0319-2121933');
INSERT INTO `khxx` VALUES ('299', '邢台圣柯达电梯有限公司', '邢台市桥西区中华大街398#锦绣中华园物业公司二层1#', '王艳0319-3131933  11131369111', null, '0311-6631011');
INSERT INTO `khxx` VALUES ('300', '廊坊市赛孚电梯', '河北省 廊坊市 安次区仇庄建设工业园 东方国立院内', '王冬梅电话：0316-3196889手机：1383163019918603331310李海风18603331310', null, null);
INSERT INTO `khxx` VALUES ('301', '石家庄中迅', '河北省石家庄市中华南大街473号居然商务中心501室', '张工 13933081931', null, null);
INSERT INTO `khxx` VALUES ('302', '东莞西门子山西分公司', '太原市兴华北街15号金座公寓', '曾祥云 0311-6610888 13666833386', null, null);
INSERT INTO `khxx` VALUES ('303', '太原市津典电梯有限公司', '山西省太原市平阳路1号金茂国际数码中心B座25楼', '张效生13916800109 0311-6193933', null, '0311-6199822');
INSERT INTO `khxx` VALUES ('304', '太原市景山房屋设备有限公司', '太原市后王南街2号603室', '郭锦13831181113', null, null);
INSERT INTO `khxx` VALUES ('305', '太原市新星商贸有限公司', '太原市解放路66号', '常建明0311-6168698/6063098*13803613903', null, '7010421');
INSERT INTO `khxx` VALUES ('306', '山西立安电梯技术有限公司配件供应部', '太原市山西大学28楼4-401', '张保军13936306810', null, null);
INSERT INTO `khxx` VALUES ('307', '慧远达电梯有限公司', '太原市杏花岭区经园路374号五龙湾阳光海岸阳光区七号路305', '张什产 0311-6663088（兼传真） 米兰13936633096', null, '0311-7189726');
INSERT INTO `khxx` VALUES ('308', '山西沈东电梯营销有限公司', '太原市亲贤北街42号西八楼', '姬贵文经理0311-9189931/13903669113  13803693830苏智军13803693119', null, '0311-6061818');
INSERT INTO `khxx` VALUES ('309', '太原市世翔电梯制造有限公司', '太原市和平南路小井峪街26号', '孙经理0311-6061989', null, '0311-7189726');
INSERT INTO `khxx` VALUES ('310', '太原市通富电梯营销有限公司', '太原市亲贤北街148号', '姬高文13903669113   0311-9188366/9189939', null, '0310-3040881');
INSERT INTO `khxx` VALUES ('311', '忻州忻鑫电梯有限公司', '忻州市七一北路学府街北苑', '曹毅平 李彩俊   13931030891 0310-3060881', null, null);
INSERT INTO `khxx` VALUES ('312', '山西省忻州市建设北路1号广播电视局', '山西省忻州市建设北路1号', '杨玉峰   0310-3801999   13931013889', null, '0311-3126119');
INSERT INTO `khxx` VALUES ('313', '太原邦尼电梯工程有限公司', '山西省太原市五一路225号唐久大厦420室', '马邦虎13836316666', null, null);
INSERT INTO `khxx` VALUES ('314', '山西瑞莱博电梯服务有限公司', '山西省太原市金刚堰路68号捷利大厦508', '徐峰13603163366 0311-3311966', null, null);
INSERT INTO `khxx` VALUES ('315', '太原市富士电梯销售有限公司', '太原市府西街12号', '李勇胜13093100869  黄路珍13109931080', null, 'FAX：0471-6287184');
INSERT INTO `khxx` VALUES ('316', '苏州富佳恩科电梯有限公司太原分公司', '太原市学府街高新区科技街北美晶域蓝湾FB座1003号/太原市高新区产业路39号34楼1单元201号', '韩建胜 13996363666  0311-9033186', null, null);
INSERT INTO `khxx` VALUES ('317', '内蒙古中升实业有限公司', '内蒙古呼和浩特市中山路23号', '栗勇0691-6368330、13969198993张亚凤6399696', null, null);
INSERT INTO `khxx` VALUES ('318', '呼伦贝尔市恒达电梯销售有限责任公司', '内蒙古呼伦贝尔市海拉尔区伊敏大街26号', '王哲荣13868098116', null, null);
INSERT INTO `khxx` VALUES ('319', '内蒙古黎明电梯经销安装维修有限责任公司', '内蒙古呼和浩特市新城区海东路丽苑小区16号楼1单元102室', '武黎明13906913600 、0691-6191606', null, null);
INSERT INTO `khxx` VALUES ('320', '内蒙古帝亚杰电梯有限公司', '内蒙古呼和浩特市新城南街奈伦大厦三楼', '高吉祥13968816193/0691-3368388', null, '0474-3207444');
INSERT INTO `khxx` VALUES ('321', '内蒙古凯帝斯电梯制造有限公司', '内蒙古丰镇市轻工业科技园', '乔国富13936969183', null, null);
INSERT INTO `khxx` VALUES ('322', '包头市捷安电梯自动化有限责任公司', '内蒙古省包头市昆区青年路6号街坊8栋51号', '李晓春13868339689', null, null);
INSERT INTO `khxx` VALUES ('323', '内蒙古菱工电梯有限公司', '内蒙古呼和浩特市赛罕区昭乌达路山丹街商检小区4-2-202', '王琴 0696-6363813 13616916100', null, null);
INSERT INTO `khxx` VALUES ('324', '内蒙古精工电梯股份有限公司', '内蒙古包头市九原区兴胜经济开发区', '贺培基13868316131', null, null);
INSERT INTO `khxx` VALUES ('325', '洛阳益成电梯', '洛阳市凯旋东路60号', '马翠荣13838816333 0399-63313110', null, null);
INSERT INTO `khxx` VALUES ('326', '河北上海三菱', '石家庄市裕华西路67号', '范淑萍13081003396', null, null);
INSERT INTO `khxx` VALUES ('327', '哈尔滨南方', '哈尔滨中山路166号512室', '李秋晶0611-83613818', null, null);
INSERT INTO `khxx` VALUES ('328', '天津鑫宝龙', '天津市西青区杨柳青镇柳口路与津静公路交口西侧精成路', '赵新祥189030313630', null, null);
INSERT INTO `khxx` VALUES ('329', '沈阳新程', null, '程林13998866198 11803639999', null, null);
INSERT INTO `khxx` VALUES ('330', '长春奥利夫', '发票地址：长春市西安大路2389号七楼；发货地址：吉林省公主岭市怀德镇双榆树村街道奥利夫电梯有限公司一分厂', '马洪良13396696198', null, '0434-6110113-8000');
INSERT INTO `khxx` VALUES ('331', '上海三洋', '上海市南汇区新场坦直工业区古丹路26号', '蒋林031-38011396-8103/牛建新（技术）031-38011366-8011', null, null);
INSERT INTO `khxx` VALUES ('332', '北京顺迅', '北京市顺义区怡馨家园29号楼201室', '郑敬敏13911131639', null, null);
INSERT INTO `khxx` VALUES ('333', '中船重工', '沈阳市和平区浑河民族开发区民旺路18号辽海机械厂院内', '郝新民13960066938 张宗岱11960191619', null, null);
INSERT INTO `khxx` VALUES ('334', '辽宁科瑞特电梯有限公司', '沈阳市皇姑区鸭绿江街198-26号', '曹金州13860303398/036-86690991', null, '024-86670771');
INSERT INTO `khxx` VALUES ('335', '北京海迅进出口有限公司', '北京市丰台区马家堡西路15号时代风帆大厦1-2206室', '冯娜13661013103/010-89969933-8308', null, '010-87747978');
INSERT INTO `khxx` VALUES ('336', '辽宁富士电梯有限公司', '皇姑区崇山东路鸭绿江街49号', '杨永帅13998313010', null, '86617044');
INSERT INTO `khxx` VALUES ('337', '沈阳三洋电梯有限公司', '沈阳市大东区东北大马路272号', '张舫13889800093', null, '88093432');
INSERT INTO `khxx` VALUES ('338', '浙江韦伯', '浙江省湖州市南浔经济开发区东翔同辛村', '郑婵0193-3993983', null, null);
INSERT INTO `khxx` VALUES ('339', '怡达快速', '湖州市南浔318国道北侧（经济开发区1号门）', '技术 0193-3063339方工0193-3063338/3060896沈钰 周祝华 手机 13919063061  座机电话0193-3060896   滕梁：0193-3063331', null, null);
INSERT INTO `khxx` VALUES ('340', '恒达富士', '浙江湖州南浔镇人瑞西路南侧', '张振华13906936618    0193-3610303/3061303小何    张振华0193-3061883/13906936618', null, null);
INSERT INTO `khxx` VALUES ('341', '浙江南奥', '浙江湖州市南浔经济开发区强华路6号', '沈小弟：18901931960  0193-3809030 3809010 潘女士：0193-3809030   13969396636', null, null);
INSERT INTO `khxx` VALUES ('342', '浙江联合', '浙江湖州市南洵经济开发区织洵大道68号', '张利华:0193-3989331 陆利英:0193-3919390', null, null);
INSERT INTO `khxx` VALUES ('343', '苏州帝奥', '吴江市震泽镇八都太湖大道', '\n小王：座机现改为0113-63991396', null, null);
INSERT INTO `khxx` VALUES ('344', '苏州菱怡电梯', '苏州吴江市震泽大船港开发区大道', '俞吴新：13969383066/0113-63988838', null, null);
INSERT INTO `khxx` VALUES ('345', '巨人通力', '浙江省湖州市南浔经济开发区织浔大道88号', '吴洁：11088366916  0193-3989998 0193-3989836 11088366916 沈焰月：0193-3989098  徐惠鑫：0193-3989098', null, null);
INSERT INTO `khxx` VALUES ('346', '湖州南浔电气', '浙江省湖州市南浔镇压同心路晶典花苑四幢二单元302', '钱建强13169369881', null, null);
INSERT INTO `khxx` VALUES ('347', '浙江屹立', '浙江省湖州市南浔经济开发区综园路8号', '洪月仙0193-3013011/3998011/何伟芳3999313', null, null);
INSERT INTO `khxx` VALUES ('348', '苏州法奥', '江苏省吴江震泽镇镇西开发区 朱家浜村', '张红13169996111倪总 0113-63988918-8088 :0113-63988931吕剑名                         自动化采购 张红 18363199093     0113-66988136\n驱动采购     贝月秋 18363199093  0113-63988680', null, null);
INSERT INTO `khxx` VALUES ('349', '沃克斯中国电梯', '浙江南浔科技工业园区西泰路8号', '刘斌：11088330939  传真：86-193-3019931 电话：86-193-3099311  宋丽娟：0193-3019901  王英：0193-3010338', null, null);
INSERT INTO `khxx` VALUES ('350', '苏州通用', '江苏省吴江市七都镇港东开发区', '13906311603 孙海荣 0113-63818169', null, null);
INSERT INTO `khxx` VALUES ('351', '苏州迪欧达改名头 （波士顿电梯（苏州）有限公司）', '吴江桃源梵香工业区', '13919311669虞成0113-63866331', null, null);
INSERT INTO `khxx` VALUES ('352', '浙江快奥', '浙江省湖州市南浔经济开发区丁家港东村', ' 李小姐 13169333663严金礼  电话：0193-3061611', null, null);
INSERT INTO `khxx` VALUES ('353', '苏州克莱斯', '吴江市七都镇临浙经济区', '崔建华0113-63833066', null, null);
INSERT INTO `khxx` VALUES ('354', '湖州安灵', '浙江省湖州市南浔经济开发区1区2号路(东段)', '李建根0193-3060313/3808638/13901931001', null, null);
INSERT INTO `khxx` VALUES ('355', '苏州富士佳', '苏州市吴江桃源梵香工业区', '严友法:0113-63868088 小倪:0113-63960631/13863109301', null, null);
INSERT INTO `khxx` VALUES ('356', '湖州中菱', '浙江南浔开发区工业园区适园西路1688号', '张绍有13189396639/0193-3030900', null, null);
INSERT INTO `khxx` VALUES ('357', '浙江巨奥', '湖州市南浔镇横三路128号\n王勇新   13905721962', 'TEL：0193-3013888', null, null);
INSERT INTO `khxx` VALUES ('358', '杭州奥立达', '浙江省建德市三河建兰路6号', '罗卓娅13819130013/小陈0191-66166891蒋正芳0191-66166891', null, null);
INSERT INTO `khxx` VALUES ('359', '杭州顺达伯耐特电梯有限公司（杭州顺达）', '杭州市余杭区崇贤镇北庄村', '俞富杨0191-86019601/86019969', null, null);
INSERT INTO `khxx` VALUES ('360', '浙江西尼', '浙江杭州市萧山经济开发区桥南7号路东(北环路南)（新地址：萧山南阳开发区阳城路31号）', '干巧娣13188199183   彭青18319193136/0191-19163601\n 曳引机随机文件收件人：：李兴花/电话：131-8813-3689 原点值接收人：：jiangan@syney.net\n 余丽：11918169096 0191-19163603 吴海鱼：  13639691663', null, null);
INSERT INTO `khxx` VALUES ('361', '建德天和', '建德市新安江镇城东科技工业园', '黄利洪0191-66963166/13116836696/0191-66963918叶树刚（应兰芳）0191-66963919', null, null);
INSERT INTO `khxx` VALUES ('362', '杭州新马', '浙江省建德市新安江镇城东区', '郭勇:13188310399  小邵    0191-66963963', null, null);
INSERT INTO `khxx` VALUES ('363', '杭州恒丰', '杭州萧山区靖江街道工业园区', '戴建军0191-83190000/13819691303', null, null);
INSERT INTO `khxx` VALUES ('364', '浙江比奇', '杭州市萧山区党山镇前兴工业区', '傅庆0191-83133388/13188601396', null, null);
INSERT INTO `khxx` VALUES ('365', '江西富士', '江西省吉安市吉水县城西工业园', '钟远平0996-3313839/13119069893/孟仲贤18909969989', null, null);
INSERT INTO `khxx` VALUES ('366', '杭州通达', '杭州市莫干山路493号5-105室', '沈斌0191-88803393', null, null);
INSERT INTO `khxx` VALUES ('367', '杭州太阳电气', '杭州市西湖区文三路90号东部软件园科技大厦4楼B408室(只寄发票到这个地址).仓库(收发货)杭州市江干区机场路277号20号楼(货与货和发票寄此地址)', '叶花:0191-81911399-339;仓库:0191-81066318/81069106', null, null);
INSERT INTO `khxx` VALUES ('368', '杭州锐志智能', '发货址：杭州下沙开发区海杭路128号曼斯顿电梯有限公司内 发票地址:杭州市新塘路99号天翔凤起时代大厦2002室', '王荣飞/0191-38033381 收货人:汪建华  0191-86999083/86999093', null, null);
INSERT INTO `khxx` VALUES ('369', '浙江富控', '温州市经济开发区滨海园区十五路五道519号', '孟仲贤18909969989/收货：黎小峰11018913099 采购部   周燕手机18011666113   QQ613310113\n工程：翁志华：18906610633 质量部 何倪 电话：0199-81839361手机：11383188933', null, null);
INSERT INTO `khxx` VALUES ('370', '深圳铃木平湖工厂', '浙江省平湖市平湖太道独黎路口 (现收货地址)', '张艳红0193-81396666转8081', null, null);
INSERT INTO `khxx` VALUES ('371', '温州奥德斯(浙江富奥）', '温州市乐清柳市翁洋镇华新工业区', '聂都奎11088998363/0199-63803933/杨志丹13919981116 0199-63803986', null, null);
INSERT INTO `khxx` VALUES ('372', '浙江梅轮电梯', '浙江省绍兴县齐贤镇梅林村（收货地址：浙江绍兴柯北工业园区梅中路576号 莫雅莉 0575-85591819', '采购：陈锋。朱虹0191-81660138/小高:0191-81660131 技术张慧:13819190613（倪金祥0191-81660138）陈亮（0191-81660036 13919108303）', null, null);
INSERT INTO `khxx` VALUES ('373', '浙江飞亚', '金华市金圆路1199号', '技术雯经理 0199-83366610/张建0199-89196893', null, null);
INSERT INTO `khxx` VALUES ('374', '浙江威尔金森电梯', '浙江省永康市五金工业园四期群升科技园  郑作枫13858932444/0579-87153733\n', '0199-89116189黄俊武  （发票） 13106996106', null, null);
INSERT INTO `khxx` VALUES ('375', '乐清迅达电梯', '浙江省乐清市虹桥镇虹河西路212号 三元公司', '赵元勇：13868988166', null, null);
INSERT INTO `khxx` VALUES ('376', '浙江振涯西屋电梯', '浙江省绍兴县湖塘街道宾舍村', '收货：钱根苗 11918116991/0191-86386313/13 收货:徐国萍0191-86386313/13191168909', null, null);
INSERT INTO `khxx` VALUES ('377', '浙江诺比克', '浙江温州市龙湾区永强大道八甲工业区章家桥3号曳引机收货地址：浙江温州龙湾区八甲工业区章家桥3号；杨俊孝 15888723456  0577-86908668', '吴晓明0199-86908668/0199-86908668  FAX：0199-86908333 杨俊孝', null, null);
INSERT INTO `khxx` VALUES ('378', '台州富士', '浙江台州市椒江区东南大道富士工业园', '11019630990 许艳 0196-88660999-86    88660188', null, null);
INSERT INTO `khxx` VALUES ('379', '宁波南方电梯', '宁波市灵桥路219号A座二路', '吴国创:0196-89303186', null, null);
INSERT INTO `khxx` VALUES ('380', '宁波五星电梯', '浙江宁波北仑区春晓工业园洋沙山西十路180号', '曾新明0196-86869391', null, null);
INSERT INTO `khxx` VALUES ('381', '浙江金华同创', '浙江省金华市婺州街星月花园690号', '周建庭11306180933   0199-83313098', null, null);
INSERT INTO `khxx` VALUES ('382', '浙江安利索电梯', '浙江省台州经济开发区经一路108-3号', '0196-8303188李先锋13186083163/13186083613', null, null);
INSERT INTO `khxx` VALUES ('383', '温州圣普电梯', '温州市瓯海经济开发区翠柏路2号', '0199-86369133施小姐', null, null);
INSERT INTO `khxx` VALUES ('384', '浙江丽水菱奥电梯', '浙江省丽水市白云山口48号/水阁工业区石牛路262号', '陈建饶13886336636', null, null);
INSERT INTO `khxx` VALUES ('385', '金华同创', null, '0199-8331313813906818396', null, null);
INSERT INTO `khxx` VALUES ('386', '嘉兴富士', null, '陆先生 13186399938', null, null);
INSERT INTO `khxx` VALUES ('387', '浙江威特电梯', '浙江省义乌市经济开发区杨村路335号', '联系人：蒋化林\n电话：0199-81810110\n手机：11918993890\n', null, null);
INSERT INTO `khxx` VALUES ('388', '台州市鸿升电梯', '浙江省台州市路桥桐屿坝头工业区', '吴仲龚：13616696381', null, null);
INSERT INTO `khxx` VALUES ('389', '上海富士', '上海大叶公路7505-7515号', '吴天忠13311691819  031- 19113606', null, null);
INSERT INTO `khxx` VALUES ('390', '武汉鑫元上海办事处', '地址：上海市浦东新区张杨路228号汤臣中心A座1917室', '胡毅刚电话：13919198669', null, null);
INSERT INTO `khxx` VALUES ('391', '上海德驰电扶梯成套配件有限公司(阿尔法)', '上海市共和新路966号1603室 姜志航地址:上海市宝山区富联二路198号顾村1号工业园区', '孙环霖 13901809969  031-36063300-6091', null, null);
INSERT INTO `khxx` VALUES ('392', '上海阿尔法电梯厂', '上海市宝山区富联二路198号顾村工业园区', '钱宝岐13901903163\\031-36066130', null, null);
INSERT INTO `khxx` VALUES ('393', '上海贝思特', '上海市浦东新区航头镇大麦弯工业园区航帆路2号徐毅 13918062045  邬雪明/18602106698/021-58223128/58225564   胡洁：021-58223789', '姚立波031-18339603/方卫红小灵通031-39391631 /13818086368/031-18333800 纪红031-18331168 /3668FAX:031-18333138  /13311961698', null, null);
INSERT INTO `khxx` VALUES ('394', '上海统一精工机械有限公司', '上海市青浦工业园区新区路409号', '技术金秋峰13136193638 031-69311868830工程部谭工 金叶13816893966 叶英', null, null);
INSERT INTO `khxx` VALUES ('395', '上海鹏沪电梯有限公司（登梯斯）', '嘉定区南翔镇嘉前路928号', '谢奕031-69199983     13966119311   /69199189常工13916313369 财务谢佳华(发票)031-69199986', null, null);
INSERT INTO `khxx` VALUES ('396', '上海时备莱(埃神)赵辉', '上海市浦东新区金港路333号16楼1619室', '031-11998990 赵辉13819836188\\031-66936998传 罗军(发票)', null, null);
INSERT INTO `khxx` VALUES ('397', '上海浦东开灵电梯厂', '上海浦东合庆跃东路300号', '丁为民13801630913\\031-68901030/031-68909669传/68903613财务 奚厂长68900193传', null, null);
INSERT INTO `khxx` VALUES ('398', '上海台菱', '发货地址：上海南汇临港新城书院都市产业圆丽正路1659号   陶爱明（系统）  021-58198866-832/13601904105；朱慧超（曳引机）021-58198866-817', null, null, null);
INSERT INTO `khxx` VALUES ('399', '石狮洋阳电梯贸易有限公司', '福建省石狮市子芳路691号巷43.45.47', '李志阳1300683391/0191-8888111/8883391', null, null);
INSERT INTO `khxx` VALUES ('400', '上海鸥开电梯配件有限公司', '上海市南汇区临港万祥都市产业区万达路208号', '丁志明031-18089930总机/18089981总   储华13386033996   倪春燕 仓库-33丁小姐39333191/38016319', null, null);
INSERT INTO `khxx` VALUES ('401', '上海昌菱', '上海市青浦区大盈镇青赵公路5899号', '张育广：031-19331336/13916860890', null, null);
INSERT INTO `khxx` VALUES ('402', '上海贤友机械制造有限公司', '上海市奉贤区奉城镇大叶公路蔡桥路168号(上海富士电梯斜对面)', '收货人：吴丽华031-69119198/13816163160', null, null);
INSERT INTO `khxx` VALUES ('403', '上海三洋电梯有限公司', '上海市南汇区新场坦直工业区古丹路26号', '佟肖(曳引机)031-38011396-8103/蔡燕红(系统)031-38011396-8103', null, null);
INSERT INTO `khxx` VALUES ('404', '上海凯钟进出口贸易有限公司', '上海市镇宁路200号欣安大厦东楼15层B座', '张佳瑜031-63891863-33  13611999001 陈经理13801691110', null, null);
INSERT INTO `khxx` VALUES ('405', '上海日宽', '上海市嘉定区黄渡镇聊群村383号', '翟方生 13101931311 031-69193390', null, null);
INSERT INTO `khxx` VALUES ('406', '上海三荣（昌华）电梯制造有限公司', '021-56863030宝山区月罗路2120号邮编201908', '采购经理：陈芹13801893018/16863030-8313/李海霞 电话 031-16866688-8308', null, null);
INSERT INTO `khxx` VALUES ('407', '上海长江斯迈普电梯有限公司', '上海市曹安路3939号', '林禄保13061661883/031-39198800-8066', null, null);
INSERT INTO `khxx` VALUES ('408', '上海三荣电梯工程有限公司', '上海市阳城路183号', '余雷031-16613633', null, null);
INSERT INTO `khxx` VALUES ('409', '上海中迅赛勒瓦电梯厂（上海双达  张文钱经理 安元路372号）', '上海市普陀区镇坪路赵家宅25号310室 石泉工业园区 近中山北路 石泉路）', '张文钱厂长  徐亚芬女士031-63168136 11060631 63669186 19166861 19918991-31   19169191(褚振华)13919399036收货人:董宁巍13919991963', null, null);
INSERT INTO `khxx` VALUES ('410', '上海爱默生', '上海市普陀区志丹路260弄1号楼201室', '向明华031-66109080', null, null);
INSERT INTO `khxx` VALUES ('411', '上海磊嘉机电设备工程有限公司', '上海市嘉定区城南路1128号C118', '031-69139160-101薛士部', null, null);
INSERT INTO `khxx` VALUES ('412', '上海日洋电梯有限公司', '上海市浦东高行镇东靖路1831号803室', '吴友文031-68998900-33', null, null);
INSERT INTO `khxx` VALUES ('413', '上海铃木电梯销售有限公司', '普陀区中山北路2318号104室', '史国华13361916101/031-63010906（张锡善）13601610313', null, null);
INSERT INTO `khxx` VALUES ('414', '上海广烨', '上海市新闸路84号后门', '张永富  031-63933110  13818311191', null, null);
INSERT INTO `khxx` VALUES ('415', '上海佳登曼电梯有限公司', '上海市嘉定区徐行镇新建二路328号', '郑总031-19116666-808', null, null);
INSERT INTO `khxx` VALUES ('416', '上海伊森', '上海阳城路183号永和大厦7楼', '沈健031-66311833', null, null);
INSERT INTO `khxx` VALUES ('417', '上海房屋设备有限公司', '上海市普陀区三源路200号', '夏巍巍031-13818816-311/13691166986', null, null);
INSERT INTO `khxx` VALUES ('418', '武汉世纪菱达', '上海市浦东新区张扬路228号汤臣中心A座1917室', '胡毅刚  13919198669 TEL：031-18999939', null, null);
INSERT INTO `khxx` VALUES ('419', '上海国泰电梯有限公司', '上海市青浦区凤溪镇民兴工业区民兴三路128号', '徐逾伽 13801900393 63308696', null, null);
INSERT INTO `khxx` VALUES ('420', '上海凌天', '上海市肇嘉浜路212号明珠饭店815室', '徐艳031-66111391   13181900963', null, null);
INSERT INTO `khxx` VALUES ('421', '上海中迅电梯南市销售安装工程有限公司', '上海银行豫园支行    316120--00067267250  税号:310101132444172  地址:陆家浜路468弄30号2301室 电话:33762424', null, null, null);
INSERT INTO `khxx` VALUES ('422', '上海哲科', '南通市人民东路金路大厦C座408室。', '俞为民 13901689966', null, null);
INSERT INTO `khxx` VALUES ('423', '允成机电科技（上海）有限公司', '上海市嘉定区黄渡镇春归路585号', '031-69190960 胡小丽', null, null);
INSERT INTO `khxx` VALUES ('424', '奥克斯快速（苏州）有限公司', null, '王建琴 0113-81191983', null, null);
INSERT INTO `khxx` VALUES ('425', '上海三胜康恩得', '上海市奉贤区柘公路733号18幢', '金国平 TEL：031-19190131-813', null, null);
INSERT INTO `khxx` VALUES ('426', '上海爱默生', null, '向明华 1380191906', null, null);
INSERT INTO `khxx` VALUES ('427', '苏州菱怡', null, '于工0113-63988838 13969383066', null, null);
INSERT INTO `khxx` VALUES ('428', '上海中迅实业电梯工程公司经营部', null, '金正中 031-16338130', null, null);
INSERT INTO `khxx` VALUES ('429', '浙江奥特', null, '周先生 0193-3016161 13919088111', null, null);
INSERT INTO `khxx` VALUES ('430', '上海巨立', null, '丁先生 13818133189', null, null);
INSERT INTO `khxx` VALUES ('431', '嵊州日通电梯', null, '钱学强 0191-83036633', null, null);
INSERT INTO `khxx` VALUES ('432', '上海谷坑', '莘朱路1258号1号楼101室', '张丽娟 031-61111003-116', null, null);
INSERT INTO `khxx` VALUES ('433', '浙江威特', '浙江省义乌市杨村路335号', '马美燕 0199-83810901 FAX：0199-81633309', null, null);
INSERT INTO `khxx` VALUES ('434', '宁波器材一厂', '宁波市北仑区大港虎业城天目山16号', '陈春生 13906863309 0196-86100619', null, null);
INSERT INTO `khxx` VALUES ('435', '上海三盛康恩得', null, '金国平 031-19190131-813  FAX：031-19190133', null, null);
INSERT INTO `khxx` VALUES ('436', '温州天力', null, '李秀荣  18818931999   FAX：0199-69308810', null, null);
INSERT INTO `khxx` VALUES ('437', '上海中富', null, 'FAX：031-11308099  TEL：031-11308088', null, null);
INSERT INTO `khxx` VALUES ('438', '浙江浙奥（原台州浙奥）', '台州市椒江机场东路108号 飞跃工业园E3幢   傅燕飞：15381862510', '罗静 0196-81839388  0196-88313169 傅燕飞：11381863110', null, null);
INSERT INTO `khxx` VALUES ('439', '上海立扶特电梯有限公司', '上海奉贤区南桥镇运河路576号', ' 瞿正华  收  11300991318\n', null, null);
INSERT INTO `khxx` VALUES ('440', '浙江快速', '湖州南浔镇生力路601号（老汽车站对面）', '孙勋（采购部负责人）手机：18619318100\n传真：0193-3063919\nQQ:  11133699\n邮箱：xun.sun@zjks-elevator.com刘志琴：电话：0193-3063639\n手机：18906933806\n传真：0193-3063919\nQQ:  1966993996\n邮箱：zhiqin.liu@zjks-elevator.com', null, null);
INSERT INTO `khxx` VALUES ('441', '浙江喜来登电梯有限公司', '浙江省温州市瓯北镇东瓯工业区', '袁秀友：11383191111/18019931100  0199-66991118  朱小姐18919969938', null, null);
INSERT INTO `khxx` VALUES ('442', '上海凌天', '上海市肇嘉浜路212号明珠饭店815室', '徐艳031-66111391 13181900963', null, null);
INSERT INTO `khxx` VALUES ('443', '上海上奥', '上海市金山区金山卫镇新卫公路838号', '陆彩英 电话：60893111转3039   瞿工：13311916100', null, null);
INSERT INTO `khxx` VALUES ('444', '东芝?梯(中国)有限公司　维修部维修营业科', '上海市宝山区?川路685号', '盛　颉 031－16808888#301', null, null);
INSERT INTO `khxx` VALUES ('445', '亚洲富士长林电梯(新余)', '江西省新余市北湖西路长林工业园', '冯桂敏：0990-6363961 13809903996 罗城刚：13899093366 技术：聂世杰013969383693', null, null);
INSERT INTO `khxx` VALUES ('446', '苏州建新', '吴江市汾湖镇莘塔社区芦莘公路518号曳引机收货地址：江苏吴江市汾湖镇莘塔社区莘周公路666号（鼎升企业内）：陈新妹  15206258392', '陈建新 0113-83099696  13963101118', null, null);
INSERT INTO `khxx` VALUES ('447', '苏州迅电', '江苏省吴江市汾湖镇龙江路888号', '蔡冰冰13811363133', null, null);
INSERT INTO `khxx` VALUES ('448', '湖州三荣电梯', '浙江省湖州市南浔世纪名都8幢1单元301', '邱芳萍 0193-3030311', null, null);
INSERT INTO `khxx` VALUES ('449', '浙江西沃电梯有限公司', '浙江湖州南浔古英公路西侧68号', '0193-3890338 沈建群 18919393391 莫永良 0193-38903338 18919393399', null, null);
INSERT INTO `khxx` VALUES ('450', '宁波江东宇达', '宁波江东百丈南路61号（1-4）―', '陆爱君  0196-89896611', null, null);
INSERT INTO `khxx` VALUES ('451', '赣州市鑫安机电', '江西省赣州市伍州大道28号明珠苑B栋103室', '王晓13969966886', null, null);
INSERT INTO `khxx` VALUES ('452', '浙江法斯特电梯', '浙江湖州南浔古英公路西侧', '施云杰   薄彩红 13336813130', null, null);
INSERT INTO `khxx` VALUES ('453', '杭州霍普曼', '杭州市桐庐县瑶淋镇琴溪村', '郑菲 0191-66399611 13869119030', null, null);
INSERT INTO `khxx` VALUES ('454', '上海从太电子科技', '上海市闵行区瓶安路 1600弄19号 1002室', '朱金伟 13331968661', null, null);
INSERT INTO `khxx` VALUES ('455', '松日电梯', null, '潘总18363193333', null, null);
INSERT INTO `khxx` VALUES ('456', '上海鹏阳电梯有限公司', '收发票地址上海市大渡河路648号510室 发货地址见订单', ' 采购部联系人：陆晨强 18016610316  031-11308016', null, null);
INSERT INTO `khxx` VALUES ('457', '杭州捷巧电子', '杭州滨江区滨安路1181号电梯集团大楼4楼', '金文方 11818310813', null, null);
INSERT INTO `khxx` VALUES ('458', '苏州奥玛斯', '江苏省吴江市七都镇虹桥东路88号（双塔集团内）', '潘济欣 电话0113-63833883  13869398198（收货和发票同一收件人）', null, null);
INSERT INTO `khxx` VALUES ('459', '上海盖普', '上海市金山区枫泾镇建定路78号', ' 鲁静 11931633196', null, null);
INSERT INTO `khxx` VALUES ('460', '浙江富奥（新）', '浙江嘉兴市海盐县大桥经济开发区棕榈路999号', '张静0193-86868663  18019366631', null, null);
INSERT INTO `khxx` VALUES ('461', '松日电梯（中国）有限公司', '江苏省吴江市七都镇人民西路北侧', '顾超（总经理助理sir@srielevator.com）0113-63131813 13991699399', null, null);
INSERT INTO `khxx` VALUES ('462', '苏州默顿电梯', '苏州市桃源镇梵香经济开发区99号  0512-63760118   杨小英', '0113-63960118   杨小英', null, null);
INSERT INTO `khxx` VALUES ('463', '上海贝淳经贸', '上海市闸北区天通庵路413号108室', '周炎培 18916913136  13311913136  031-16636303', null, null);
INSERT INTO `khxx` VALUES ('464', '浙江圣普', '浙江温州市瓯海经济开发区翠柏路2号', '施小莲  0199-86939191', null, null);
INSERT INTO `khxx` VALUES ('465', '浙江伯爵电梯', '江苏吴江市七都镇虹桥东路', '邵来好 18363163113    0113-63183131', null, null);
INSERT INTO `khxx` VALUES ('466', '浙江德尔法', '浙江湖州市吴兴区环渚路915号', '张荣华0193-33011168  18001931111', null, null);
INSERT INTO `khxx` VALUES ('467', '浙江快客电梯', '浙江杭州市萧山区南阳街道阳城路66号 田涛 13486396242', '田涛13686396363', null, null);
INSERT INTO `khxx` VALUES ('468', '上海崇友', '上海市嘉定区浏翔公路2555号', '冯晓萍031-19111610', null, null);
INSERT INTO `khxx` VALUES ('469', '浙江汉诺威电梯', '浙江省桐庐县经济开发区柴梅路777号', '陈国杰18868969333', null, null);
INSERT INTO `khxx` VALUES ('479', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('480', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('481', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('482', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('483', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('484', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('485', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('486', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('487', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('488', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('489', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('490', '', null, null, null, null);
INSERT INTO `khxx` VALUES ('491', '', null, null, null, null);

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
-- Records of mpzlxx
-- ----------------------------
INSERT INTO `mpzlxx` VALUES ('1', '');
INSERT INTO `mpzlxx` VALUES ('2', '蓝光英文铭牌');
INSERT INTO `mpzlxx` VALUES ('3', '蓝光铭牌');
INSERT INTO `mpzlxx` VALUES ('4', '蓝光英文西门子监制');
INSERT INTO `mpzlxx` VALUES ('5', '主机用西德英文铭牌');
INSERT INTO `mpzlxx` VALUES ('6', '制动器和上行超速铭牌用蓝光英文');

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
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of pcjhxxb
-- ----------------------------

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
-- Records of permission
-- ----------------------------
INSERT INTO `permission` VALUES ('ADMIN', '1', '1', '1', '1', '1', '1', '1', '1');
INSERT INTO `permission` VALUES ('JHLEADER', '0', '1', '0', '1', '0', '1', '1', '1');
INSERT INTO `permission` VALUES ('USER', '0', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `permission` VALUES ('YWLEADER', '1', '0', '1', '0', '1', '0', '1', '1');

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
-- Records of user
-- ----------------------------
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
INSERT INTO `user` VALUES ('王颖', '1285384ddfb057814bad78127bc789be', '业务部', 'USER');
INSERT INTO `user` VALUES ('白艳玲', 'de14eb8ed5316b565495b43444146fb8', '计划科', 'JHLEADER');
INSERT INTO `user` VALUES ('苏璇', 'bb7822fdf4eb5fff6dba132a10cdc36a', '业务部', 'USER');
INSERT INTO `user` VALUES ('陈静', '0b4b8fdb33bc1700c1d1ba6254c55b2f', '业务部', 'USER');
INSERT INTO `user` VALUES ('陈鹤', '1956f2a1e48cca88c3194d5e7f2de48d', '业务部', 'USER');
INSERT INTO `user` VALUES ('高珊', 'c08199dc9290811a9e761e3f813a9862', '业务部', 'USER');
INSERT INTO `user` VALUES ('高英', 'e1a7cae0ea57092c97cc165440776e95', '计划科', 'JHLEADER');

-- ----------------------------
-- Table structure for yylggflxx
-- ----------------------------
DROP TABLE IF EXISTS `yylggflxx`;
CREATE TABLE `yylggflxx` (
  `yylggID` int(11) NOT NULL AUTO_INCREMENT,
  `yylgg` char(100) NOT NULL,
  PRIMARY KEY (`yylggID`)
) ENGINE=InnoDB AUTO_INCREMENT=121 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of yylggflxx
-- ----------------------------
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


-- ----------------------------
-- Table structure for zcxx
-- ----------------------------
DROP TABLE IF EXISTS `zcxx`;
CREATE TABLE `zcxx` (
  `zcxhID` int(11) NOT NULL AUTO_INCREMENT,
  `zcxh` char(100) NOT NULL,
  PRIMARY KEY (`zcxhID`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of zcxx
-- ----------------------------
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



-- ----------------------------
-- Table structure for zdqdyflxx
-- ----------------------------
DROP TABLE IF EXISTS `zdqdyflxx`;
CREATE TABLE `zdqdyflxx` (
  `zdqdyID` int(11) NOT NULL AUTO_INCREMENT,
  `zdqdy` char(100) NOT NULL,
  PRIMARY KEY (`zdqdyID`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of zdqdyflxx
-- ----------------------------
INSERT INTO `zdqdyflxx` VALUES ('1', '');
INSERT INTO `zdqdyflxx` VALUES ('2', 'DC110V');
INSERT INTO `zdqdyflxx` VALUES ('3', 'DC220V');
INSERT INTO `zdqdyflxx` VALUES ('4', 'AC110V');
INSERT INTO `zdqdyflxx` VALUES ('5', 'AC220V');
INSERT INTO `zdqdyflxx` VALUES ('6', 'DC90V');

-- ----------------------------
-- Table structure for zdqxh
-- ----------------------------
DROP TABLE IF EXISTS `zdqxh`;
CREATE TABLE `zdqxh` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `zdqxh` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of zdqxh
-- ----------------------------
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


-- ----------------------------
-- Table structure for zjdy
-- ----------------------------
DROP TABLE IF EXISTS `zjdy`;
CREATE TABLE `zjdy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `zjdy` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of zjdy
-- ----------------------------
INSERT INTO `zjdy` VALUES ('1', '');
INSERT INTO `zjdy` VALUES ('2', '220');
INSERT INTO `zjdy` VALUES ('3', '380');

-- ----------------------------
-- Table structure for zjys
-- ----------------------------
DROP TABLE IF EXISTS `zjys`;
CREATE TABLE `zjys` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `zjys` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of zjys
-- ----------------------------
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


-- ----------------------------
-- Table structure for zzs
-- ----------------------------
DROP TABLE IF EXISTS `zzs`;
CREATE TABLE `zzs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `zzs` char(100) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of zzs
-- ----------------------------
INSERT INTO `zzs` VALUES ('1', '');
INSERT INTO `zzs` VALUES ('2', '抚顺');
INSERT INTO `zzs` VALUES ('3', '佛山');
INSERT INTO `zzs` VALUES ('4', '苏州');
