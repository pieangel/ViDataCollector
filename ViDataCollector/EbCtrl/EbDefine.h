#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿܼ��� ���񸶽��� ��ȸ ( ATTR,BLOCK,HEADTYPE=A )
#pragma pack( push, 1 )

// �ؿ� ���� ���� ������ ��ȸ 
#define NAME_o3101     "o3101"
// �ؿ� ���� �к� ��Ʈ ��ȸ
#define NAME_o3103     "o3103"
// ���� �ֽ� ��� �������� - �ڽ���, �ڽ��� ����
#define NAME_t9945     "t9945"
#define NAME_t8436     "t8436"
// ���� �ֽ� ����Ʈ ������ ��������
#define NAME_t8412     "t8412"
// ���� �ֽ� ��/��/�� ������ ��������
#define NAME_t8413     "t8413"
// �ǽð� �ֽ� �ü� ���
#define NAME_S3_     "S3_"
#define NAME_I5_     "I5_"
// ���� ���� �ǽð� �ü� ���
#define NAME_FC0     "FC0" // �ü�
#define NAME_FH0     "FH0" // ȣ��
// ���� �ɼ� �ǽð� �ü� ���
#define NAME_OC0     "OC0" // �ü� 
#define NAME_OH0     "OH0" // ȣ��
// �ؿ� ���� �ǽð� �ü� ���
#define NAME_OVC     "OVC" // �ü�
#define NAME_H1_     "H1_" // ȣ��


///////////////////////////////////////////////////////////////////////////////////////////////////
// ��ǰ���� ������ ��ȸ ( BLOCK,HEADTYPE=A )


#define NAME_t8426     "t8426"

// �⺻�Է�                       
typedef struct _t8426InBlock
{
	char    dummy[1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t8426InBlock, * LPt8426InBlock;
#define NAME_t8426InBlock     "t8426InBlock"

// �ֽ����񸶽���                 , occurs
typedef struct _t8426OutBlock
{
	char    hname[20];    // [string,   20] �����                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] �����ڵ�                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 28, Length 12
} t8426OutBlock, * LPt8426OutBlock;
#define NAME_t8426OutBlock     "t8426OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
// �Ļ����񸶽�����ȸAPI�� ( BLOCK,HEADTYPE=A )


#define NAME_t8435     "t8435"

// �⺻�Է�                       
typedef struct _t8435InBlock
{
	char    gubun[2];    // [string,    2] ����(MF/MO)                     StartPos 0, Length 2
} t8435InBlock, * LPt8435InBlock;
#define NAME_t8435InBlock     "t8435InBlock"

// �Ļ����񸶽���                 , occurs
typedef struct _t8435OutBlock
{
	char    hname[20];    // [string,   20] �����                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] �����ڵ�                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 28, Length 12
	char    uplmtprice[6];    // [float ,  6.2] ���Ѱ�                          StartPos 40, Length 6
	char    dnlmtprice[6];    // [float ,  6.2] ���Ѱ�                          StartPos 46, Length 6
	char    jnilclose[6];    // [float ,  6.2] ��������                        StartPos 52, Length 6
	char    jnilhigh[6];    // [float ,  6.2] ���ϰ�                        StartPos 58, Length 6
	char    jnillow[6];    // [float ,  6.2] ��������                        StartPos 64, Length 6
	char    recprice[6];    // [float ,  6.2] ���ذ�                          StartPos 70, Length 6
} t8435OutBlock, * LPt8435OutBlock;
#define NAME_t8435OutBlock     "t8435OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼǸ�������ȸ API�� ( BLOCK,HEADTYPE=A )


#define NAME_t9944     "t9944"

// �⺻�Է�                       
typedef struct _t9944InBlock
{
	char    dummy[1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t9944InBlock, * LPt9944InBlock;
#define NAME_t9944InBlock     "t9944InBlock"

// �ֽ����񸶽���                 , occurs
typedef struct _t9944OutBlock
{
	char    hname[20];    // [string,   20] �����                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] �����ڵ�                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 28, Length 12
} t9944OutBlock, * LPt9944OutBlock;
#define NAME_t9944OutBlock     "t9944OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// ����������������ȸ API�� ( BLOCK,HEADTYPE=A )


#define NAME_t9943     "t9943"

// �⺻�Է�                       
typedef struct _t9943InBlock
{
	char    gubun[1];    // [string,    1] ����                            StartPos 0, Length 1
} t9943InBlock, * LPt9943InBlock;
#define NAME_t9943InBlock     "t9943InBlock"

// �ֽ����񸶽���                 , occurs
typedef struct _t9943OutBlock
{
	char    hname[20];    // [string,   20] �����                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] �����ڵ�                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 28, Length 12
} t9943OutBlock, * LPt9943OutBlock;
#define NAME_t9943OutBlock     "t9943OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////


// �⺻�Է�                       
typedef struct _o3101InBlock
{
	char    gubun[1];    char    _gubun;    // [string,    1] �Է±���(����)                  StartPos 0, Length 1
} o3101InBlock, * LPo3101InBlock;
#define NAME_o3101InBlock     "o3101InBlock"

// ���-������                    , occurs
typedef struct _o3101OutBlock
{
	char    Symbol[8];    char    _Symbol;    // [string,    8] �����ڵ�                        StartPos 0, Length 8
	char    SymbolNm[50];    char    _SymbolNm;    // [string,   50] �����                          StartPos 9, Length 50
	char    ApplDate[8];    char    _ApplDate;    // [string,    8] �����ġ������(�ѱ�����)        StartPos 60, Length 8
	char    BscGdsCd[10];    char    _BscGdsCd;    // [string,   10] ���ʻ�ǰ�ڵ�                    StartPos 69, Length 10
	char    BscGdsNm[40];    char    _BscGdsNm;    // [string,   40] ���ʻ�ǰ��                      StartPos 80, Length 40
	char    ExchCd[10];    char    _ExchCd;    // [string,   10] �ŷ����ڵ�                      StartPos 121, Length 10
	char    ExchNm[40];    char    _ExchNm;    // [string,   40] �ŷ��Ҹ�                        StartPos 132, Length 40
	char    CrncyCd[3];    char    _CrncyCd;    // [string,    3] ������ȭ�ڵ�                    StartPos 173, Length 3
	char    NotaCd[3];    char    _NotaCd;    // [string,    3] ���������ڵ�                    StartPos 177, Length 3
	char    UntPrc[15];    char    _UntPrc;    // [double, 15.9] ȣ����������                    StartPos 181, Length 15
	char    MnChgAmt[15];    char    _MnChgAmt;    // [double, 15.9] �ּҰ��ݺ����ݾ�                StartPos 197, Length 15
	char    RgltFctr[15];    char    _RgltFctr;    // [double,15.10] �����������                    StartPos 213, Length 15
	char    CtrtPrAmt[15];    char    _CtrtPrAmt;    // [double, 15.2] ����ݾ�                      StartPos 229, Length 15
	char    GdsCd[3];    char    _GdsCd;    // [string,    3] ��ǰ�����ڵ�                    StartPos 245, Length 3
	char    LstngYr[4];    char    _LstngYr;    // [string,    4] ����(��)                        StartPos 249, Length 4
	char    LstngM[1];    char    _LstngM;    // [string,    1] ����(��)                        StartPos 254, Length 1
	char    EcPrc[15];    char    _EcPrc;    // [double, 15.9] ���갡��                        StartPos 256, Length 15
	char    DlStrtTm[6];    char    _DlStrtTm;    // [string,    6] �ŷ����۽ð�                    StartPos 272, Length 6
	char    DlEndTm[6];    char    _DlEndTm;    // [string,    6] �ŷ�����ð�                    StartPos 279, Length 6
	char    DlPsblCd[1];    char    _DlPsblCd;    // [string,    1] �ŷ����ɱ����ڵ�                StartPos 286, Length 1
	char    MgnCltCd[1];    char    _MgnCltCd;    // [string,    1] ���ű�¡�������ڵ�              StartPos 288, Length 1
	char    OpngMgn[15];    char    _OpngMgn;    // [double, 15.2] �������ű�                      StartPos 290, Length 15
	char    MntncMgn[15];    char    _MntncMgn;    // [double, 15.2] �������ű�                      StartPos 306, Length 15
	char    OpngMgnR[7];    char    _OpngMgnR;    // [double,  7.3] �������ű���                    StartPos 322, Length 7
	char    MntncMgnR[7];    char    _MntncMgnR;    // [double,  7.3] �������ű���                    StartPos 330, Length 7
	char    DotGb[2];    char    _DotGb;    // [long  ,    2] ��ȿ�Ҽ����ڸ���                StartPos 338, Length 2
} o3101OutBlock, * LPo3101OutBlock;
#define NAME_o3101OutBlock     "o3101OutBlock"


// �⺻�Է�                       
typedef struct _o3103InBlock
{
	char    shcode[8];    char    _shcode;    // [string,    8] �����ڵ�                        StartPos 0, Length 8
	char    ncnt[4];    char    _ncnt;    // [long  ,    4] N���ֱ�                         StartPos 9, Length 4
	char    readcnt[4];    char    _readcnt;    // [long  ,    4] ��ȸ�Ǽ�                        StartPos 14, Length 4
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 19, Length 8
	char    cts_time[6];    char    _cts_time;    // [string,    6] ���ӽð�                        StartPos 28, Length 6
} o3103InBlock, * LPo3103InBlock;
#define NAME_o3103InBlock     "o3103InBlock"

// ���                           
typedef struct _o3103OutBlock
{
	char    shcode[8];    char    _shcode;    // [string,    8] �����ڵ�                        StartPos 0, Length 8
	char    timediff[4];    char    _timediff;    // [long  ,    4] ����                            StartPos 9, Length 4
	char    readcnt[4];    char    _readcnt;    // [long  ,    4] ��ȸ�Ǽ�                        StartPos 14, Length 4
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 19, Length 8
	char    cts_time[6];    char    _cts_time;    // [string,    6] ���ӽð�                        StartPos 28, Length 6
} o3103OutBlock, * LPo3103OutBlock;
#define NAME_o3103OutBlock     "o3103OutBlock"

// ���1                          , occurs
typedef struct _o3103OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] ��¥                            StartPos 0, Length 8
	char    time[6];    char    _time;    // [string,    6] �����ð�                        StartPos 9, Length 6
	char    open[15];    char    _open;    // [double, 15.9] �ð�                            StartPos 16, Length 15
	char    high[15];    char    _high;    // [double, 15.9] ��                            StartPos 32, Length 15
	char    low[15];    char    _low;    // [double, 15.9] ����                            StartPos 48, Length 15
	char    close[15];    char    _close;    // [double, 15.9] ����                            StartPos 64, Length 15
	char    volume[12];    char    _volume;    // [long  ,   12] �ŷ���                          StartPos 80, Length 12
} o3103OutBlock1, * LPo3103OutBlock1;
#define NAME_o3103OutBlock1     "o3103OutBlock1"

// �⺻�Է�                       
typedef struct _t9945InBlock
{
	char    gubun[1];    // [string,    1] ����(KSP:1KSD:2)                StartPos 0, Length 1
} t9945InBlock, * LPt9945InBlock;
#define NAME_t9945InBlock     "t9945InBlock"

// �ֽ����񸶽���                 , occurs
typedef struct _t9945OutBlock
{
	char    hname[40];    // [string,   40] �����                          StartPos 0, Length 40
	char    shcode[6];    // [string,    6] �����ڵ�                        StartPos 40, Length 6
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 46, Length 12
	char    etfchk[1];    // [string,    1] ETF����                         StartPos 58, Length 1
	char    filler[5];    // [string,    5] filler                          StartPos 59, Length 5
} t9945OutBlock, * LPt9945OutBlock;
#define NAME_t9945OutBlock     "t9945OutBlock"

// �⺻�Է�                       
typedef struct _t8436InBlock
{
	char    gubun[1];    // [string,    1] ����(0:��ü1:�ڽ���2:�ڽ���)    StartPos 0, Length 1
} t8436InBlock, * LPt8436InBlock;
#define NAME_t8436InBlock     "t8436InBlock"

// ���1                          , occurs
typedef struct _t8436OutBlock
{
	char    hname[20];    // [string,   20] �����                          StartPos 0, Length 20
	char    shcode[6];    // [string,    6] �����ڵ�                        StartPos 20, Length 6
	char    expcode[12];    // [string,   12] Ȯ���ڵ�                        StartPos 26, Length 12
	char    etfgubun[1];    // [string,    1] ETF����(1:ETF2:ETN)             StartPos 38, Length 1
	char    uplmtprice[8];    // [long  ,    8] ���Ѱ�                          StartPos 39, Length 8
	char    dnlmtprice[8];    // [long  ,    8] ���Ѱ�                          StartPos 47, Length 8
	char    jnilclose[8];    // [long  ,    8] ���ϰ�                          StartPos 55, Length 8
	char    memedan[5];    // [string,    5] �ֹ���������                    StartPos 63, Length 5
	char    recprice[8];    // [long  ,    8] ���ذ�                          StartPos 68, Length 8
	char    gubun[1];    // [string,    1] ����(1:�ڽ���2:�ڽ���)          StartPos 76, Length 1
	char    bu12gubun[2];    // [string,    2] ���Ǳ׷�                        StartPos 77, Length 2
	char    spac_gubun[1];    // [string,    1] ����μ�����ȸ�翩��(Y/N)       StartPos 79, Length 1
	char    filler[32];    // [string,   32] filler(�̻��)                  StartPos 80, Length 32
} t8436OutBlock, * LPt8436OutBlock;
#define NAME_t8436OutBlock     "t8436OutBlock"


// �⺻�Է�                       
typedef struct _t8412InBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 0, Length 6
	char    ncnt[4];    char    _ncnt;    // [long  ,    4] ����(n��)                       StartPos 7, Length 4
	char    qrycnt[4];    char    _qrycnt;    // [long  ,    4] ��û�Ǽ�(�ִ�-����:2000�����:5 StartPos 12, Length 4
	char    nday[1];    char    _nday;    // [string,    1] ��ȸ�����ϼ�(0:�̻��1>=���)   StartPos 17, Length 1
	char    sdate[8];    char    _sdate;    // [string,    8] ��������                        StartPos 19, Length 8
	char    stime[6];    char    _stime;    // [string,    6] ���۽ð�(����̻��)            StartPos 28, Length 6
	char    edate[8];    char    _edate;    // [string,    8] ��������                        StartPos 35, Length 8
	char    etime[6];    char    _etime;    // [string,    6] ����ð�(����̻��)            StartPos 44, Length 6
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 51, Length 8
	char    cts_time[10];    char    _cts_time;    // [string,   10] ���ӽð�                        StartPos 60, Length 10
	char    comp_yn[1];    char    _comp_yn;    // [string,    1] ���࿩��(Y:����N:�����)        StartPos 71, Length 1
} t8412InBlock, * LPt8412InBlock;
#define NAME_t8412InBlock     "t8412InBlock"

// ���                           
typedef struct _t8412OutBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 0, Length 6
	char    jisiga[8];    char    _jisiga;    // [long  ,    8] ���Ͻð�                        StartPos 7, Length 8
	char    jihigh[8];    char    _jihigh;    // [long  ,    8] ���ϰ�                        StartPos 16, Length 8
	char    jilow[8];    char    _jilow;    // [long  ,    8] ��������                        StartPos 25, Length 8
	char    jiclose[8];    char    _jiclose;    // [long  ,    8] ��������                        StartPos 34, Length 8
	char    jivolume[12];    char    _jivolume;    // [long  ,   12] ���ϰŷ���                      StartPos 43, Length 12
	char    disiga[8];    char    _disiga;    // [long  ,    8] ���Ͻð�                        StartPos 56, Length 8
	char    dihigh[8];    char    _dihigh;    // [long  ,    8] ���ϰ�                        StartPos 65, Length 8
	char    dilow[8];    char    _dilow;    // [long  ,    8] ��������                        StartPos 74, Length 8
	char    diclose[8];    char    _diclose;    // [long  ,    8] ��������                        StartPos 83, Length 8
	char    highend[8];    char    _highend;    // [long  ,    8] ���Ѱ�                          StartPos 92, Length 8
	char    lowend[8];    char    _lowend;    // [long  ,    8] ���Ѱ�                          StartPos 101, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 110, Length 8
	char    cts_time[10];    char    _cts_time;    // [string,   10] ���ӽð�                        StartPos 119, Length 10
	char    s_time[6];    char    _s_time;    // [string,    6] ����۽ð�(HHMMSS)              StartPos 130, Length 6
	char    e_time[6];    char    _e_time;    // [string,    6] ������ð�(HHMMSS)              StartPos 137, Length 6
	char    dshmin[2];    char    _dshmin;    // [string,    2] ����ȣ��ó���ð�(MM:��)         StartPos 144, Length 2
	char    rec_count[7];    char    _rec_count;    // [long  ,    7] ���ڵ�ī��Ʈ                    StartPos 147, Length 7
} t8412OutBlock, * LPt8412OutBlock;
#define NAME_t8412OutBlock     "t8412OutBlock"

// ���1                          , occurs
typedef struct _t8412OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] ��¥                            StartPos 0, Length 8
	char    time[10];    char    _time;    // [string,   10] �ð�                            StartPos 9, Length 10
	char    open[8];    char    _open;    // [long  ,    8] �ð�                            StartPos 20, Length 8
	char    high[8];    char    _high;    // [long  ,    8] ��                            StartPos 29, Length 8
	char    low[8];    char    _low;    // [long  ,    8] ����                            StartPos 38, Length 8
	char    close[8];    char    _close;    // [long  ,    8] ����                            StartPos 47, Length 8
	char    jdiff_vol[12];    char    _jdiff_vol;    // [long  ,   12] �ŷ���                          StartPos 56, Length 12
	char    value[12];    char    _value;    // [long  ,   12] �ŷ����                        StartPos 69, Length 12
	char    jongchk[13];    char    _jongchk;    // [long  ,   13] ��������                        StartPos 82, Length 13
	char    rate[6];    char    _rate;    // [double,  6.2] ��������                        StartPos 96, Length 6
	char    sign[1];    char    _sign;    // [string,    1] �����������(1:����2:���3:���� StartPos 103, Length 1
} t8412OutBlock1, * LPt8412OutBlock1;
#define NAME_t8412OutBlock1     "t8412OutBlock1"

// �⺻�Է�                       
typedef struct _t8413InBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 0, Length 6
	char    gubun[1];    char    _gubun;    // [string,    1] �ֱⱸ��(2:��3:��4:��)          StartPos 7, Length 1
	char    qrycnt[4];    char    _qrycnt;    // [long  ,    4] ��û�Ǽ�(�ִ�-����:2000�����:5 StartPos 9, Length 4
	char    sdate[8];    char    _sdate;    // [string,    8] ��������                        StartPos 14, Length 8
	char    edate[8];    char    _edate;    // [string,    8] ��������                        StartPos 23, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 32, Length 8
	char    comp_yn[1];    char    _comp_yn;    // [string,    1] ���࿩��(Y:����N:�����)        StartPos 41, Length 1
} t8413InBlock, * LPt8413InBlock;
#define NAME_t8413InBlock     "t8413InBlock"

// ���                           
typedef struct _t8413OutBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 0, Length 6
	char    jisiga[8];    char    _jisiga;    // [long  ,    8] ���Ͻð�                        StartPos 7, Length 8
	char    jihigh[8];    char    _jihigh;    // [long  ,    8] ���ϰ�                        StartPos 16, Length 8
	char    jilow[8];    char    _jilow;    // [long  ,    8] ��������                        StartPos 25, Length 8
	char    jiclose[8];    char    _jiclose;    // [long  ,    8] ��������                        StartPos 34, Length 8
	char    jivolume[12];    char    _jivolume;    // [long  ,   12] ���ϰŷ���                      StartPos 43, Length 12
	char    disiga[8];    char    _disiga;    // [long  ,    8] ���Ͻð�                        StartPos 56, Length 8
	char    dihigh[8];    char    _dihigh;    // [long  ,    8] ���ϰ�                        StartPos 65, Length 8
	char    dilow[8];    char    _dilow;    // [long  ,    8] ��������                        StartPos 74, Length 8
	char    diclose[8];    char    _diclose;    // [long  ,    8] ��������                        StartPos 83, Length 8
	char    highend[8];    char    _highend;    // [long  ,    8] ���Ѱ�                          StartPos 92, Length 8
	char    lowend[8];    char    _lowend;    // [long  ,    8] ���Ѱ�                          StartPos 101, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] ��������                        StartPos 110, Length 8
	char    s_time[6];    char    _s_time;    // [string,    6] ����۽ð�(HHMMSS)              StartPos 119, Length 6
	char    e_time[6];    char    _e_time;    // [string,    6] ������ð�(HHMMSS)              StartPos 126, Length 6
	char    dshmin[2];    char    _dshmin;    // [string,    2] ����ȣ��ó���ð�(MM:��)         StartPos 133, Length 2
	char    rec_count[7];    char    _rec_count;    // [long  ,    7] ���ڵ�ī��Ʈ                    StartPos 136, Length 7
} t8413OutBlock, * LPt8413OutBlock;
#define NAME_t8413OutBlock     "t8413OutBlock"

// ���1                          , occurs
typedef struct _t8413OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] ��¥                            StartPos 0, Length 8
	char    open[8];    char    _open;    // [long  ,    8] �ð�                            StartPos 9, Length 8
	char    high[8];    char    _high;    // [long  ,    8] ��                            StartPos 18, Length 8
	char    low[8];    char    _low;    // [long  ,    8] ����                            StartPos 27, Length 8
	char    close[8];    char    _close;    // [long  ,    8] ����                            StartPos 36, Length 8
	char    jdiff_vol[12];    char    _jdiff_vol;    // [long  ,   12] �ŷ���                          StartPos 45, Length 12
	char    value[12];    char    _value;    // [long  ,   12] �ŷ����                        StartPos 58, Length 12
	char    jongchk[13];    char    _jongchk;    // [long  ,   13] ��������                        StartPos 71, Length 13
	char    rate[6];    char    _rate;    // [double,  6.2] ��������                        StartPos 85, Length 6
	char    pricechk[13];    char    _pricechk;    // [long  ,   13] �����ְ��ݿ��׸�                StartPos 92, Length 13
	char    ratevalue[12];    char    _ratevalue;    // [long  ,   12] ���������ݿ��ŷ����            StartPos 106, Length 12
	char    sign[1];    char    _sign;    // [string,    1] �����������(1:����2:���3:���� StartPos 119, Length 1
} t8413OutBlock1, * LPt8413OutBlock1;
#define NAME_t8413OutBlock1     "t8413OutBlock1"


// �Է�                           
typedef struct _S3__InBlock
{
	char    shcode[6];    // [string,    6] �����ڵ�                        StartPos 0, Length 6
} S3__InBlock, * LPS3__InBlock;
#define NAME_S3__InBlock     "InBlock"

// ���                           
typedef struct _S3__OutBlock
{
	char    chetime[6];    char    _chetime;    // [string,    6] ü��ð�                        StartPos 0, Length 6
	char    sign[1];    char    _sign;    // [string,    1] ���ϴ�񱸺�                    StartPos 7, Length 1
	char    change[8];    char    _change;    // [long  ,    8] ���ϴ��                        StartPos 9, Length 8
	char    drate[6];    char    _drate;    // [float ,  6.2] �����                          StartPos 18, Length 6
	char    price[8];    char    _price;    // [long  ,    8] ���簡                          StartPos 25, Length 8
	char    opentime[6];    char    _opentime;    // [string,    6] �ð��ð�                        StartPos 34, Length 6
	char    open[8];    char    _open;    // [long  ,    8] �ð�                            StartPos 41, Length 8
	char    hightime[6];    char    _hightime;    // [string,    6] ���ð�                        StartPos 50, Length 6
	char    high[8];    char    _high;    // [long  ,    8] ��                            StartPos 57, Length 8
	char    lowtime[6];    char    _lowtime;    // [string,    6] �����ð�                        StartPos 66, Length 6
	char    low[8];    char    _low;    // [long  ,    8] ����                            StartPos 73, Length 8
	char    cgubun[1];    char    _cgubun;    // [string,    1] ü�ᱸ��                        StartPos 82, Length 1
	char    cvolume[8];    char    _cvolume;    // [long  ,    8] ü�ᷮ                          StartPos 84, Length 8
	char    volume[12];    char    _volume;    // [long  ,   12] �����ŷ���                      StartPos 93, Length 12
	char    value[12];    char    _value;    // [long  ,   12] �����ŷ����                    StartPos 106, Length 12
	char    mdvolume[12];    char    _mdvolume;    // [long  ,   12] �ŵ�����ü�ᷮ                  StartPos 119, Length 12
	char    mdchecnt[8];    char    _mdchecnt;    // [long  ,    8] �ŵ�����ü��Ǽ�                StartPos 132, Length 8
	char    msvolume[12];    char    _msvolume;    // [long  ,   12] �ż�����ü�ᷮ                  StartPos 141, Length 12
	char    mschecnt[8];    char    _mschecnt;    // [long  ,    8] �ż�����ü��Ǽ�                StartPos 154, Length 8
	char    cpower[9];    char    _cpower;    // [float ,  9.2] ü�ᰭ��                        StartPos 163, Length 9
	char    w_avrg[8];    char    _w_avrg;    // [long  ,    8] ������հ�                      StartPos 173, Length 8
	char    offerho[8];    char    _offerho;    // [long  ,    8] �ŵ�ȣ��                        StartPos 182, Length 8
	char    bidho[8];    char    _bidho;    // [long  ,    8] �ż�ȣ��                        StartPos 191, Length 8
	char    status[2];    char    _status;    // [string,    2] ������                          StartPos 200, Length 2
	char    jnilvolume[12];    char    _jnilvolume;    // [long  ,   12] ���ϵ��ð���ŷ���              StartPos 203, Length 12
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 216, Length 6
} S3__OutBlock, * LPS3__OutBlock;
#define NAME_S3__OutBlock     "OutBlock"


// �Է�                           
typedef struct _FC0_InBlock
{
	char    futcode[8];     // [string,    8] �����ڵ�                        StartPos 0, Length 8
} FC0_InBlock, * LPFC0_InBlock;
#define NAME_FC0_InBlock     "InBlock"

// ���                           
typedef struct _FC0_OutBlock
{
	char    chetime[6];    char    _chetime;    // [string,    6] ü��ð�                        StartPos 0, Length 6
	char    sign[1];    char    _sign;    // [string,    1] ���ϴ�񱸺�                    StartPos 7, Length 1
	char    change[6];    char    _change;    // [float ,  6.2] ���ϴ��                        StartPos 9, Length 6
	char    drate[6];    char    _drate;    // [float ,  6.2] �����                          StartPos 16, Length 6
	char    price[6];    char    _price;    // [float ,  6.2] ���簡                          StartPos 23, Length 6
	char    open[6];    char    _open;    // [float ,  6.2] �ð�                            StartPos 30, Length 6
	char    high[6];    char    _high;    // [float ,  6.2] ��                            StartPos 37, Length 6
	char    low[6];    char    _low;    // [float ,  6.2] ����                            StartPos 44, Length 6
	char    cgubun[1];    char    _cgubun;    // [string,    1] ü�ᱸ��                        StartPos 51, Length 1
	char    cvolume[6];    char    _cvolume;    // [long  ,    6] ü�ᷮ                          StartPos 53, Length 6
	char    volume[12];    char    _volume;    // [long  ,   12] �����ŷ���                      StartPos 60, Length 12
	char    value[12];    char    _value;    // [long  ,   12] �����ŷ����                    StartPos 73, Length 12
	char    mdvolume[12];    char    _mdvolume;    // [long  ,   12] �ŵ�����ü�ᷮ                  StartPos 86, Length 12
	char    mdchecnt[8];    char    _mdchecnt;    // [long  ,    8] �ŵ�����ü��Ǽ�                StartPos 99, Length 8
	char    msvolume[12];    char    _msvolume;    // [long  ,   12] �ż�����ü�ᷮ                  StartPos 108, Length 12
	char    mschecnt[8];    char    _mschecnt;    // [long  ,    8] �ż�����ü��Ǽ�                StartPos 121, Length 8
	char    cpower[9];    char    _cpower;    // [float ,  9.2] ü�ᰭ��                        StartPos 130, Length 9
	char    offerho1[6];    char    _offerho1;    // [float ,  6.2] �ŵ�ȣ��1                       StartPos 140, Length 6
	char    bidho1[6];    char    _bidho1;    // [float ,  6.2] �ż�ȣ��1                       StartPos 147, Length 6
	char    openyak[8];    char    _openyak;    // [long  ,    8] �̰�����������                  StartPos 154, Length 8
	char    k200jisu[6];    char    _k200jisu;    // [float ,  6.2] KOSPI200����                    StartPos 163, Length 6
	char    theoryprice[6];    char    _theoryprice;    // [float ,  6.2] �̷а�                          StartPos 170, Length 6
	char    kasis[6];    char    _kasis;    // [float ,  6.2] ������                          StartPos 177, Length 6
	char    sbasis[6];    char    _sbasis;    // [float ,  6.2] ����BASIS                       StartPos 184, Length 6
	char    ibasis[6];    char    _ibasis;    // [float ,  6.2] �̷�BASIS                       StartPos 191, Length 6
	char    openyakcha[8];    char    _openyakcha;    // [long  ,    8] �̰�����������                  StartPos 198, Length 8
	char    jgubun[2];    char    _jgubun;    // [string,    2] ������                      StartPos 207, Length 2
	char    jnilvolume[12];    char    _jnilvolume;    // [long  ,   12] ���ϵ��ð���ŷ���              StartPos 210, Length 12
	char    futcode[8];    char    _futcode;    // [string,    8] �����ڵ�                        StartPos 223, Length 8
} FC0_OutBlock, * LPFC0_OutBlock;
#define NAME_FC0_OutBlock     "OutBlock"

// �Է�                           
typedef struct _OVC_InBlock
{
	char    symbol[8];    // [string,    8] �����ڵ�                        StartPos 0, Length 8
} OVC_InBlock, * LPOVC_InBlock;
#define NAME_OVC_InBlock     "InBlock"

// ���                           
typedef struct _OVC_OutBlock
{
	char    symbol[8];    char    _symbol;    // [string,    8] �����ڵ�                        StartPos 0, Length 8
	char    ovsdate[8];    char    _ovsdate;    // [string,    8] ü������(����)                  StartPos 9, Length 8
	char    kordate[8];    char    _kordate;    // [string,    8] ü������(�ѱ�)                  StartPos 18, Length 8
	char    trdtm[6];    char    _trdtm;    // [string,    6] ü��ð�(����)                  StartPos 27, Length 6
	char    kortm[6];    char    _kortm;    // [string,    6] ü��ð�(�ѱ�)                  StartPos 34, Length 6
	char    curpr[15];    char    _curpr;    // [double, 15.9] ü�ᰡ��                        StartPos 41, Length 15
	char    ydiffpr[15];    char    _ydiffpr;    // [double, 15.9] ���ϴ��                        StartPos 57, Length 15
	char    ydiffSign[1];    char    _ydiffSign;    // [string,    1] ���ϴ���ȣ                    StartPos 73, Length 1
	char    open[15];    char    _open;    // [double, 15.9] �ð�                            StartPos 75, Length 15
	char    high[15];    char    _high;    // [double, 15.9] ��                            StartPos 91, Length 15
	char    low[15];    char    _low;    // [double, 15.9] ����                            StartPos 107, Length 15
	char    chgrate[6];    char    _chgrate;    // [float ,  6.2] �����                          StartPos 123, Length 6
	char    trdq[10];    char    _trdq;    // [long  ,   10] �Ǻ�ü�����                    StartPos 130, Length 10
	char    totq[15];    char    _totq;    // [string,   15] ����ü�����                    StartPos 141, Length 15
	char    cgubun[1];    char    _cgubun;    // [string,    1] ü�ᱸ��                        StartPos 157, Length 1
	char    mdvolume[15];    char    _mdvolume;    // [string,   15] �ŵ�����ü�����                StartPos 159, Length 15
	char    msvolume[15];    char    _msvolume;    // [string,   15] �ż�����ü�����                StartPos 175, Length 15
	char    ovsmkend[8];    char    _ovsmkend;    // [string,    8] �帶����                        StartPos 191, Length 8
} OVC_OutBlock, * LPOVC_OutBlock;
#define NAME_OVC_OutBlock     "OutBlock"


// �Է�                           
typedef struct _I5__InBlock
{
	char    shcode[6];   // [string,    6] �����ڵ�                        StartPos 0, Length 6
} I5__InBlock, * LPI5__InBlock;
#define NAME_I5__InBlock     "InBlock"

// ���                           
typedef struct _I5__OutBlock
{
	char    time[8];    char    _time;    // [string,    8] �ð�                            StartPos 0, Length 8
	char    price[8];    char    _price;    // [long  ,    8] ���簡                          StartPos 9, Length 8
	char    sign[1];    char    _sign;    // [string,    1] ���ϴ�񱸺�                    StartPos 18, Length 1
	char    change[8];    char    _change;    // [long  ,    8] ���ϴ��                        StartPos 20, Length 8
	char    volume[12];    char    _volume;    // [float ,   12] �����ŷ���                      StartPos 29, Length 12
	char    navdiff[9];    char    _navdiff;    // [float ,  9.2] NAV���                         StartPos 42, Length 9
	char    nav[9];    char    _nav;    // [float ,  9.2] NAV                             StartPos 52, Length 9
	char    navchange[9];    char    _navchange;    // [float ,  9.2] ���ϴ��                        StartPos 62, Length 9
	char    crate[9];    char    _crate;    // [float ,  9.2] ��������                        StartPos 72, Length 9
	char    grate[9];    char    _grate;    // [float ,  9.2] ����                            StartPos 82, Length 9
	char    jisu[8];    char    _jisu;    // [float ,  8.2] ����                            StartPos 92, Length 8
	char    jichange[8];    char    _jichange;    // [float ,  8.2] ���ϴ��                        StartPos 101, Length 8
	char    jirate[8];    char    _jirate;    // [float ,  8.2] ���ϴ����                      StartPos 110, Length 8
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 119, Length 6
} I5__OutBlock, * LPI5__OutBlock;
#define NAME_I5__OutBlock     "OutBlock"


// �Է�                           
typedef struct _H1__InBlock
{
	char    shcode[6];       // [string,    6] �����ڵ�                        StartPos 0, Length 6
} H1__InBlock, * LPH1__InBlock;
#define NAME_H1__InBlock     "InBlock"

// ���                           
typedef struct _H1__OutBlock
{
	char    hotime[6];    char    _hotime;    // [string,    6] ȣ���ð�                        StartPos 0, Length 6
	char    offerho1[7];    char    _offerho1;    // [long  ,    7] �ŵ�ȣ��1                       StartPos 7, Length 7
	char    bidho1[7];    char    _bidho1;    // [long  ,    7] �ż�ȣ��1                       StartPos 15, Length 7
	char    offerrem1[9];    char    _offerrem1;    // [long  ,    9] �ŵ�ȣ���ܷ�1                   StartPos 23, Length 9
	char    bidrem1[9];    char    _bidrem1;    // [long  ,    9] �ż�ȣ���ܷ�1                   StartPos 33, Length 9
	char    offerho2[7];    char    _offerho2;    // [long  ,    7] �ŵ�ȣ��2                       StartPos 43, Length 7
	char    bidho2[7];    char    _bidho2;    // [long  ,    7] �ż�ȣ��2                       StartPos 51, Length 7
	char    offerrem2[9];    char    _offerrem2;    // [long  ,    9] �ŵ�ȣ���ܷ�2                   StartPos 59, Length 9
	char    bidrem2[9];    char    _bidrem2;    // [long  ,    9] �ż�ȣ���ܷ�2                   StartPos 69, Length 9
	char    offerho3[7];    char    _offerho3;    // [long  ,    7] �ŵ�ȣ��3                       StartPos 79, Length 7
	char    bidho3[7];    char    _bidho3;    // [long  ,    7] �ż�ȣ��3                       StartPos 87, Length 7
	char    offerrem3[9];    char    _offerrem3;    // [long  ,    9] �ŵ�ȣ���ܷ�3                   StartPos 95, Length 9
	char    bidrem3[9];    char    _bidrem3;    // [long  ,    9] �ż�ȣ���ܷ�3                   StartPos 105, Length 9
	char    offerho4[7];    char    _offerho4;    // [long  ,    7] �ŵ�ȣ��4                       StartPos 115, Length 7
	char    bidho4[7];    char    _bidho4;    // [long  ,    7] �ż�ȣ��4                       StartPos 123, Length 7
	char    offerrem4[9];    char    _offerrem4;    // [long  ,    9] �ŵ�ȣ���ܷ�4                   StartPos 131, Length 9
	char    bidrem4[9];    char    _bidrem4;    // [long  ,    9] �ż�ȣ���ܷ�4                   StartPos 141, Length 9
	char    offerho5[7];    char    _offerho5;    // [long  ,    7] �ŵ�ȣ��5                       StartPos 151, Length 7
	char    bidho5[7];    char    _bidho5;    // [long  ,    7] �ż�ȣ��5                       StartPos 159, Length 7
	char    offerrem5[9];    char    _offerrem5;    // [long  ,    9] �ŵ�ȣ���ܷ�5                   StartPos 167, Length 9
	char    bidrem5[9];    char    _bidrem5;    // [long  ,    9] �ż�ȣ���ܷ�5                   StartPos 177, Length 9
	char    offerho6[7];    char    _offerho6;    // [long  ,    7] �ŵ�ȣ��6                       StartPos 187, Length 7
	char    bidho6[7];    char    _bidho6;    // [long  ,    7] �ż�ȣ��6                       StartPos 195, Length 7
	char    offerrem6[9];    char    _offerrem6;    // [long  ,    9] �ŵ�ȣ���ܷ�6                   StartPos 203, Length 9
	char    bidrem6[9];    char    _bidrem6;    // [long  ,    9] �ż�ȣ���ܷ�6                   StartPos 213, Length 9
	char    offerho7[7];    char    _offerho7;    // [long  ,    7] �ŵ�ȣ��7                       StartPos 223, Length 7
	char    bidho7[7];    char    _bidho7;    // [long  ,    7] �ż�ȣ��7                       StartPos 231, Length 7
	char    offerrem7[9];    char    _offerrem7;    // [long  ,    9] �ŵ�ȣ���ܷ�7                   StartPos 239, Length 9
	char    bidrem7[9];    char    _bidrem7;    // [long  ,    9] �ż�ȣ���ܷ�7                   StartPos 249, Length 9
	char    offerho8[7];    char    _offerho8;    // [long  ,    7] �ŵ�ȣ��8                       StartPos 259, Length 7
	char    bidho8[7];    char    _bidho8;    // [long  ,    7] �ż�ȣ��8                       StartPos 267, Length 7
	char    offerrem8[9];    char    _offerrem8;    // [long  ,    9] �ŵ�ȣ���ܷ�8                   StartPos 275, Length 9
	char    bidrem8[9];    char    _bidrem8;    // [long  ,    9] �ż�ȣ���ܷ�8                   StartPos 285, Length 9
	char    offerho9[7];    char    _offerho9;    // [long  ,    7] �ŵ�ȣ��9                       StartPos 295, Length 7
	char    bidho9[7];    char    _bidho9;    // [long  ,    7] �ż�ȣ��9                       StartPos 303, Length 7
	char    offerrem9[9];    char    _offerrem9;    // [long  ,    9] �ŵ�ȣ���ܷ�9                   StartPos 311, Length 9
	char    bidrem9[9];    char    _bidrem9;    // [long  ,    9] �ż�ȣ���ܷ�9                   StartPos 321, Length 9
	char    offerho10[7];    char    _offerho10;    // [long  ,    7] �ŵ�ȣ��10                      StartPos 331, Length 7
	char    bidho10[7];    char    _bidho10;    // [long  ,    7] �ż�ȣ��10                      StartPos 339, Length 7
	char    offerrem10[9];    char    _offerrem10;    // [long  ,    9] �ŵ�ȣ���ܷ�10                  StartPos 347, Length 9
	char    bidrem10[9];    char    _bidrem10;    // [long  ,    9] �ż�ȣ���ܷ�10                  StartPos 357, Length 9
	char    totofferrem[9];    char    _totofferrem;    // [long  ,    9] �Ѹŵ�ȣ���ܷ�                  StartPos 367, Length 9
	char    totbidrem[9];    char    _totbidrem;    // [long  ,    9] �Ѹż�ȣ���ܷ�                  StartPos 377, Length 9
	char    donsigubun[1];    char    _donsigubun;    // [string,    1] ����ȣ������                    StartPos 387, Length 1
	char    shcode[6];    char    _shcode;    // [string,    6] �����ڵ�                        StartPos 389, Length 6
	char    alloc_gubun[1];    char    _alloc_gubun;    // [string,    1] ������뱸��                    StartPos 396, Length 1
} H1__OutBlock, * LPH1__OutBlock;
#define NAME_H1__OutBlock     "OutBlock"



#define NAME_t2101     "t2101"

// �⺻�Է�                       
typedef struct _t2101InBlock
{
	char    focode[8];    char    _focode;    // [string,    8] �����ڵ�                        StartPos 0, Length 8
} t2101InBlock, * LPt2101InBlock;
#define NAME_t2101InBlock     "t2101InBlock"

// ���                           
typedef struct _t2101OutBlock
{
	char    hname[20];    char    _hname;    // [string,   20] �ѱ۸�                          StartPos 0, Length 20
	char    price[6];    char    _price;    // [float ,  6.2] ���簡                          StartPos 21, Length 6
	char    sign[1];    char    _sign;    // [string,    1] ���ϴ�񱸺�                    StartPos 28, Length 1
	char    change[6];    char    _change;    // [float ,  6.2] ���ϴ��                        StartPos 30, Length 6
	char    jnilclose[6];    char    _jnilclose;    // [float ,  6.2] ��������                        StartPos 37, Length 6
	char    diff[6];    char    _diff;    // [float ,  6.2] �����                          StartPos 44, Length 6
	char    volume[12];    char    _volume;    // [long  ,   12] �ŷ���                          StartPos 51, Length 12
	char    value[12];    char    _value;    // [long  ,   12] �ŷ����                        StartPos 64, Length 12
	char    mgjv[8];    char    _mgjv;    // [long  ,    8] �̰�����                        StartPos 77, Length 8
	char    mgjvdiff[8];    char    _mgjvdiff;    // [long  ,    8] �̰�������                      StartPos 86, Length 8
	char    open[6];    char    _open;    // [float ,  6.2] �ð�                            StartPos 95, Length 6
	char    high[6];    char    _high;    // [float ,  6.2] ��                            StartPos 102, Length 6
	char    low[6];    char    _low;    // [float ,  6.2] ����                            StartPos 109, Length 6
	char    uplmtprice[6];    char    _uplmtprice;    // [float ,  6.2] ���Ѱ�                          StartPos 116, Length 6
	char    dnlmtprice[6];    char    _dnlmtprice;    // [float ,  6.2] ���Ѱ�                          StartPos 123, Length 6
	char    high52w[6];    char    _high52w;    // [float ,  6.2] 52�ְ�                        StartPos 130, Length 6
	char    low52w[6];    char    _low52w;    // [float ,  6.2] 52������                        StartPos 137, Length 6
	char    basis[6];    char    _basis;    // [float ,  6.2] ���̽ý�                        StartPos 144, Length 6
	char    recprice[6];    char    _recprice;    // [float ,  6.2] ���ذ�                          StartPos 151, Length 6
	char    theoryprice[6];    char    _theoryprice;    // [float ,  6.2] �̷а�                          StartPos 158, Length 6
	char    glyl[6];    char    _glyl;    // [float ,  6.3] ������                          StartPos 165, Length 6
	char    cbhprice[6];    char    _cbhprice;    // [float ,  6.2] CB���Ѱ�                        StartPos 172, Length 6
	char    cblprice[6];    char    _cblprice;    // [float ,  6.2] CB���Ѱ�                        StartPos 179, Length 6
	char    lastmonth[8];    char    _lastmonth;    // [string,    8] ������                          StartPos 186, Length 8
	char    jandatecnt[8];    char    _jandatecnt;    // [long  ,    8] �ܿ���                          StartPos 195, Length 8
	char    pricejisu[6];    char    _pricejisu;    // [float ,  6.2] ��������                        StartPos 204, Length 6
	char    jisusign[1];    char    _jisusign;    // [string,    1] �����������ϴ�񱸺�            StartPos 211, Length 1
	char    jisuchange[6];    char    _jisuchange;    // [float ,  6.2] �����������ϴ��                StartPos 213, Length 6
	char    jisudiff[6];    char    _jisudiff;    // [float ,  6.2] �������������                  StartPos 220, Length 6
	char    kospijisu[6];    char    _kospijisu;    // [float ,  6.2] KOSPI200����                    StartPos 227, Length 6
	char    kospisign[1];    char    _kospisign;    // [string,    1] KOSPI200���ϴ�񱸺�            StartPos 234, Length 1
	char    kospichange[6];    char    _kospichange;    // [float ,  6.2] KOSPI200���ϴ��                StartPos 236, Length 6
	char    kospidiff[6];    char    _kospidiff;    // [float ,  6.2] KOSPI200�����                  StartPos 243, Length 6
	char    listhprice[6];    char    _listhprice;    // [float ,  6.2] �����ְ�                      StartPos 250, Length 6
	char    listlprice[6];    char    _listlprice;    // [float ,  6.2] ����������                      StartPos 257, Length 6
	char    delt[6];    char    _delt;    // [float ,  6.4] ��Ÿ                            StartPos 264, Length 6
	char    gama[6];    char    _gama;    // [float ,  6.4] ����                            StartPos 271, Length 6
	char    ceta[6];    char    _ceta;    // [float ,  6.4] ��Ÿ                            StartPos 278, Length 6
	char    vega[6];    char    _vega;    // [float ,  6.4] ����                            StartPos 285, Length 6
	char    rhox[6];    char    _rhox;    // [float ,  6.4] �ο�                            StartPos 292, Length 6
	char    gmprice[6];    char    _gmprice;    // [float ,  6.2] �ٿ������簡                    StartPos 299, Length 6
	char    gmsign[1];    char    _gmsign;    // [string,    1] �ٿ������ϴ�񱸺�              StartPos 306, Length 1
	char    gmchange[6];    char    _gmchange;    // [float ,  6.2] �ٿ������ϴ��                  StartPos 308, Length 6
	char    gmdiff[6];    char    _gmdiff;    // [float ,  6.2] �ٿ��������                    StartPos 315, Length 6
	char    theorypriceg[6];    char    _theorypriceg;    // [float ,  6.2] �̷а�                          StartPos 322, Length 6
	char    histimpv[6];    char    _histimpv;    // [float ,  6.2] ������������                    StartPos 329, Length 6
	char    impv[6];    char    _impv;    // [float ,  6.2] ���纯����                      StartPos 336, Length 6
	char    sbasis[6];    char    _sbasis;    // [float ,  6.2] ����BASIS                       StartPos 343, Length 6
	char    ibasis[6];    char    _ibasis;    // [float ,  6.2] �̷�BASIS                       StartPos 350, Length 6
	char    gmfutcode[8];    char    _gmfutcode;    // [string,    8] �ٿ��������ڵ�                  StartPos 357, Length 8
	char    actprice[6];    char    _actprice;    // [float ,  6.2] ��簡                          StartPos 366, Length 6
	char    greeks_time[6];    char    _greeks_time;    // [string,    6] �ŷ��ҹΰ������Žð�            StartPos 373, Length 6
	char    greeks_confirm[8];    char    _greeks_confirm;    // [string,    8] �ŷ��ҹΰ���Ȯ������            StartPos 380, Length 8
	char    danhochk[1];    char    _danhochk;    // [string,    1] ���ϰ�ȣ������                  StartPos 389, Length 1
	char    yeprice[6];    char    _yeprice;    // [float ,  6.2] ����ü�ᰡ                      StartPos 391, Length 6
	char    jnilysign[1];    char    _jnilysign;    // [string,    1] ����ü�ᰡ����������񱸺�      StartPos 398, Length 1
	char    jnilychange[6];    char    _jnilychange;    // [float ,  6.2] ����ü�ᰡ�����������          StartPos 400, Length 6
	char    jnilydrate[6];    char    _jnilydrate;    // [float ,  6.2] ����ü�ᰡ�������������        StartPos 407, Length 6
	char    alloc_gubun[1];    char    _alloc_gubun;    // [string,    1] ��б���(1:��а���2:�������0: StartPos 414, Length 1
	char    bjandatecnt[8];    char    _bjandatecnt;    // [long  ,    8] �ܿ���(������)                  StartPos 416, Length 8
	char    focode[8];    char    _focode;    // [string,    8] �����ڵ�                        StartPos 425, Length 8
	char    dy_gubun[1];    char    _dy_gubun;    // [string,    1] �ǽð��������ѿ���(0:���ƴ�1: StartPos 434, Length 1
	char    dy_uplmtprice[6];    char    _dy_uplmtprice;    // [float ,  6.2] �ǽð����Ѱ�                    StartPos 436, Length 6
	char    dy_dnlmtprice[6];    char    _dy_dnlmtprice;    // [float ,  6.2] �ǽð����Ѱ�                    StartPos 443, Length 6
	char    updnstep_gubun[1];    char    _updnstep_gubun;    // [string,    1] ����������Ȯ��(0:��Ȯ��1:Ȯ��2: StartPos 450, Length 1
	char    upstep[2];    char    _upstep;    // [string,    2] ��������ܰ�                    StartPos 452, Length 2
	char    dnstep[2];    char    _dnstep;    // [string,    2] ��������ܰ�                    StartPos 455, Length 2
	char    uplmtprice_3rd[6];    char    _uplmtprice_3rd;    // [float ,  6.2] 3�ܰ���Ѱ�                     StartPos 458, Length 6
	char    dnlmtprice_3rd[6];    char    _dnlmtprice_3rd;    // [float ,  6.2] 3�ܰ����Ѱ�                     StartPos 465, Length 6
} t2101OutBlock, * LPt2101OutBlock;
#define NAME_t2101OutBlock     "t2101OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼ� ���¿�Ź�����ű���ȸ ( ENCRYPT,SERVICE=CFOBQ10500,HEADTYPE=B,CREATOR=�����,CREDATE=2012/03/12 15:03:11 )


#define NAME_CFOBQ10500     "CFOBQ10500"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500InBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
} CFOBQ10500InBlock1, * LPCFOBQ10500InBlock1;
#define NAME_CFOBQ10500InBlock1     "CFOBQ10500InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
} CFOBQ10500OutBlock1, * LPCFOBQ10500OutBlock1;
#define NAME_CFOBQ10500OutBlock1     "CFOBQ10500OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOBQ10500OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] ���¸�                          StartPos 5, Length 40
	char    DpsamtTotamt[16];    // [long  ,   16] ��Ź���Ѿ�                      StartPos 45, Length 16 //
	char    Dps[16];    // [long  ,   16] ������                          StartPos 61, Length 16
	char    SubstAmt[16];    // [long  ,   16] ���ݾ�                        StartPos 77, Length 16
	char    FilupDpsamtTotamt[16];    // [long  ,   16] ��翹Ź���Ѿ�                  StartPos 93, Length 16
	char    FilupDps[16];    // [long  ,   16] ��翹����                      StartPos 109, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] �������ͱݾ�                    StartPos 125, Length 16 //
	char    WthdwAbleAmt[16];    // [long  ,   16] ���Ⱑ�ɱݾ�                    StartPos 141, Length 16
	char    PsnOutAbleCurAmt[16];    // [long  ,   16] ���Ⱑ�����ݾ�                  StartPos 157, Length 16
	char    PsnOutAbleSubstAmt[16];    // [long  ,   16] ���Ⱑ�ɴ��ݾ�                StartPos 173, Length 16
	char    Mgn[16];    // [long  ,   16] ���űݾ�                        StartPos 189, Length 16
	char    MnyMgn[16];    // [long  ,   16] �������űݾ�                    StartPos 205, Length 16
	char    OrdAbleAmt[16];    // [long  ,   16] �ֹ����ɱݾ�                    StartPos 221, Length 16 //
	char    MnyOrdAbleAmt[16];    // [long  ,   16] �����ֹ����ɱݾ�                StartPos 237, Length 16
	char    AddMgn[16];    // [long  ,   16] �߰����űݾ�                    StartPos 253, Length 16 //
	char    MnyAddMgn[16];    // [long  ,   16] �����߰����űݾ�                StartPos 269, Length 16
	char    AmtPrdayChckInAmt[16];    // [long  ,   16] �����ϼ�ǥ�Աݾ�                StartPos 285, Length 16
	char    FnoPrdaySubstSellAmt[16];    // [long  ,   16] �����ɼ����ϴ��ŵ��ݾ�        StartPos 301, Length 16
	char    FnoCrdaySubstSellAmt[16];    // [long  ,   16] �����ɼǱ��ϴ��ŵ��ݾ�        StartPos 317, Length 16
	char    FnoPrdayFdamt[16];    // [long  ,   16] �����ɼ����ϰ��Աݾ�            StartPos 333, Length 16
	char    FnoCrdayFdamt[16];    // [long  ,   16] �����ɼǱ��ϰ��Աݾ�            StartPos 349, Length 16
	char    FcurrSubstAmt[16];    // [long  ,   16] ��ȭ���ݾ�                    StartPos 365, Length 16
	char    FnoAcntAfmgnNm[20];    // [string,   20] �����ɼǰ��»������űݸ�        StartPos 381, Length 20
} CFOBQ10500OutBlock2, * LPCFOBQ10500OutBlock2;
#define NAME_CFOBQ10500OutBlock2     "CFOBQ10500OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CFOBQ10500OutBlock3
{
	char    PdGrpCodeNm[20];    // [string,   20] ��ǰ���ڵ��                    StartPos 0, Length 20
	char    NetRiskMgn[16];    // [long  ,   16] ���������űݾ�                  StartPos 20, Length 16
	char    PrcMgn[16];    // [long  ,   16] �������űݾ�                    StartPos 36, Length 16
	char    SprdMgn[16];    // [long  ,   16] �����������űݾ�                StartPos 52, Length 16
	char    PrcFlctMgn[16];    // [long  ,   16] ���ݺ������űݾ�                StartPos 68, Length 16
	char    MinMgn[16];    // [long  ,   16] �ּ����űݾ�                    StartPos 84, Length 16
	char    OrdMgn[16];    // [long  ,   16] �ֹ����űݾ�                    StartPos 100, Length 16
	char    OptNetBuyAmt[16];    // [long  ,   16] �ɼǼ��ż��ݾ�                  StartPos 116, Length 16
	char    CsgnMgn[16];    // [long  ,   16] ��Ź���űݾ�                    StartPos 132, Length 16 //
	char    MaintMgn[16];    // [long  ,   16] �������űݾ�                    StartPos 148, Length 16 //
	char    FutsBuyExecAmt[16];    // [long  ,   16] �����ż�ü��ݾ�                StartPos 164, Length 16
	char    FutsSellExecAmt[16];    // [long  ,   16] �����ŵ�ü��ݾ�                StartPos 180, Length 16
	char    OptBuyExecAmt[16];    // [long  ,   16] �ɼǸż�ü��ݾ�                StartPos 196, Length 16
	char    OptSellExecAmt[16];    // [long  ,   16] �ɼǸŵ�ü��ݾ�                StartPos 212, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] �������ͱݾ�                    StartPos 228, Length 16
	char    TotRiskCsgnMgn[16];    // [long  ,   16] ��������Ź���ű�                StartPos 244, Length 16
	char    UndCsgnMgn[16];    // [long  ,   16] �μ�����Ź���ű�                StartPos 260, Length 16
	char    MgnRdctAmt[16];    // [long  ,   16] ���űݰ���ݾ�                  StartPos 276, Length 16
} CFOBQ10500OutBlock3, * LPCFOBQ10500OutBlock3;
#define NAME_CFOBQ10500OutBlock3     "CFOBQ10500OutBlock3"



///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼǰ����꿹Ź�ݻ� ( SERVICE=CFOEQ11100,HEADTYPE=B,CREATOR=������,CREDATE=2012/03/16 14:04:41 )

#define NAME_CFOEQ11100     "CFOEQ11100"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100InBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
	char    BnsDt[8];    // [string,    8] �Ÿ���                          StartPos 33, Length 8
} CFOEQ11100InBlock1, * LPCFOEQ11100InBlock1;
#define NAME_CFOEQ11100InBlock1     "CFOEQ11100InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
	char    BnsDt[8];    // [string,    8] �Ÿ���                          StartPos 33, Length 8
} CFOEQ11100OutBlock1, * LPCFOEQ11100OutBlock1;
#define NAME_CFOEQ11100OutBlock1     "CFOEQ11100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ11100OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] ���¸�                          StartPos 5, Length 40
	char    OpnmkDpsamtTotamt[16];    // [long  ,   16] ����ÿ�Ź���Ѿ�                StartPos 45, Length 16
	char    OpnmkDps[16];    // [long  ,   16] ����ÿ�����                    StartPos 61, Length 16
	char    OpnmkMnyrclAmt[16];    // [long  ,   16] ��������ݹ̼���                StartPos 77, Length 16
	char    OpnmkSubstAmt[16];    // [long  ,   16] ����ô��ݾ�                  StartPos 93, Length 16
	char    TotAmt[16];    // [long  ,   16] �ѱݾ�                          StartPos 109, Length 16
	char    Dps[16];    // [long  ,   16] ������                          StartPos 125, Length 16
	char    MnyrclAmt[16];    // [long  ,   16] ���ݹ̼��ݾ�                    StartPos 141, Length 16
	char    SubstDsgnAmt[16];    // [long  ,   16] ��������ݾ�                    StartPos 157, Length 16
	char    CsgnMgn[16];    // [long  ,   16] ��Ź���űݾ�                    StartPos 173, Length 16
	char    MnyCsgnMgn[16];    // [long  ,   16] ������Ź���űݾ�                StartPos 189, Length 16
	char    MaintMgn[16];    // [long  ,   16] �������űݾ�                    StartPos 205, Length 16
	char    MnyMaintMgn[16];    // [long  ,   16] �����������űݾ�                StartPos 221, Length 16
	char    OutAbleAmt[16];    // [long  ,   16] ��ݰ����Ѿ�                    StartPos 237, Length 16
	char    MnyoutAbleAmt[16];    // [long  ,   16] ��ݰ��ɱݾ�                    StartPos 253, Length 16
	char    SubstOutAbleAmt[16];    // [long  ,   16] ��ݰ��ɴ��                    StartPos 269, Length 16
	char    OrdAbleAmt[16];    // [long  ,   16] �ֹ����ɱݾ�                    StartPos 285, Length 16
	char    MnyOrdAbleAmt[16];    // [long  ,   16] �����ֹ����ɱݾ�                StartPos 301, Length 16
	char    AddMgnOcrTpCode[1];    // [string,    1] �߰����űݱ���                  StartPos 317, Length 1
	char    AddMgn[16];    // [long  ,   16] �߰����űݾ�                    StartPos 318, Length 16
	char    MnyAddMgn[16];    // [long  ,   16] �����߰����űݾ�                StartPos 334, Length 16
	char    NtdayTotAmt[16];    // [long  ,   16] ���Ͽ�Ź�Ѿ�                    StartPos 350, Length 16
	char    NtdayDps[16];    // [long  ,   16] ���Ͽ�Ź����                    StartPos 366, Length 16
	char    NtdayMnyrclAmt[16];    // [long  ,   16] ���Ϲ̼���                      StartPos 382, Length 16
	char    NtdaySubstAmt[16];    // [long  ,   16] ���Ͽ�Ź���                    StartPos 398, Length 16
	char    NtdayCsgnMgn[16];    // [long  ,   16] ������Ź���ű�                  StartPos 414, Length 16
	char    NtdayMnyCsgnMgn[16];    // [long  ,   16] ������Ź���ű�����              StartPos 430, Length 16
	char    NtdayMaintMgn[16];    // [long  ,   16] �����������ű�                  StartPos 446, Length 16
	char    NtdayMnyMaintMgn[16];    // [long  ,   16] �����������ű�����              StartPos 462, Length 16
	char    NtdayOutAbleAmt[16];    // [long  ,   16] �������Ⱑ�ɱݾ�                StartPos 478, Length 16
	char    NtdayMnyoutAbleAmt[16];    // [long  ,   16] �������Ⱑ�ɱݾ�                StartPos 494, Length 16
	char    NtdaySubstOutAbleAmt[16];    // [long  ,   16] �������Ⱑ�ɴ��                StartPos 510, Length 16
	char    NtdayOrdAbleAmt[16];    // [long  ,   16] �����ֹ����ɱݾ�                StartPos 526, Length 16
	char    NtdayMnyOrdAbleAmt[16];    // [long  ,   16] �����ֹ���������                StartPos 542, Length 16
	char    NtdayAddMgnTp[1];    // [string,    1] �����߰����űݱ���              StartPos 558, Length 1
	char    NtdayAddMgn[16];    // [long  ,   16] �����߰����ű�                  StartPos 559, Length 16
	char    NtdayMnyAddMgn[16];    // [long  ,   16] �����߰����ű�����              StartPos 575, Length 16
	char    NtdaySettAmt[16];    // [long  ,   16] ���ϰ����ݾ�                    StartPos 591, Length 16
	char    EvalDpsamtTotamt[15];    // [long  ,   15] �򰡿�Ź���Ѿ�                  StartPos 607, Length 15
	char    MnyEvalDpstgAmt[15];    // [long  ,   15] �����򰡿�Ź�ݾ�                StartPos 622, Length 15
	char    DpsamtUtlfeeGivPrergAmt[16];    // [long  ,   16] ��Ź���̿�����޿����ݾ�        StartPos 637, Length 16
	char    TaxAmt[16];    // [long  ,   16] ����                            StartPos 653, Length 16
	char    CsgnMgnrat[7];    // [double,  7.2] ��Ź���ű� ����                 StartPos 669, Length 7
	char    CsgnMnyMgnrat[7];    // [double,  7.2] ��Ź���ű����ݺ���              StartPos 676, Length 7
	char    DpstgTotamtLackAmt[16];    // [long  ,   16] ��Ź�Ѿ׺����ݾ�(��Ź���űݱ��� StartPos 683, Length 16
	char    DpstgMnyLackAmt[16];    // [long  ,   16] ��Ź���ݺ����ݾ�(��Ź���űݱ��� StartPos 699, Length 16
	char    RealInAmt[16];    // [long  ,   16] ���Աݾ�                        StartPos 715, Length 16
	char    InAmt[16];    // [long  ,   16] �Աݾ�                          StartPos 731, Length 16
	char    OutAmt[16];    // [long  ,   16] ��ݾ�                          StartPos 747, Length 16
	char    FutsAdjstDfamt[16];    // [long  ,   16] ������������                    StartPos 763, Length 16
	char    FutsThdayDfamt[16];    // [long  ,   16] ������������                    StartPos 779, Length 16
	char    FutsUpdtDfamt[16];    // [long  ,   16] ������������                    StartPos 795, Length 16
	char    FutsLastSettDfamt[16];    // [long  ,   16] ����������������                StartPos 811, Length 16
	char    OptSettDfamt[16];    // [long  ,   16] �ɼǰ�������                    StartPos 827, Length 16
	char    OptBuyAmt[16];    // [long  ,   16] �ɼǸż��ݾ�                    StartPos 843, Length 16
	char    OptSellAmt[16];    // [long  ,   16] �ɼǸŵ��ݾ�                    StartPos 859, Length 16
	char    OptXrcDfamt[16];    // [long  ,   16] �ɼ��������                    StartPos 875, Length 16
	char    OptAsgnDfamt[16];    // [long  ,   16] �ɼǹ�������                    StartPos 891, Length 16
	char    RealGdsUndAmt[16];    // [long  ,   16] �ǹ��μ����ݾ�                  StartPos 907, Length 16
	char    RealGdsUndAsgnAmt[16];    // [long  ,   16] �ǹ��μ����������              StartPos 923, Length 16
	char    RealGdsUndXrcAmt[16];    // [long  ,   16] �ǹ��μ��������              StartPos 939, Length 16
	char    CmsnAmt[16];    // [long  ,   16] ������                          StartPos 955, Length 16
	char    FutsCmsn[16];    // [long  ,   16] ����������                      StartPos 971, Length 16
	char    OptCmsn[16];    // [long  ,   16] �ɼǼ�����                      StartPos 987, Length 16
	char    FutsCtrctQty[16];    // [long  ,   16] ������������                    StartPos 1003, Length 16
	char    FutsCtrctAmt[16];    // [long  ,   16] ���������ݾ�                    StartPos 1019, Length 16
	char    OptCtrctQty[16];    // [long  ,   16] �ɼǾ�������                    StartPos 1035, Length 16
	char    OptCtrctAmt[16];    // [long  ,   16] �ɼǾ����ݾ�                    StartPos 1051, Length 16
	char    FutsUnsttQty[16];    // [long  ,   16] �����̰�������                  StartPos 1067, Length 16
	char    FutsUnsttAmt[16];    // [long  ,   16] �����̰����ݾ�                  StartPos 1083, Length 16
	char    OptUnsttQty[16];    // [long  ,   16] �ɼǹ̰�������                  StartPos 1099, Length 16
	char    OptUnsttAmt[16];    // [long  ,   16] �ɼǹ̰����ݾ�                  StartPos 1115, Length 16
	char    FutsBuyUnsttQty[16];    // [long  ,   16] �����ż��̰�������              StartPos 1131, Length 16
	char    FutsBuyUnsttAmt[16];    // [long  ,   16] �����ż��̰����ݾ�              StartPos 1147, Length 16
	char    FutsSellUnsttQty[16];    // [long  ,   16] �����ŵ��̰�������              StartPos 1163, Length 16
	char    FutsSellUnsttAmt[16];    // [long  ,   16] �����ŵ��̰����ݾ�              StartPos 1179, Length 16
	char    OptBuyUnsttQty[16];    // [long  ,   16] �ɼǸż��̰�������              StartPos 1195, Length 16
	char    OptBuyUnsttAmt[16];    // [long  ,   16] �ɼǸż��̰����ݾ�              StartPos 1211, Length 16
	char    OptSellUnsttQty[16];    // [long  ,   16] �ɼǸŵ��̰�������              StartPos 1227, Length 16
	char    OptSellUnsttAmt[16];    // [long  ,   16] �ɼǸŵ��̰����ݾ�              StartPos 1243, Length 16
	char    FutsBuyctrQty[16];    // [long  ,   16] �����ż���������                StartPos 1259, Length 16
	char    FutsBuyctrAmt[16];    // [long  ,   16] �����ż������ݾ�                StartPos 1275, Length 16
	char    FutsSlctrQty[16];    // [long  ,   16] �����ŵ���������                StartPos 1291, Length 16
	char    FutsSlctrAmt[16];    // [long  ,   16] �����ŵ������ݾ�                StartPos 1307, Length 16
	char    OptBuyctrQty[16];    // [long  ,   16] �ɼǸż���������                StartPos 1323, Length 16
	char    OptBuyctrAmt[16];    // [long  ,   16] �ɼǸż������ݾ�                StartPos 1339, Length 16
	char    OptSlctrQty[16];    // [long  ,   16] �ɼǸŵ���������                StartPos 1355, Length 16
	char    OptSlctrAmt[16];    // [long  ,   16] �ɼǸŵ������ݾ�                StartPos 1371, Length 16
	char    FutsBnsplAmt[16];    // [long  ,   16] �����Ÿż��ͱݾ�                StartPos 1387, Length 16
	char    OptBnsplAmt[16];    // [long  ,   16] �ɼǸŸż��ͱݾ�                StartPos 1403, Length 16
	char    FutsEvalPnlAmt[16];    // [long  ,   16] �����򰡼��ͱݾ�                StartPos 1419, Length 16
	char    OptEvalPnlAmt[16];    // [long  ,   16] �ɼ��򰡼��ͱݾ�                StartPos 1435, Length 16
	char    FutsEvalAmt[16];    // [long  ,   16] �����򰡱ݾ�                    StartPos 1451, Length 16
	char    OptEvalAmt[16];    // [long  ,   16] �ɼ��򰡱ݾ�                    StartPos 1467, Length 16
	char    MktEndAfMnyInAmt[16];    // [long  ,   16] �������������Աݱݾ�            StartPos 1483, Length 16
	char    MktEndAfMnyOutAmt[16];    // [long  ,   16] ��������������ݱݾ�            StartPos 1499, Length 16
	char    MktEndAfSubstDsgnAmt[16];    // [long  ,   16] �������Ĵ�������ݾ�            StartPos 1515, Length 16
	char    MktEndAfSubstAbndAmt[16];    // [long  ,   16] �������Ĵ�������ݾ�            StartPos 1531, Length 16
} CFOEQ11100OutBlock2, * LPCFOEQ11100OutBlock2;
#define NAME_CFOEQ11100OutBlock2     "CFOEQ11100OutBlock2"


///////////////////////////////////////////////////////////////////////////////////////////////////
// ����/�ɼ� �ܰ���(�̵����) ( ATTR,TUXCODE=T0441,HEADTYPE=D )


#define NAME_t0441     "t0441"

// �⺻�Է�                       
typedef struct _t0441InBlock
{
    char    accno               [  11];    char    _accno               ;    // [string,   11] ���¹�ȣ                        StartPos 0, Length 11
    char    passwd              [   8];    char    _passwd              ;    // [string,    8] ��й�ȣ                        StartPos 12, Length 8
    char    cts_expcode         [   8];    char    _cts_expcode         ;    // [string,    8] CTS_�����ȣ                    StartPos 21, Length 8
    char    cts_medocd          [   1];    char    _cts_medocd          ;    // [string,    1] CTS_�Ÿű���                    StartPos 30, Length 1
} t0441InBlock, *LPt0441InBlock;
#define NAME_t0441InBlock     "t0441InBlock"

// ���                           
typedef struct _t0441OutBlock
{
    char    tdtsunik            [  18];    char    _tdtsunik            ;    // [long  ,   18] �Ÿż����հ�                    StartPos 0, Length 18
    char    cts_expcode         [   8];    char    _cts_expcode         ;    // [string,    8] CTS_�����ȣ                    StartPos 19, Length 8
    char    cts_medocd          [   1];    char    _cts_medocd          ;    // [string,    1] CTS_�Ÿű���                    StartPos 28, Length 1
    char    tappamt             [  18];    char    _tappamt             ;    // [long  ,   18] �򰡱ݾ�                        StartPos 30, Length 18
    char    tsunik              [  18];    char    _tsunik              ;    // [long  ,   18] �򰡼���                        StartPos 49, Length 18
} t0441OutBlock, *LPt0441OutBlock;
#define NAME_t0441OutBlock     "t0441OutBlock"

// ���1                          , occurs
typedef struct _t0441OutBlock1
{
    char    expcode             [   8];    char    _expcode             ;    // [string,    8] �����ȣ                        StartPos 0, Length 8
    char    medosu              [   4];    char    _medosu              ;    // [string,    4] ����                            StartPos 9, Length 4
    char    jqty                [  10];    char    _jqty                ;    // [long  ,   10] �ܰ����                        StartPos 14, Length 10
    char    cqty                [  10];    char    _cqty                ;    // [long  ,   10] û�갡�ɼ���                    StartPos 25, Length 10
    char    pamt                [  10];    char    _pamt                ;    // [float , 10.2] ��մܰ�                        StartPos 36, Length 10
    char    mamt                [  18];    char    _mamt                ;    // [long  ,   18] �Ѹ��Աݾ�                      StartPos 47, Length 18
    char    medocd              [   1];    char    _medocd              ;    // [string,    1] �Ÿű���                        StartPos 66, Length 1
    char    dtsunik             [  18];    char    _dtsunik             ;    // [long  ,   18] �Ÿż���                        StartPos 68, Length 18
    char    sysprocseq          [  10];    char    _sysprocseq          ;    // [long  ,   10] ó������                        StartPos 87, Length 10
    char    price               [   9];    char    _price               ;    // [float ,  9.2] ���簡                          StartPos 98, Length 9
    char    appamt              [  18];    char    _appamt              ;    // [long  ,   18] �򰡱ݾ�                        StartPos 108, Length 18
    char    dtsunik1            [  18];    char    _dtsunik1            ;    // [long  ,   18] �򰡼���                        StartPos 127, Length 18
    char    sunikrt             [  10];    char    _sunikrt             ;    // [float , 10.2] ������                          StartPos 146, Length 10
} t0441OutBlock1, *LPt0441OutBlock1;
#define NAME_t0441OutBlock1     "t0441OutBlock1"


///////////////////////////////////////////////////////////////////////////////////////////////////
// ����/�ɼ� ü��/��ü�� ( TUXCODE=T0434,HEADTYPE=D )

#define NAME_t0434     "t0434"

// �⺻�Է�                       
typedef struct _t0434InBlock
{
	char    accno[11];    // [string,   11] ���¹�ȣ                        StartPos 0, Length 11
	char    passwd[8];    // [string,    8] ��й�ȣ                        StartPos 11, Length 8
	char    expcode[8];    // [string,    8] �����ȣ                        StartPos 19, Length 8
	char    chegb[1];    // [string,    1] ü�ᱸ��                        StartPos 27, Length 1
	char    sortgb[1];    // [string,    1] ���ļ���                        StartPos 28, Length 1
	char    cts_ordno[7];    // [string,    7] CTS_�ֹ���ȣ                    StartPos 29, Length 7
} t0434InBlock, * LPt0434InBlock;
#define NAME_t0434InBlock     "t0434InBlock"

// ���                           
typedef struct _t0434OutBlock
{
	char    cts_ordno[7];    // [string,    7] CTS_�ֹ���ȣ                    StartPos 0, Length 7
} t0434OutBlock, * LPt0434OutBlock;
#define NAME_t0434OutBlock     "t0434OutBlock"

// ���1                          , occurs
typedef struct _t0434OutBlock1
{
	char    ordno[7];    // [long  ,    7] �ֹ���ȣ                        StartPos 0, Length 7
	char    orgordno[7];    // [long  ,    7] ���ֹ���ȣ                      StartPos 7, Length 7
	char    medosu[10];    // [string,   10] ����                            StartPos 14, Length 10
	char    ordgb[20];    // [string,   20] ����                            StartPos 24, Length 20
	char    qty[9];    // [long  ,    9] �ֹ�����                        StartPos 44, Length 9
	char    price[9];    // [float ,  9.2] �ֹ�����                        StartPos 53, Length 9
	char    cheqty[9];    // [long  ,    9] ü�����                        StartPos 62, Length 9
	char    cheprice[9];    // [float ,  9.2] ü�ᰡ��                        StartPos 71, Length 9
	char    ordrem[9];    // [long  ,    9] ��ü���ܷ�                      StartPos 80, Length 9
	char    status[10];    // [string,   10] ����                            StartPos 89, Length 10
	char    ordtime[8];    // [string,    8] �ֹ��ð�                        StartPos 99, Length 8
	char    ordermtd[10];    // [string,   10] �ֹ���ü                        StartPos 107, Length 10
	char    expcode[8];    // [string,    8] �����ȣ                        StartPos 117, Length 8
	char    rtcode[3];    // [string,    3] �����ڵ�                        StartPos 125, Length 3
	char    sysprocseq[10];    // [long  ,   10] ó������                        StartPos 128, Length 10
	char    hogatype[1];    // [string,    1] ȣ��Ÿ��                        StartPos 138, Length 1
} t0434OutBlock1, * LPt0434OutBlock1;
#define NAME_t0434OutBlock1     "t0434OutBlock1"


///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼ� �����ֹ�ü�᳻�� ��ȸ ( ENCRYPT,SERVICE=CFOAQ00600,HEADTYPE=B,CREATOR=�����,CREDATE=2012/03/12 16:35:20 )


#define NAME_CFOAQ00600     "CFOAQ00600"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600InBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    InptPwd[8];    // [string,    8] �Էº�й�ȣ                    StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] ��ȸ������                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] ��ȸ������                      StartPos 41, Length 8
	char    FnoClssCode[2];    // [string,    2] �����ɼǺз��ڵ�                StartPos 49, Length 2
	char    PrdgrpCode[2];    // [string,    2] ��ǰ���ڵ�                      StartPos 51, Length 2
	char    PrdtExecTpCode[1];    // [string,    1] ü�ᱸ��                        StartPos 53, Length 1
	char    StnlnSeqTp[1];    // [string,    1] ���ļ�������                    StartPos 54, Length 1
	char    CommdaCode[2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 55, Length 2
} CFOAQ00600InBlock1, * LPCFOAQ00600InBlock1;
#define NAME_CFOAQ00600InBlock1     "CFOAQ00600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    InptPwd[8];    // [string,    8] �Էº�й�ȣ                    StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] ��ȸ������                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] ��ȸ������                      StartPos 41, Length 8
	char    FnoClssCode[2];    // [string,    2] �����ɼǺз��ڵ�                StartPos 49, Length 2
	char    PrdgrpCode[2];    // [string,    2] ��ǰ���ڵ�                      StartPos 51, Length 2
	char    PrdtExecTpCode[1];    // [string,    1] ü�ᱸ��                        StartPos 53, Length 1
	char    StnlnSeqTp[1];    // [string,    1] ���ļ�������                    StartPos 54, Length 1
	char    CommdaCode[2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 55, Length 2
} CFOAQ00600OutBlock1, * LPCFOAQ00600OutBlock1;
#define NAME_CFOAQ00600OutBlock1     "CFOAQ00600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAQ00600OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] ���¸�                          StartPos 5, Length 40
	char    FutsOrdQty[16];    // [long  ,   16] �����ֹ�����                    StartPos 45, Length 16
	char    FutsExecQty[16];    // [long  ,   16] ����ü�����                    StartPos 61, Length 16
	char    OptOrdQty[16];    // [long  ,   16] �ɼ��ֹ�����                    StartPos 77, Length 16
	char    OptExecQty[16];    // [long  ,   16] �ɼ�ü�����                    StartPos 93, Length 16
} CFOAQ00600OutBlock2, * LPCFOAQ00600OutBlock2;
#define NAME_CFOAQ00600OutBlock2     "CFOAQ00600OutBlock2"

// Out1(*EMPTY*)                  , occurs
typedef struct _CFOAQ00600OutBlock3
{
	char    OrdDt[8];    // [string,    8] �ֹ���                          StartPos 0, Length 8
	char    OrdNo[10];    // [long  ,   10] �ֹ���ȣ                        StartPos 8, Length 10
	char    OrgOrdNo[10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 18, Length 10
	char    OrdTime[9];    // [string,    9] �ֹ��ð�                        StartPos 28, Length 9
	char    FnoIsuNo[12];    // [string,   12] �����ɼ������ȣ                StartPos 37, Length 12
	char    IsuNm[40];    // [string,   40] �����                          StartPos 49, Length 40
	char    BnsTpNm[10];    // [string,   10] �Ÿű���                        StartPos 89, Length 10
	char    MrcTpNm[10];    // [string,   10] ������ұ��и�                  StartPos 99, Length 10
	char    FnoOrdprcPtnCode[2];    // [string,    2] �����ɼ�ȣ�������ڵ�            StartPos 109, Length 2
	char    FnoOrdprcPtnNm[40];    // [string,   40] �����ɼ�ȣ��������              StartPos 111, Length 40
	char    OrdPrc[13];    // [double, 13.2] �ֹ���                          StartPos 151, Length 13
	char    OrdQty[16];    // [long  ,   16] �ֹ�����                        StartPos 164, Length 16
	char    OrdTpNm[10];    // [string,   10] �ֹ����и�                      StartPos 180, Length 10
	char    ExecTpNm[10];    // [string,   10] ü�ᱸ�и�                      StartPos 190, Length 10
	char    ExecPrc[13];    // [double, 13.2] ü�ᰡ                          StartPos 200, Length 13
	char    ExecQty[16];    // [long  ,   16] ü�����                        StartPos 213, Length 16
	char    CtrctTime[9];    // [string,    9] �����ð�                        StartPos 229, Length 9
	char    CtrctNo[10];    // [long  ,   10] ������ȣ                        StartPos 238, Length 10
	char    ExecNo[10];    // [long  ,   10] ü���ȣ                        StartPos 248, Length 10
	char    BnsplAmt[16];    // [long  ,   16] �Ÿż��ͱݾ�                    StartPos 258, Length 16
	char    UnercQty[16];    // [long  ,   16] ��ü�����                      StartPos 274, Length 16
	char    UserId[16];    // [string,   16] �����ID                        StartPos 290, Length 16
	char    CommdaCode[2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 306, Length 2
	char    CommdaCodeNm[40];    // [string,   40] ��Ÿ�ü�ڵ��                  StartPos 308, Length 40
} CFOAQ00600OutBlock3, * LPCFOAQ00600OutBlock3;
#define NAME_CFOAQ00600OutBlock3     "CFOAQ00600OutBlock3"


///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼ� �Ϻ� ���¼��ͳ��� ( SERVICE=CFOEQ82600,HEADTYPE=B,CREATOR=Ȳ�Լ�,CREDATE=2013/01/06 17:48:51 )


#define NAME_CFOEQ82600     "CFOEQ82600"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600InBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] ��ȸ������                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] ��ȸ������                      StartPos 41, Length 8
	char    QryTp[1];    // [string,    1] ��ȸ����                        StartPos 49, Length 1
	char    StnlnSeqTp[1];    // [string,    1] ���ļ�������                    StartPos 50, Length 1
	char    FnoBalEvalTpCode[1];    // [string,    1] �����ɼ��ܰ��򰡱����ڵ�        StartPos 51, Length 1
} CFOEQ82600InBlock1, * LPCFOEQ82600InBlock1;
#define NAME_CFOEQ82600InBlock1     "CFOEQ82600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] ��ȸ������                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] ��ȸ������                      StartPos 41, Length 8
	char    QryTp[1];    // [string,    1] ��ȸ����                        StartPos 49, Length 1
	char    StnlnSeqTp[1];    // [string,    1] ���ļ�������                    StartPos 50, Length 1
	char    FnoBalEvalTpCode[1];    // [string,    1] �����ɼ��ܰ��򰡱����ڵ�        StartPos 51, Length 1
} CFOEQ82600OutBlock1, * LPCFOEQ82600OutBlock1;
#define NAME_CFOEQ82600OutBlock1     "CFOEQ82600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ82600OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
	char    FutsAdjstDfamt[16];    // [long  ,   16] ������������                    StartPos 5, Length 16
	char    OptBnsplAmt[16];    // [long  ,   16] �ɼǸŸż��ͱݾ�                StartPos 21, Length 16
	char    FnoCmsnAmt[16];    // [long  ,   16] �����ɼǼ�����                  StartPos 37, Length 16
	char    PnlSumAmt[16];    // [long  ,   16] �����հ�ݾ�                    StartPos 53, Length 16
	char    MnyinSumAmt[16];    // [long  ,   16] �Ա��հ�ݾ�                    StartPos 69, Length 16
	char    MnyoutSumAmt[16];    // [long  ,   16] ����հ�ݾ�                    StartPos 85, Length 16
	char    AcntNm[40];    // [string,   40] ���¸�                          StartPos 101, Length 40
} CFOEQ82600OutBlock2, * LPCFOEQ82600OutBlock2;
#define NAME_CFOEQ82600OutBlock2     "CFOEQ82600OutBlock2"

// OutList(*EMPTY*)               , occurs
typedef struct _CFOEQ82600OutBlock3
{
	char    QryDt[8];    // [string,    8] ��ȸ��                          StartPos 0, Length 8
	char    DpstgTotamt[16];    // [long  ,   16] ��Ź�Ѿ�                        StartPos 8, Length 16
	char    DpstgMny[16];    // [long  ,   16] ��Ź����                        StartPos 24, Length 16
	char    FnoMgn[16];    // [long  ,   16] �����ɼ����űݾ�                StartPos 40, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] �������ͱݾ�                    StartPos 56, Length 16
	char    OptBsnPnlAmt[16];    // [long  ,   16] �ɼǸŸż��ͱݾ�                StartPos 72, Length 16
	char    OptEvalPnlAmt[16];    // [long  ,   16] �ɼ��򰡼��ͱݾ�                StartPos 88, Length 16
	char    CmsnAmt[16];    // [long  ,   16] ������                          StartPos 104, Length 16
	char    SumAmt1[16];    // [long  ,   16] �հ�ݾ�1                       StartPos 120, Length 16
	char    SumAmt2[16];    // [long  ,   16] �հ�ݾ�                        StartPos 136, Length 16
	char    PnlSumAmt[16];    // [long  ,   16] �����հ�ݾ�                    StartPos 152, Length 16
	char    FutsBuyAmt[16];    // [long  ,   16] �����ż��ݾ�                    StartPos 168, Length 16
	char    FutsSellAmt[16];    // [long  ,   16] �����ŵ��ݾ�                    StartPos 184, Length 16
	char    OptBuyAmt[16];    // [long  ,   16] �ɼǸż��ݾ�                    StartPos 200, Length 16
	char    OptSellAmt[16];    // [long  ,   16] �ɼǸŵ��ݾ�                    StartPos 216, Length 16
	char    InAmt[16];    // [long  ,   16] �Աݾ�                          StartPos 232, Length 16
	char    OutAmt[16];    // [long  ,   16] ��ݾ�                          StartPos 248, Length 16
	char    EvalAmt[16];    // [long  ,   16] �򰡱ݾ�                        StartPos 264, Length 16
	char    AddupEvalAmt[16];    // [long  ,   16] �ջ��򰡱ݾ�                    StartPos 280, Length 16
	char    Amt2[16];    // [long  ,   16] �ݾ�2                           StartPos 296, Length 16
} CFOEQ82600OutBlock3, * LPCFOEQ82600OutBlock3;
#define NAME_CFOEQ82600OutBlock3     "CFOEQ82600OutBlock3"


#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

