package com.BlueRay.mutton.model.entity.jpa;

import java.io.Serializable;
import java.lang.reflect.Field;
import java.sql.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import com.BlueRay.mutton.service.HtxxColumn;

@Entity
@Table(name = "htxx")
public class HTXX implements Serializable {

	private Integer ID;
	private String htID = "";
	private Integer clientID = 1;
	private Integer ggxhID = 1;
	private Integer sl;
	private Integer zcID = 1;
	private String dfr = "W";
	private Integer zdqdyID = 1;
	private Integer yylggID = 1;
	private String sfjf = "N";
	private Integer bpqxhID = 1;
	private Integer bmqxhID = 1;
	private String dlcd = "";
	private String zxcd = "";
	private Integer mpzl = 1;
	private String bz = "";
	private Date ddrq;
	private Integer zjdyID = 1;
	private Integer zjysID = 1;
	private Integer zdqxhID = 1;
	private String zyz = "";
	private Integer bzxdtggID = 1;
	private String gh = "";
	private Integer zzsID = 1;
	private Integer khqyID = 1;
	private Integer yxj = 100;
	private String sftgywsh = "N";
	private String sftgjhsh = "N";
	private String ddzt = "";
	
	public Integer getZjdyID() {
		return zjdyID;
	}

	public void setZjdyID(Integer zjdyID) {
		this.zjdyID = zjdyID;
	}

	public Integer getZjysID() {
		return zjysID;
	}

	public void setZjysID(Integer zjysID) {
		this.zjysID = zjysID;
	}

	public Integer getZdqxhID() {
		return zdqxhID;
	}

	public void setZdqxhID(Integer zdqxhID) {
		this.zdqxhID = zdqxhID;
	}

	public String getZyz() {
		return zyz;
	}

	public void setZyz(String zyz) {
		this.zyz = zyz;
	}

	public Integer getBzxdtggID() {
		return bzxdtggID;
	}

	public void setBzxdtggID(Integer bzxdtggID) {
		this.bzxdtggID = bzxdtggID;
	}

	public String getGh() {
		return gh;
	}

	public void setGh(String gh) {
		this.gh = gh;
	}

	public Integer getZzsID() {
		return zzsID;
	}

	public void setZzsID(Integer zzsID) {
		this.zzsID = zzsID;
	}

	public Integer getKhqyID() {
		return khqyID;
	}

	public void setKhqyID(Integer khqyID) {
		this.khqyID = khqyID;
	}

	
	public static Field getField(int col) {
		HtxxColumn enCol = HtxxColumn.valueOf(col);
		try {
			switch (enCol) {
			case bmqxh:
				return HTXX.class.getDeclaredField("bmqxhID");
			case bpqxh:
				return HTXX.class.getDeclaredField("bpqxhID");
			case bz:
				return HTXX.class.getDeclaredField("bz");
			case bzxdtgg:
				return HTXX.class.getDeclaredField("bzxdtggID");
			case ddrq:
				return HTXX.class.getDeclaredField("ddrq");
			case dfr:
				return HTXX.class.getDeclaredField("dfr");
			case dlcd:
				return HTXX.class.getDeclaredField("dlcd");
			case end:
				break;
			case ggxh:
				return HTXX.class.getDeclaredField("ggxhID");
			case gh:
				return HTXX.class.getDeclaredField("gh");
			case hth:
				return HTXX.class.getDeclaredField("htID");
			case id:
				return HTXX.class.getDeclaredField("ID");
			case jf:
				return HTXX.class.getDeclaredField("sfjf");
			case xsjhshjh:
				return HTXX.class.getDeclaredField("sftgjhsh");
			case xsjhshyw:
				return HTXX.class.getDeclaredField("sftgywsh");
			case khmc:
				return HTXX.class.getDeclaredField("clientID");
			case khqy:
				return HTXX.class.getDeclaredField("khqyID");
			case mpzl:
				return HTXX.class.getDeclaredField("mpzl");
			case sl:
				return HTXX.class.getDeclaredField("sl");
			case yxj:
				return HTXX.class.getDeclaredField("yxj");
			case yylgg:
				return HTXX.class.getDeclaredField("yylggID");
			case zc:
				return HTXX.class.getDeclaredField("zcID");
			case zdqdy:
				return HTXX.class.getDeclaredField("zdqdyID");
			case zdqxh:
				return HTXX.class.getDeclaredField("zdqxhID");
			case zjdy:
				return HTXX.class.getDeclaredField("zjdyID");
			case zjys:
				return HTXX.class.getDeclaredField("zjysID");
			case zxcd:
				return HTXX.class.getDeclaredField("zxcd");
			case zyz:
				return HTXX.class.getDeclaredField("zyz");
			case zzs:
				return HTXX.class.getDeclaredField("zzsID");
			default:
				break;
			}
		} catch (NoSuchFieldException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public static Class<?>  getFroeignClass(int col){
		
		if(HtxxColumn.khmc.ordinal() == col){
			return KHXX.class;
		} else if(HtxxColumn.ggxh.ordinal() == col){
			return CPGGXHXX.class;
		} else if(HtxxColumn.zc.ordinal() == col){
			return ZCXX.class;
		} else if(HtxxColumn.zdqdy.ordinal() == col){
			return ZDQDYFLXX.class;
		} else if(HtxxColumn.yylgg.ordinal() == col){
			return YYLGGFLXX.class;
		} else if(HtxxColumn.bpqxh.ordinal() == col){
			return BPQXHFLXX.class;
		} else if(HtxxColumn.bmqxh.ordinal() == col){
			return BMQXHFLXX.class;
		} else if(HtxxColumn.mpzl.ordinal() == col){
			return MPZLXX.class;
		} else if(HtxxColumn.zjdy.ordinal() == col){
			return ZJDY.class;
		} else if(HtxxColumn.zjys.ordinal() == col){
			return ZJYS.class;
		} else if(HtxxColumn.zdqxh.ordinal() == col){
			return ZDQXH.class;
		} else if(HtxxColumn.bzxdtgg.ordinal() == col){
			return BZXDTGG.class;
		} else if(HtxxColumn.zzs.ordinal() == col){
			return ZZS.class;
		} else if(HtxxColumn.khqy.ordinal() == col){
			return KHQY.class;
		} else{
			return null;
		}
	}
	
	public Integer getYxj() {
		return yxj;
	}
	public void setYxj(Integer yxj) {
		this.yxj = yxj;
	}
	/**
	 * @return the iD
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getID() {
		return ID;
	}
	/**
	 * @return the htID
	 */
	public String getHtID() {
		return htID;
	}
	/**
	 * @return the clientID
	 */
	public Integer getClientID() {
		return clientID;
	}
	/**
	 * @return the ggxhID
	 */
	public Integer getGgxhID() {
		return ggxhID;
	}
	/**
	 * @return the sl
	 */
	public Integer getSl() {
		return sl;
	}
	/**
	 * @return the zcID
	 */
	public Integer getZcID() {
		return zcID;
	}
	/**
	 * @return the dfr
	 */
	public String getDfr() {
		return dfr;
	}
	/**
	 * @return the zdqdyID
	 */
	public Integer getZdqdyID() {
		return zdqdyID;
	}
	/**
	 * @return the yylggID
	 */
	public Integer getYylggID() {
		return yylggID;
	}
	/**
	 * @return the sfjf
	 */
	public String getSfjf() {
		return sfjf;
	}
	/**
	 * @return the bpqxhID
	 */
	public Integer getBpqxhID() {
		return bpqxhID;
	}
	/**
	 * @return the bmqxhID
	 */
	public Integer getBmqxhID() {
		return bmqxhID;
	}
	/**
	 * @return the dlcd
	 */
	public String getDlcd() {
		return dlcd;
	}
	/**
	 * @return the zxcd
	 */
	public String getZxcd() {
		return zxcd;
	}
	/**
	 * @return the mpzl
	 */
	public Integer getMpzl() {
		return mpzl;
	}
	/**
	 * @return the ddrq
	 */
	public Date getDdrq() {
		return ddrq;
	}
	/**
	 * @return the bz
	 */
	public String getBz() {
		return bz;
	}
	/**
	 * @return the ddzt
	 */
	public String getDdzt() {
		return ddzt;
	}
	/**
	 * @return the sftgywsh
	 */
	public String getSftgywsh() {
		return sftgywsh;
	}
	/**
	 * @return the sftgjhsh
	 */
	public String getSftgjhsh() {
		return sftgjhsh;
	}
	/**
	 * @param iD the iD to set
	 */
	public void setID(Integer iD) {
		ID = iD;
	}
	/**
	 * @param htID the htID to set
	 */
	public void setHtID(String htID) {
		this.htID = htID;
	}
	/**
	 * @param clientID the clientID to set
	 */
	public void setClientID(Integer clientID) {
		this.clientID = clientID;
	}
	/**
	 * @param ggxhID the ggxhID to set
	 */
	public void setGgxhID(Integer ggxhID) {
		this.ggxhID = ggxhID;
	}
	/**
	 * @param sl the sl to set
	 */
	public void setSl(Integer sl) {
		this.sl = sl;
	}
	/**
	 * @param zcID the zcID to set
	 */
	public void setZcID(Integer zcID) {
		this.zcID = zcID;
	}
	/**
	 * @param dfr the dfr to set
	 */
	public void setDfr(String dfr) {
		this.dfr = dfr;
	}
	/**
	 * @param zdqdyID the zdqdyID to set
	 */
	public void setZdqdyID(Integer zdqdyID) {
		this.zdqdyID = zdqdyID;
	}
	/**
	 * @param yylggID the yylggID to set
	 */
	public void setYylggID(Integer yylggID) {
		this.yylggID = yylggID;
	}
	/**
	 * @param sfjf the sfjf to set
	 */
	public void setSfjf(String sfjf) {
		this.sfjf = sfjf;
	}
	/**
	 * @param bpqxhID the bpqxhID to set
	 */
	public void setBpqxhID(Integer bpqxhID) {
		this.bpqxhID = bpqxhID;
	}
	/**
	 * @param bmqxhID the bmqxhID to set
	 */
	public void setBmqxhID(Integer bmqxhID) {
		this.bmqxhID = bmqxhID;
	}
	/**
	 * @param dlcd the dlcd to set
	 */
	public void setDlcd(String dlcd) {
		this.dlcd = dlcd;
	}
	/**
	 * @param zxcd the zxcd to set
	 */
	public void setZxcd(String zxcd) {
		this.zxcd = zxcd;
	}
	/**
	 * @param mpzl the mpzl to set
	 */
	public void setMpzl(Integer mpzl) {
		this.mpzl = mpzl;
	}
	/**
	 * @param ddrq the ddrq to set
	 */
	public void setDdrq(Date ddrq) {
		this.ddrq = ddrq;
	}
	/**
	 * @param bz the bz to set
	 */
	public void setBz(String bz) {
		this.bz = bz;
	}
	/**
	 * @param ddzt the ddzt to set
	 */
	public void setDdzt(String ddzt) {
		this.ddzt = ddzt;
	}
	/**
	 * @param sftgywsh the sftgywsh to set
	 */
	public void setSftgywsh(String sftgywsh) {
		this.sftgywsh = sftgywsh;
	}
	/**
	 * @param sftgjhsh the sftgjhsh to set
	 */
	public void setSftgjhsh(String sftgjhsh) {
		this.sftgjhsh = sftgjhsh;
	}
	

}
