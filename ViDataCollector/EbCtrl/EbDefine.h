#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외선물 종목마스터 조회 ( ATTR,BLOCK,HEADTYPE=A )
#pragma pack( push, 1 )

// 해외 선물 종목 마스터 조회 
#define NAME_o3101     "o3101"
// 해외 선물 분봉 차트 조회
#define NAME_o3103     "o3103"
// 국내 주식 목록 가져오기 - 코스피, 코스닥 별도
#define NAME_t9945     "t9945"
#define NAME_t8436     "t8436"
// 국내 주식 분차트 데이터 가져오기
#define NAME_t8412     "t8412"
// 국내 주식 일/주/월 데이터 가져오기
#define NAME_t8413     "t8413"
// 실시간 주식 시세 등록
#define NAME_S3_     "S3_"
#define NAME_I5_     "I5_"
// 국내 선물 실시간 시세 등록
#define NAME_FC0     "FC0" // 시세
#define NAME_FH0     "FH0" // 호가
// 국내 옵션 실시간 시세 등록
#define NAME_OC0     "OC0" // 시세 
#define NAME_OH0     "OH0" // 호가
// 해외 선물 실시간 시세 등록
#define NAME_OVC     "OVC" // 시세
#define NAME_H1_     "H1_" // 호가


///////////////////////////////////////////////////////////////////////////////////////////////////
// 상품선물 마스터 조회 ( BLOCK,HEADTYPE=A )


#define NAME_t8426     "t8426"

// 기본입력                       
typedef struct _t8426InBlock
{
	char    dummy[1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t8426InBlock, * LPt8426InBlock;
#define NAME_t8426InBlock     "t8426InBlock"

// 주식종목마스터                 , occurs
typedef struct _t8426OutBlock
{
	char    hname[20];    // [string,   20] 종목명                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] 단축코드                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 28, Length 12
} t8426OutBlock, * LPt8426OutBlock;
#define NAME_t8426OutBlock     "t8426OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
// 파생종목마스터조회API용 ( BLOCK,HEADTYPE=A )


#define NAME_t8435     "t8435"

// 기본입력                       
typedef struct _t8435InBlock
{
	char    gubun[2];    // [string,    2] 구분(MF/MO)                     StartPos 0, Length 2
} t8435InBlock, * LPt8435InBlock;
#define NAME_t8435InBlock     "t8435InBlock"

// 파생종목마스터                 , occurs
typedef struct _t8435OutBlock
{
	char    hname[20];    // [string,   20] 종목명                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] 단축코드                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 28, Length 12
	char    uplmtprice[6];    // [float ,  6.2] 상한가                          StartPos 40, Length 6
	char    dnlmtprice[6];    // [float ,  6.2] 하한가                          StartPos 46, Length 6
	char    jnilclose[6];    // [float ,  6.2] 전일종가                        StartPos 52, Length 6
	char    jnilhigh[6];    // [float ,  6.2] 전일고가                        StartPos 58, Length 6
	char    jnillow[6];    // [float ,  6.2] 전일저가                        StartPos 64, Length 6
	char    recprice[6];    // [float ,  6.2] 기준가                          StartPos 70, Length 6
} t8435OutBlock, * LPt8435OutBlock;
#define NAME_t8435OutBlock     "t8435OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수옵션마스터조회 API용 ( BLOCK,HEADTYPE=A )


#define NAME_t9944     "t9944"

// 기본입력                       
typedef struct _t9944InBlock
{
	char    dummy[1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t9944InBlock, * LPt9944InBlock;
#define NAME_t9944InBlock     "t9944InBlock"

// 주식종목마스터                 , occurs
typedef struct _t9944OutBlock
{
	char    hname[20];    // [string,   20] 종목명                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] 단축코드                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 28, Length 12
} t9944OutBlock, * LPt9944OutBlock;
#define NAME_t9944OutBlock     "t9944OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수선물마스터조회 API용 ( BLOCK,HEADTYPE=A )


#define NAME_t9943     "t9943"

// 기본입력                       
typedef struct _t9943InBlock
{
	char    gubun[1];    // [string,    1] 구분                            StartPos 0, Length 1
} t9943InBlock, * LPt9943InBlock;
#define NAME_t9943InBlock     "t9943InBlock"

// 주식종목마스터                 , occurs
typedef struct _t9943OutBlock
{
	char    hname[20];    // [string,   20] 종목명                          StartPos 0, Length 20
	char    shcode[8];    // [string,    8] 단축코드                        StartPos 20, Length 8
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 28, Length 12
} t9943OutBlock, * LPt9943OutBlock;
#define NAME_t9943OutBlock     "t9943OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////


// 기본입력                       
typedef struct _o3101InBlock
{
	char    gubun[1];    char    _gubun;    // [string,    1] 입력구분(예비)                  StartPos 0, Length 1
} o3101InBlock, * LPo3101InBlock;
#define NAME_o3101InBlock     "o3101InBlock"

// 출력-마스터                    , occurs
typedef struct _o3101OutBlock
{
	char    Symbol[8];    char    _Symbol;    // [string,    8] 종목코드                        StartPos 0, Length 8
	char    SymbolNm[50];    char    _SymbolNm;    // [string,   50] 종목명                          StartPos 9, Length 50
	char    ApplDate[8];    char    _ApplDate;    // [string,    8] 종목배치수신일(한국일자)        StartPos 60, Length 8
	char    BscGdsCd[10];    char    _BscGdsCd;    // [string,   10] 기초상품코드                    StartPos 69, Length 10
	char    BscGdsNm[40];    char    _BscGdsNm;    // [string,   40] 기초상품명                      StartPos 80, Length 40
	char    ExchCd[10];    char    _ExchCd;    // [string,   10] 거래소코드                      StartPos 121, Length 10
	char    ExchNm[40];    char    _ExchNm;    // [string,   40] 거래소명                        StartPos 132, Length 40
	char    CrncyCd[3];    char    _CrncyCd;    // [string,    3] 기준통화코드                    StartPos 173, Length 3
	char    NotaCd[3];    char    _NotaCd;    // [string,    3] 진법구분코드                    StartPos 177, Length 3
	char    UntPrc[15];    char    _UntPrc;    // [double, 15.9] 호가단위가격                    StartPos 181, Length 15
	char    MnChgAmt[15];    char    _MnChgAmt;    // [double, 15.9] 최소가격변동금액                StartPos 197, Length 15
	char    RgltFctr[15];    char    _RgltFctr;    // [double,15.10] 가격조정계수                    StartPos 213, Length 15
	char    CtrtPrAmt[15];    char    _CtrtPrAmt;    // [double, 15.2] 계약당금액                      StartPos 229, Length 15
	char    GdsCd[3];    char    _GdsCd;    // [string,    3] 상품구분코드                    StartPos 245, Length 3
	char    LstngYr[4];    char    _LstngYr;    // [string,    4] 월물(년)                        StartPos 249, Length 4
	char    LstngM[1];    char    _LstngM;    // [string,    1] 월물(월)                        StartPos 254, Length 1
	char    EcPrc[15];    char    _EcPrc;    // [double, 15.9] 정산가격                        StartPos 256, Length 15
	char    DlStrtTm[6];    char    _DlStrtTm;    // [string,    6] 거래시작시간                    StartPos 272, Length 6
	char    DlEndTm[6];    char    _DlEndTm;    // [string,    6] 거래종료시간                    StartPos 279, Length 6
	char    DlPsblCd[1];    char    _DlPsblCd;    // [string,    1] 거래가능구분코드                StartPos 286, Length 1
	char    MgnCltCd[1];    char    _MgnCltCd;    // [string,    1] 증거금징수구분코드              StartPos 288, Length 1
	char    OpngMgn[15];    char    _OpngMgn;    // [double, 15.2] 개시증거금                      StartPos 290, Length 15
	char    MntncMgn[15];    char    _MntncMgn;    // [double, 15.2] 유지증거금                      StartPos 306, Length 15
	char    OpngMgnR[7];    char    _OpngMgnR;    // [double,  7.3] 개시증거금율                    StartPos 322, Length 7
	char    MntncMgnR[7];    char    _MntncMgnR;    // [double,  7.3] 유지증거금율                    StartPos 330, Length 7
	char    DotGb[2];    char    _DotGb;    // [long  ,    2] 유효소수점자리수                StartPos 338, Length 2
} o3101OutBlock, * LPo3101OutBlock;
#define NAME_o3101OutBlock     "o3101OutBlock"


// 기본입력                       
typedef struct _o3103InBlock
{
	char    shcode[8];    char    _shcode;    // [string,    8] 단축코드                        StartPos 0, Length 8
	char    ncnt[4];    char    _ncnt;    // [long  ,    4] N분주기                         StartPos 9, Length 4
	char    readcnt[4];    char    _readcnt;    // [long  ,    4] 조회건수                        StartPos 14, Length 4
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 19, Length 8
	char    cts_time[6];    char    _cts_time;    // [string,    6] 연속시간                        StartPos 28, Length 6
} o3103InBlock, * LPo3103InBlock;
#define NAME_o3103InBlock     "o3103InBlock"

// 출력                           
typedef struct _o3103OutBlock
{
	char    shcode[8];    char    _shcode;    // [string,    8] 단축코드                        StartPos 0, Length 8
	char    timediff[4];    char    _timediff;    // [long  ,    4] 시차                            StartPos 9, Length 4
	char    readcnt[4];    char    _readcnt;    // [long  ,    4] 조회건수                        StartPos 14, Length 4
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 19, Length 8
	char    cts_time[6];    char    _cts_time;    // [string,    6] 연속시간                        StartPos 28, Length 6
} o3103OutBlock, * LPo3103OutBlock;
#define NAME_o3103OutBlock     "o3103OutBlock"

// 출력1                          , occurs
typedef struct _o3103OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] 날짜                            StartPos 0, Length 8
	char    time[6];    char    _time;    // [string,    6] 현지시간                        StartPos 9, Length 6
	char    open[15];    char    _open;    // [double, 15.9] 시가                            StartPos 16, Length 15
	char    high[15];    char    _high;    // [double, 15.9] 고가                            StartPos 32, Length 15
	char    low[15];    char    _low;    // [double, 15.9] 저가                            StartPos 48, Length 15
	char    close[15];    char    _close;    // [double, 15.9] 종가                            StartPos 64, Length 15
	char    volume[12];    char    _volume;    // [long  ,   12] 거래량                          StartPos 80, Length 12
} o3103OutBlock1, * LPo3103OutBlock1;
#define NAME_o3103OutBlock1     "o3103OutBlock1"

// 기본입력                       
typedef struct _t9945InBlock
{
	char    gubun[1];    // [string,    1] 구분(KSP:1KSD:2)                StartPos 0, Length 1
} t9945InBlock, * LPt9945InBlock;
#define NAME_t9945InBlock     "t9945InBlock"

// 주식종목마스터                 , occurs
typedef struct _t9945OutBlock
{
	char    hname[40];    // [string,   40] 종목명                          StartPos 0, Length 40
	char    shcode[6];    // [string,    6] 단축코드                        StartPos 40, Length 6
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 46, Length 12
	char    etfchk[1];    // [string,    1] ETF구분                         StartPos 58, Length 1
	char    filler[5];    // [string,    5] filler                          StartPos 59, Length 5
} t9945OutBlock, * LPt9945OutBlock;
#define NAME_t9945OutBlock     "t9945OutBlock"

// 기본입력                       
typedef struct _t8436InBlock
{
	char    gubun[1];    // [string,    1] 구분(0:전체1:코스피2:코스닥)    StartPos 0, Length 1
} t8436InBlock, * LPt8436InBlock;
#define NAME_t8436InBlock     "t8436InBlock"

// 출력1                          , occurs
typedef struct _t8436OutBlock
{
	char    hname[20];    // [string,   20] 종목명                          StartPos 0, Length 20
	char    shcode[6];    // [string,    6] 단축코드                        StartPos 20, Length 6
	char    expcode[12];    // [string,   12] 확장코드                        StartPos 26, Length 12
	char    etfgubun[1];    // [string,    1] ETF구분(1:ETF2:ETN)             StartPos 38, Length 1
	char    uplmtprice[8];    // [long  ,    8] 상한가                          StartPos 39, Length 8
	char    dnlmtprice[8];    // [long  ,    8] 하한가                          StartPos 47, Length 8
	char    jnilclose[8];    // [long  ,    8] 전일가                          StartPos 55, Length 8
	char    memedan[5];    // [string,    5] 주문수량단위                    StartPos 63, Length 5
	char    recprice[8];    // [long  ,    8] 기준가                          StartPos 68, Length 8
	char    gubun[1];    // [string,    1] 구분(1:코스피2:코스닥)          StartPos 76, Length 1
	char    bu12gubun[2];    // [string,    2] 증권그룹                        StartPos 77, Length 2
	char    spac_gubun[1];    // [string,    1] 기업인수목적회사여부(Y/N)       StartPos 79, Length 1
	char    filler[32];    // [string,   32] filler(미사용)                  StartPos 80, Length 32
} t8436OutBlock, * LPt8436OutBlock;
#define NAME_t8436OutBlock     "t8436OutBlock"


// 기본입력                       
typedef struct _t8412InBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 0, Length 6
	char    ncnt[4];    char    _ncnt;    // [long  ,    4] 단위(n분)                       StartPos 7, Length 4
	char    qrycnt[4];    char    _qrycnt;    // [long  ,    4] 요청건수(최대-압축:2000비압축:5 StartPos 12, Length 4
	char    nday[1];    char    _nday;    // [string,    1] 조회영업일수(0:미사용1>=사용)   StartPos 17, Length 1
	char    sdate[8];    char    _sdate;    // [string,    8] 시작일자                        StartPos 19, Length 8
	char    stime[6];    char    _stime;    // [string,    6] 시작시간(현재미사용)            StartPos 28, Length 6
	char    edate[8];    char    _edate;    // [string,    8] 종료일자                        StartPos 35, Length 8
	char    etime[6];    char    _etime;    // [string,    6] 종료시간(현재미사용)            StartPos 44, Length 6
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 51, Length 8
	char    cts_time[10];    char    _cts_time;    // [string,   10] 연속시간                        StartPos 60, Length 10
	char    comp_yn[1];    char    _comp_yn;    // [string,    1] 압축여부(Y:압축N:비압축)        StartPos 71, Length 1
} t8412InBlock, * LPt8412InBlock;
#define NAME_t8412InBlock     "t8412InBlock"

// 출력                           
typedef struct _t8412OutBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 0, Length 6
	char    jisiga[8];    char    _jisiga;    // [long  ,    8] 전일시가                        StartPos 7, Length 8
	char    jihigh[8];    char    _jihigh;    // [long  ,    8] 전일고가                        StartPos 16, Length 8
	char    jilow[8];    char    _jilow;    // [long  ,    8] 전일저가                        StartPos 25, Length 8
	char    jiclose[8];    char    _jiclose;    // [long  ,    8] 전일종가                        StartPos 34, Length 8
	char    jivolume[12];    char    _jivolume;    // [long  ,   12] 전일거래량                      StartPos 43, Length 12
	char    disiga[8];    char    _disiga;    // [long  ,    8] 당일시가                        StartPos 56, Length 8
	char    dihigh[8];    char    _dihigh;    // [long  ,    8] 당일고가                        StartPos 65, Length 8
	char    dilow[8];    char    _dilow;    // [long  ,    8] 당일저가                        StartPos 74, Length 8
	char    diclose[8];    char    _diclose;    // [long  ,    8] 당일종가                        StartPos 83, Length 8
	char    highend[8];    char    _highend;    // [long  ,    8] 상한가                          StartPos 92, Length 8
	char    lowend[8];    char    _lowend;    // [long  ,    8] 하한가                          StartPos 101, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 110, Length 8
	char    cts_time[10];    char    _cts_time;    // [string,   10] 연속시간                        StartPos 119, Length 10
	char    s_time[6];    char    _s_time;    // [string,    6] 장시작시간(HHMMSS)              StartPos 130, Length 6
	char    e_time[6];    char    _e_time;    // [string,    6] 장종료시간(HHMMSS)              StartPos 137, Length 6
	char    dshmin[2];    char    _dshmin;    // [string,    2] 동시호가처리시간(MM:분)         StartPos 144, Length 2
	char    rec_count[7];    char    _rec_count;    // [long  ,    7] 레코드카운트                    StartPos 147, Length 7
} t8412OutBlock, * LPt8412OutBlock;
#define NAME_t8412OutBlock     "t8412OutBlock"

// 출력1                          , occurs
typedef struct _t8412OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] 날짜                            StartPos 0, Length 8
	char    time[10];    char    _time;    // [string,   10] 시간                            StartPos 9, Length 10
	char    open[8];    char    _open;    // [long  ,    8] 시가                            StartPos 20, Length 8
	char    high[8];    char    _high;    // [long  ,    8] 고가                            StartPos 29, Length 8
	char    low[8];    char    _low;    // [long  ,    8] 저가                            StartPos 38, Length 8
	char    close[8];    char    _close;    // [long  ,    8] 종가                            StartPos 47, Length 8
	char    jdiff_vol[12];    char    _jdiff_vol;    // [long  ,   12] 거래량                          StartPos 56, Length 12
	char    value[12];    char    _value;    // [long  ,   12] 거래대금                        StartPos 69, Length 12
	char    jongchk[13];    char    _jongchk;    // [long  ,   13] 수정구분                        StartPos 82, Length 13
	char    rate[6];    char    _rate;    // [double,  6.2] 수정비율                        StartPos 96, Length 6
	char    sign[1];    char    _sign;    // [string,    1] 종가등락구분(1:상한2:상승3:보합 StartPos 103, Length 1
} t8412OutBlock1, * LPt8412OutBlock1;
#define NAME_t8412OutBlock1     "t8412OutBlock1"

// 기본입력                       
typedef struct _t8413InBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 0, Length 6
	char    gubun[1];    char    _gubun;    // [string,    1] 주기구분(2:일3:주4:월)          StartPos 7, Length 1
	char    qrycnt[4];    char    _qrycnt;    // [long  ,    4] 요청건수(최대-압축:2000비압축:5 StartPos 9, Length 4
	char    sdate[8];    char    _sdate;    // [string,    8] 시작일자                        StartPos 14, Length 8
	char    edate[8];    char    _edate;    // [string,    8] 종료일자                        StartPos 23, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 32, Length 8
	char    comp_yn[1];    char    _comp_yn;    // [string,    1] 압축여부(Y:압축N:비압축)        StartPos 41, Length 1
} t8413InBlock, * LPt8413InBlock;
#define NAME_t8413InBlock     "t8413InBlock"

// 출력                           
typedef struct _t8413OutBlock
{
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 0, Length 6
	char    jisiga[8];    char    _jisiga;    // [long  ,    8] 전일시가                        StartPos 7, Length 8
	char    jihigh[8];    char    _jihigh;    // [long  ,    8] 전일고가                        StartPos 16, Length 8
	char    jilow[8];    char    _jilow;    // [long  ,    8] 전일저가                        StartPos 25, Length 8
	char    jiclose[8];    char    _jiclose;    // [long  ,    8] 전일종가                        StartPos 34, Length 8
	char    jivolume[12];    char    _jivolume;    // [long  ,   12] 전일거래량                      StartPos 43, Length 12
	char    disiga[8];    char    _disiga;    // [long  ,    8] 당일시가                        StartPos 56, Length 8
	char    dihigh[8];    char    _dihigh;    // [long  ,    8] 당일고가                        StartPos 65, Length 8
	char    dilow[8];    char    _dilow;    // [long  ,    8] 당일저가                        StartPos 74, Length 8
	char    diclose[8];    char    _diclose;    // [long  ,    8] 당일종가                        StartPos 83, Length 8
	char    highend[8];    char    _highend;    // [long  ,    8] 상한가                          StartPos 92, Length 8
	char    lowend[8];    char    _lowend;    // [long  ,    8] 하한가                          StartPos 101, Length 8
	char    cts_date[8];    char    _cts_date;    // [string,    8] 연속일자                        StartPos 110, Length 8
	char    s_time[6];    char    _s_time;    // [string,    6] 장시작시간(HHMMSS)              StartPos 119, Length 6
	char    e_time[6];    char    _e_time;    // [string,    6] 장종료시간(HHMMSS)              StartPos 126, Length 6
	char    dshmin[2];    char    _dshmin;    // [string,    2] 동시호가처리시간(MM:분)         StartPos 133, Length 2
	char    rec_count[7];    char    _rec_count;    // [long  ,    7] 레코드카운트                    StartPos 136, Length 7
} t8413OutBlock, * LPt8413OutBlock;
#define NAME_t8413OutBlock     "t8413OutBlock"

// 출력1                          , occurs
typedef struct _t8413OutBlock1
{
	char    date[8];    char    _date;    // [string,    8] 날짜                            StartPos 0, Length 8
	char    open[8];    char    _open;    // [long  ,    8] 시가                            StartPos 9, Length 8
	char    high[8];    char    _high;    // [long  ,    8] 고가                            StartPos 18, Length 8
	char    low[8];    char    _low;    // [long  ,    8] 저가                            StartPos 27, Length 8
	char    close[8];    char    _close;    // [long  ,    8] 종가                            StartPos 36, Length 8
	char    jdiff_vol[12];    char    _jdiff_vol;    // [long  ,   12] 거래량                          StartPos 45, Length 12
	char    value[12];    char    _value;    // [long  ,   12] 거래대금                        StartPos 58, Length 12
	char    jongchk[13];    char    _jongchk;    // [long  ,   13] 수정구분                        StartPos 71, Length 13
	char    rate[6];    char    _rate;    // [double,  6.2] 수정비율                        StartPos 85, Length 6
	char    pricechk[13];    char    _pricechk;    // [long  ,   13] 수정주가반영항목                StartPos 92, Length 13
	char    ratevalue[12];    char    _ratevalue;    // [long  ,   12] 수정비율반영거래대금            StartPos 106, Length 12
	char    sign[1];    char    _sign;    // [string,    1] 종가등락구분(1:상한2:상승3:보합 StartPos 119, Length 1
} t8413OutBlock1, * LPt8413OutBlock1;
#define NAME_t8413OutBlock1     "t8413OutBlock1"


// 입력                           
typedef struct _S3__InBlock
{
	char    shcode[6];    // [string,    6] 단축코드                        StartPos 0, Length 6
} S3__InBlock, * LPS3__InBlock;
#define NAME_S3__InBlock     "InBlock"

// 출력                           
typedef struct _S3__OutBlock
{
	char    chetime[6];    char    _chetime;    // [string,    6] 체결시간                        StartPos 0, Length 6
	char    sign[1];    char    _sign;    // [string,    1] 전일대비구분                    StartPos 7, Length 1
	char    change[8];    char    _change;    // [long  ,    8] 전일대비                        StartPos 9, Length 8
	char    drate[6];    char    _drate;    // [float ,  6.2] 등락율                          StartPos 18, Length 6
	char    price[8];    char    _price;    // [long  ,    8] 현재가                          StartPos 25, Length 8
	char    opentime[6];    char    _opentime;    // [string,    6] 시가시간                        StartPos 34, Length 6
	char    open[8];    char    _open;    // [long  ,    8] 시가                            StartPos 41, Length 8
	char    hightime[6];    char    _hightime;    // [string,    6] 고가시간                        StartPos 50, Length 6
	char    high[8];    char    _high;    // [long  ,    8] 고가                            StartPos 57, Length 8
	char    lowtime[6];    char    _lowtime;    // [string,    6] 저가시간                        StartPos 66, Length 6
	char    low[8];    char    _low;    // [long  ,    8] 저가                            StartPos 73, Length 8
	char    cgubun[1];    char    _cgubun;    // [string,    1] 체결구분                        StartPos 82, Length 1
	char    cvolume[8];    char    _cvolume;    // [long  ,    8] 체결량                          StartPos 84, Length 8
	char    volume[12];    char    _volume;    // [long  ,   12] 누적거래량                      StartPos 93, Length 12
	char    value[12];    char    _value;    // [long  ,   12] 누적거래대금                    StartPos 106, Length 12
	char    mdvolume[12];    char    _mdvolume;    // [long  ,   12] 매도누적체결량                  StartPos 119, Length 12
	char    mdchecnt[8];    char    _mdchecnt;    // [long  ,    8] 매도누적체결건수                StartPos 132, Length 8
	char    msvolume[12];    char    _msvolume;    // [long  ,   12] 매수누적체결량                  StartPos 141, Length 12
	char    mschecnt[8];    char    _mschecnt;    // [long  ,    8] 매수누적체결건수                StartPos 154, Length 8
	char    cpower[9];    char    _cpower;    // [float ,  9.2] 체결강도                        StartPos 163, Length 9
	char    w_avrg[8];    char    _w_avrg;    // [long  ,    8] 가중평균가                      StartPos 173, Length 8
	char    offerho[8];    char    _offerho;    // [long  ,    8] 매도호가                        StartPos 182, Length 8
	char    bidho[8];    char    _bidho;    // [long  ,    8] 매수호가                        StartPos 191, Length 8
	char    status[2];    char    _status;    // [string,    2] 장정보                          StartPos 200, Length 2
	char    jnilvolume[12];    char    _jnilvolume;    // [long  ,   12] 전일동시간대거래량              StartPos 203, Length 12
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 216, Length 6
} S3__OutBlock, * LPS3__OutBlock;
#define NAME_S3__OutBlock     "OutBlock"


// 입력                           
typedef struct _FC0_InBlock
{
	char    futcode[8];     // [string,    8] 단축코드                        StartPos 0, Length 8
} FC0_InBlock, * LPFC0_InBlock;
#define NAME_FC0_InBlock     "InBlock"

// 출력                           
typedef struct _FC0_OutBlock
{
	char    chetime[6];    char    _chetime;    // [string,    6] 체결시간                        StartPos 0, Length 6
	char    sign[1];    char    _sign;    // [string,    1] 전일대비구분                    StartPos 7, Length 1
	char    change[6];    char    _change;    // [float ,  6.2] 전일대비                        StartPos 9, Length 6
	char    drate[6];    char    _drate;    // [float ,  6.2] 등락율                          StartPos 16, Length 6
	char    price[6];    char    _price;    // [float ,  6.2] 현재가                          StartPos 23, Length 6
	char    open[6];    char    _open;    // [float ,  6.2] 시가                            StartPos 30, Length 6
	char    high[6];    char    _high;    // [float ,  6.2] 고가                            StartPos 37, Length 6
	char    low[6];    char    _low;    // [float ,  6.2] 저가                            StartPos 44, Length 6
	char    cgubun[1];    char    _cgubun;    // [string,    1] 체결구분                        StartPos 51, Length 1
	char    cvolume[6];    char    _cvolume;    // [long  ,    6] 체결량                          StartPos 53, Length 6
	char    volume[12];    char    _volume;    // [long  ,   12] 누적거래량                      StartPos 60, Length 12
	char    value[12];    char    _value;    // [long  ,   12] 누적거래대금                    StartPos 73, Length 12
	char    mdvolume[12];    char    _mdvolume;    // [long  ,   12] 매도누적체결량                  StartPos 86, Length 12
	char    mdchecnt[8];    char    _mdchecnt;    // [long  ,    8] 매도누적체결건수                StartPos 99, Length 8
	char    msvolume[12];    char    _msvolume;    // [long  ,   12] 매수누적체결량                  StartPos 108, Length 12
	char    mschecnt[8];    char    _mschecnt;    // [long  ,    8] 매수누적체결건수                StartPos 121, Length 8
	char    cpower[9];    char    _cpower;    // [float ,  9.2] 체결강도                        StartPos 130, Length 9
	char    offerho1[6];    char    _offerho1;    // [float ,  6.2] 매도호가1                       StartPos 140, Length 6
	char    bidho1[6];    char    _bidho1;    // [float ,  6.2] 매수호가1                       StartPos 147, Length 6
	char    openyak[8];    char    _openyak;    // [long  ,    8] 미결제약정수량                  StartPos 154, Length 8
	char    k200jisu[6];    char    _k200jisu;    // [float ,  6.2] KOSPI200지수                    StartPos 163, Length 6
	char    theoryprice[6];    char    _theoryprice;    // [float ,  6.2] 이론가                          StartPos 170, Length 6
	char    kasis[6];    char    _kasis;    // [float ,  6.2] 괴리율                          StartPos 177, Length 6
	char    sbasis[6];    char    _sbasis;    // [float ,  6.2] 시장BASIS                       StartPos 184, Length 6
	char    ibasis[6];    char    _ibasis;    // [float ,  6.2] 이론BASIS                       StartPos 191, Length 6
	char    openyakcha[8];    char    _openyakcha;    // [long  ,    8] 미결제약정증감                  StartPos 198, Length 8
	char    jgubun[2];    char    _jgubun;    // [string,    2] 장운영정보                      StartPos 207, Length 2
	char    jnilvolume[12];    char    _jnilvolume;    // [long  ,   12] 전일동시간대거래량              StartPos 210, Length 12
	char    futcode[8];    char    _futcode;    // [string,    8] 단축코드                        StartPos 223, Length 8
} FC0_OutBlock, * LPFC0_OutBlock;
#define NAME_FC0_OutBlock     "OutBlock"

// 입력                           
typedef struct _OVC_InBlock
{
	char    symbol[8];    // [string,    8] 종목코드                        StartPos 0, Length 8
} OVC_InBlock, * LPOVC_InBlock;
#define NAME_OVC_InBlock     "InBlock"

// 출력                           
typedef struct _OVC_OutBlock
{
	char    symbol[8];    char    _symbol;    // [string,    8] 종목코드                        StartPos 0, Length 8
	char    ovsdate[8];    char    _ovsdate;    // [string,    8] 체결일자(현지)                  StartPos 9, Length 8
	char    kordate[8];    char    _kordate;    // [string,    8] 체결일자(한국)                  StartPos 18, Length 8
	char    trdtm[6];    char    _trdtm;    // [string,    6] 체결시간(현지)                  StartPos 27, Length 6
	char    kortm[6];    char    _kortm;    // [string,    6] 체결시간(한국)                  StartPos 34, Length 6
	char    curpr[15];    char    _curpr;    // [double, 15.9] 체결가격                        StartPos 41, Length 15
	char    ydiffpr[15];    char    _ydiffpr;    // [double, 15.9] 전일대비                        StartPos 57, Length 15
	char    ydiffSign[1];    char    _ydiffSign;    // [string,    1] 전일대비기호                    StartPos 73, Length 1
	char    open[15];    char    _open;    // [double, 15.9] 시가                            StartPos 75, Length 15
	char    high[15];    char    _high;    // [double, 15.9] 고가                            StartPos 91, Length 15
	char    low[15];    char    _low;    // [double, 15.9] 저가                            StartPos 107, Length 15
	char    chgrate[6];    char    _chgrate;    // [float ,  6.2] 등락율                          StartPos 123, Length 6
	char    trdq[10];    char    _trdq;    // [long  ,   10] 건별체결수량                    StartPos 130, Length 10
	char    totq[15];    char    _totq;    // [string,   15] 누적체결수량                    StartPos 141, Length 15
	char    cgubun[1];    char    _cgubun;    // [string,    1] 체결구분                        StartPos 157, Length 1
	char    mdvolume[15];    char    _mdvolume;    // [string,   15] 매도누적체결수량                StartPos 159, Length 15
	char    msvolume[15];    char    _msvolume;    // [string,   15] 매수누적체결수량                StartPos 175, Length 15
	char    ovsmkend[8];    char    _ovsmkend;    // [string,    8] 장마감일                        StartPos 191, Length 8
} OVC_OutBlock, * LPOVC_OutBlock;
#define NAME_OVC_OutBlock     "OutBlock"


// 입력                           
typedef struct _I5__InBlock
{
	char    shcode[6];   // [string,    6] 단축코드                        StartPos 0, Length 6
} I5__InBlock, * LPI5__InBlock;
#define NAME_I5__InBlock     "InBlock"

// 출력                           
typedef struct _I5__OutBlock
{
	char    time[8];    char    _time;    // [string,    8] 시간                            StartPos 0, Length 8
	char    price[8];    char    _price;    // [long  ,    8] 현재가                          StartPos 9, Length 8
	char    sign[1];    char    _sign;    // [string,    1] 전일대비구분                    StartPos 18, Length 1
	char    change[8];    char    _change;    // [long  ,    8] 전일대비                        StartPos 20, Length 8
	char    volume[12];    char    _volume;    // [float ,   12] 누적거래량                      StartPos 29, Length 12
	char    navdiff[9];    char    _navdiff;    // [float ,  9.2] NAV대비                         StartPos 42, Length 9
	char    nav[9];    char    _nav;    // [float ,  9.2] NAV                             StartPos 52, Length 9
	char    navchange[9];    char    _navchange;    // [float ,  9.2] 전일대비                        StartPos 62, Length 9
	char    crate[9];    char    _crate;    // [float ,  9.2] 추적오차                        StartPos 72, Length 9
	char    grate[9];    char    _grate;    // [float ,  9.2] 괴리                            StartPos 82, Length 9
	char    jisu[8];    char    _jisu;    // [float ,  8.2] 지수                            StartPos 92, Length 8
	char    jichange[8];    char    _jichange;    // [float ,  8.2] 전일대비                        StartPos 101, Length 8
	char    jirate[8];    char    _jirate;    // [float ,  8.2] 전일대비율                      StartPos 110, Length 8
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 119, Length 6
} I5__OutBlock, * LPI5__OutBlock;
#define NAME_I5__OutBlock     "OutBlock"


// 입력                           
typedef struct _H1__InBlock
{
	char    shcode[6];       // [string,    6] 단축코드                        StartPos 0, Length 6
} H1__InBlock, * LPH1__InBlock;
#define NAME_H1__InBlock     "InBlock"

// 출력                           
typedef struct _H1__OutBlock
{
	char    hotime[6];    char    _hotime;    // [string,    6] 호가시간                        StartPos 0, Length 6
	char    offerho1[7];    char    _offerho1;    // [long  ,    7] 매도호가1                       StartPos 7, Length 7
	char    bidho1[7];    char    _bidho1;    // [long  ,    7] 매수호가1                       StartPos 15, Length 7
	char    offerrem1[9];    char    _offerrem1;    // [long  ,    9] 매도호가잔량1                   StartPos 23, Length 9
	char    bidrem1[9];    char    _bidrem1;    // [long  ,    9] 매수호가잔량1                   StartPos 33, Length 9
	char    offerho2[7];    char    _offerho2;    // [long  ,    7] 매도호가2                       StartPos 43, Length 7
	char    bidho2[7];    char    _bidho2;    // [long  ,    7] 매수호가2                       StartPos 51, Length 7
	char    offerrem2[9];    char    _offerrem2;    // [long  ,    9] 매도호가잔량2                   StartPos 59, Length 9
	char    bidrem2[9];    char    _bidrem2;    // [long  ,    9] 매수호가잔량2                   StartPos 69, Length 9
	char    offerho3[7];    char    _offerho3;    // [long  ,    7] 매도호가3                       StartPos 79, Length 7
	char    bidho3[7];    char    _bidho3;    // [long  ,    7] 매수호가3                       StartPos 87, Length 7
	char    offerrem3[9];    char    _offerrem3;    // [long  ,    9] 매도호가잔량3                   StartPos 95, Length 9
	char    bidrem3[9];    char    _bidrem3;    // [long  ,    9] 매수호가잔량3                   StartPos 105, Length 9
	char    offerho4[7];    char    _offerho4;    // [long  ,    7] 매도호가4                       StartPos 115, Length 7
	char    bidho4[7];    char    _bidho4;    // [long  ,    7] 매수호가4                       StartPos 123, Length 7
	char    offerrem4[9];    char    _offerrem4;    // [long  ,    9] 매도호가잔량4                   StartPos 131, Length 9
	char    bidrem4[9];    char    _bidrem4;    // [long  ,    9] 매수호가잔량4                   StartPos 141, Length 9
	char    offerho5[7];    char    _offerho5;    // [long  ,    7] 매도호가5                       StartPos 151, Length 7
	char    bidho5[7];    char    _bidho5;    // [long  ,    7] 매수호가5                       StartPos 159, Length 7
	char    offerrem5[9];    char    _offerrem5;    // [long  ,    9] 매도호가잔량5                   StartPos 167, Length 9
	char    bidrem5[9];    char    _bidrem5;    // [long  ,    9] 매수호가잔량5                   StartPos 177, Length 9
	char    offerho6[7];    char    _offerho6;    // [long  ,    7] 매도호가6                       StartPos 187, Length 7
	char    bidho6[7];    char    _bidho6;    // [long  ,    7] 매수호가6                       StartPos 195, Length 7
	char    offerrem6[9];    char    _offerrem6;    // [long  ,    9] 매도호가잔량6                   StartPos 203, Length 9
	char    bidrem6[9];    char    _bidrem6;    // [long  ,    9] 매수호가잔량6                   StartPos 213, Length 9
	char    offerho7[7];    char    _offerho7;    // [long  ,    7] 매도호가7                       StartPos 223, Length 7
	char    bidho7[7];    char    _bidho7;    // [long  ,    7] 매수호가7                       StartPos 231, Length 7
	char    offerrem7[9];    char    _offerrem7;    // [long  ,    9] 매도호가잔량7                   StartPos 239, Length 9
	char    bidrem7[9];    char    _bidrem7;    // [long  ,    9] 매수호가잔량7                   StartPos 249, Length 9
	char    offerho8[7];    char    _offerho8;    // [long  ,    7] 매도호가8                       StartPos 259, Length 7
	char    bidho8[7];    char    _bidho8;    // [long  ,    7] 매수호가8                       StartPos 267, Length 7
	char    offerrem8[9];    char    _offerrem8;    // [long  ,    9] 매도호가잔량8                   StartPos 275, Length 9
	char    bidrem8[9];    char    _bidrem8;    // [long  ,    9] 매수호가잔량8                   StartPos 285, Length 9
	char    offerho9[7];    char    _offerho9;    // [long  ,    7] 매도호가9                       StartPos 295, Length 7
	char    bidho9[7];    char    _bidho9;    // [long  ,    7] 매수호가9                       StartPos 303, Length 7
	char    offerrem9[9];    char    _offerrem9;    // [long  ,    9] 매도호가잔량9                   StartPos 311, Length 9
	char    bidrem9[9];    char    _bidrem9;    // [long  ,    9] 매수호가잔량9                   StartPos 321, Length 9
	char    offerho10[7];    char    _offerho10;    // [long  ,    7] 매도호가10                      StartPos 331, Length 7
	char    bidho10[7];    char    _bidho10;    // [long  ,    7] 매수호가10                      StartPos 339, Length 7
	char    offerrem10[9];    char    _offerrem10;    // [long  ,    9] 매도호가잔량10                  StartPos 347, Length 9
	char    bidrem10[9];    char    _bidrem10;    // [long  ,    9] 매수호가잔량10                  StartPos 357, Length 9
	char    totofferrem[9];    char    _totofferrem;    // [long  ,    9] 총매도호가잔량                  StartPos 367, Length 9
	char    totbidrem[9];    char    _totbidrem;    // [long  ,    9] 총매수호가잔량                  StartPos 377, Length 9
	char    donsigubun[1];    char    _donsigubun;    // [string,    1] 동시호가구분                    StartPos 387, Length 1
	char    shcode[6];    char    _shcode;    // [string,    6] 단축코드                        StartPos 389, Length 6
	char    alloc_gubun[1];    char    _alloc_gubun;    // [string,    1] 배분적용구분                    StartPos 396, Length 1
} H1__OutBlock, * LPH1__OutBlock;
#define NAME_H1__OutBlock     "OutBlock"



#define NAME_t2101     "t2101"

// 기본입력                       
typedef struct _t2101InBlock
{
	char    focode[8];    char    _focode;    // [string,    8] 단축코드                        StartPos 0, Length 8
} t2101InBlock, * LPt2101InBlock;
#define NAME_t2101InBlock     "t2101InBlock"

// 출력                           
typedef struct _t2101OutBlock
{
	char    hname[20];    char    _hname;    // [string,   20] 한글명                          StartPos 0, Length 20
	char    price[6];    char    _price;    // [float ,  6.2] 현재가                          StartPos 21, Length 6
	char    sign[1];    char    _sign;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
	char    change[6];    char    _change;    // [float ,  6.2] 전일대비                        StartPos 30, Length 6
	char    jnilclose[6];    char    _jnilclose;    // [float ,  6.2] 전일종가                        StartPos 37, Length 6
	char    diff[6];    char    _diff;    // [float ,  6.2] 등락율                          StartPos 44, Length 6
	char    volume[12];    char    _volume;    // [long  ,   12] 거래량                          StartPos 51, Length 12
	char    value[12];    char    _value;    // [long  ,   12] 거래대금                        StartPos 64, Length 12
	char    mgjv[8];    char    _mgjv;    // [long  ,    8] 미결제량                        StartPos 77, Length 8
	char    mgjvdiff[8];    char    _mgjvdiff;    // [long  ,    8] 미결제증감                      StartPos 86, Length 8
	char    open[6];    char    _open;    // [float ,  6.2] 시가                            StartPos 95, Length 6
	char    high[6];    char    _high;    // [float ,  6.2] 고가                            StartPos 102, Length 6
	char    low[6];    char    _low;    // [float ,  6.2] 저가                            StartPos 109, Length 6
	char    uplmtprice[6];    char    _uplmtprice;    // [float ,  6.2] 상한가                          StartPos 116, Length 6
	char    dnlmtprice[6];    char    _dnlmtprice;    // [float ,  6.2] 하한가                          StartPos 123, Length 6
	char    high52w[6];    char    _high52w;    // [float ,  6.2] 52최고가                        StartPos 130, Length 6
	char    low52w[6];    char    _low52w;    // [float ,  6.2] 52최저가                        StartPos 137, Length 6
	char    basis[6];    char    _basis;    // [float ,  6.2] 베이시스                        StartPos 144, Length 6
	char    recprice[6];    char    _recprice;    // [float ,  6.2] 기준가                          StartPos 151, Length 6
	char    theoryprice[6];    char    _theoryprice;    // [float ,  6.2] 이론가                          StartPos 158, Length 6
	char    glyl[6];    char    _glyl;    // [float ,  6.3] 괴리율                          StartPos 165, Length 6
	char    cbhprice[6];    char    _cbhprice;    // [float ,  6.2] CB상한가                        StartPos 172, Length 6
	char    cblprice[6];    char    _cblprice;    // [float ,  6.2] CB하한가                        StartPos 179, Length 6
	char    lastmonth[8];    char    _lastmonth;    // [string,    8] 만기일                          StartPos 186, Length 8
	char    jandatecnt[8];    char    _jandatecnt;    // [long  ,    8] 잔여일                          StartPos 195, Length 8
	char    pricejisu[6];    char    _pricejisu;    // [float ,  6.2] 종합지수                        StartPos 204, Length 6
	char    jisusign[1];    char    _jisusign;    // [string,    1] 종합지수전일대비구분            StartPos 211, Length 1
	char    jisuchange[6];    char    _jisuchange;    // [float ,  6.2] 종합지수전일대비                StartPos 213, Length 6
	char    jisudiff[6];    char    _jisudiff;    // [float ,  6.2] 종합지수등락율                  StartPos 220, Length 6
	char    kospijisu[6];    char    _kospijisu;    // [float ,  6.2] KOSPI200지수                    StartPos 227, Length 6
	char    kospisign[1];    char    _kospisign;    // [string,    1] KOSPI200전일대비구분            StartPos 234, Length 1
	char    kospichange[6];    char    _kospichange;    // [float ,  6.2] KOSPI200전일대비                StartPos 236, Length 6
	char    kospidiff[6];    char    _kospidiff;    // [float ,  6.2] KOSPI200등락율                  StartPos 243, Length 6
	char    listhprice[6];    char    _listhprice;    // [float ,  6.2] 상장최고가                      StartPos 250, Length 6
	char    listlprice[6];    char    _listlprice;    // [float ,  6.2] 상장최저가                      StartPos 257, Length 6
	char    delt[6];    char    _delt;    // [float ,  6.4] 델타                            StartPos 264, Length 6
	char    gama[6];    char    _gama;    // [float ,  6.4] 감마                            StartPos 271, Length 6
	char    ceta[6];    char    _ceta;    // [float ,  6.4] 세타                            StartPos 278, Length 6
	char    vega[6];    char    _vega;    // [float ,  6.4] 베가                            StartPos 285, Length 6
	char    rhox[6];    char    _rhox;    // [float ,  6.4] 로우                            StartPos 292, Length 6
	char    gmprice[6];    char    _gmprice;    // [float ,  6.2] 근월물현재가                    StartPos 299, Length 6
	char    gmsign[1];    char    _gmsign;    // [string,    1] 근월물전일대비구분              StartPos 306, Length 1
	char    gmchange[6];    char    _gmchange;    // [float ,  6.2] 근월물전일대비                  StartPos 308, Length 6
	char    gmdiff[6];    char    _gmdiff;    // [float ,  6.2] 근월물등락율                    StartPos 315, Length 6
	char    theorypriceg[6];    char    _theorypriceg;    // [float ,  6.2] 이론가                          StartPos 322, Length 6
	char    histimpv[6];    char    _histimpv;    // [float ,  6.2] 역사적변동성                    StartPos 329, Length 6
	char    impv[6];    char    _impv;    // [float ,  6.2] 내재변동성                      StartPos 336, Length 6
	char    sbasis[6];    char    _sbasis;    // [float ,  6.2] 시장BASIS                       StartPos 343, Length 6
	char    ibasis[6];    char    _ibasis;    // [float ,  6.2] 이론BASIS                       StartPos 350, Length 6
	char    gmfutcode[8];    char    _gmfutcode;    // [string,    8] 근월물종목코드                  StartPos 357, Length 8
	char    actprice[6];    char    _actprice;    // [float ,  6.2] 행사가                          StartPos 366, Length 6
	char    greeks_time[6];    char    _greeks_time;    // [string,    6] 거래소민감도수신시간            StartPos 373, Length 6
	char    greeks_confirm[8];    char    _greeks_confirm;    // [string,    8] 거래소민감도확정여부            StartPos 380, Length 8
	char    danhochk[1];    char    _danhochk;    // [string,    1] 단일가호가여부                  StartPos 389, Length 1
	char    yeprice[6];    char    _yeprice;    // [float ,  6.2] 예상체결가                      StartPos 391, Length 6
	char    jnilysign[1];    char    _jnilysign;    // [string,    1] 예상체결가전일종가대비구분      StartPos 398, Length 1
	char    jnilychange[6];    char    _jnilychange;    // [float ,  6.2] 예상체결가전일종가대비          StartPos 400, Length 6
	char    jnilydrate[6];    char    _jnilydrate;    // [float ,  6.2] 예상체결가전일종가등락율        StartPos 407, Length 6
	char    alloc_gubun[1];    char    _alloc_gubun;    // [string,    1] 배분구분(1:배분개시2:배분해제0: StartPos 414, Length 1
	char    bjandatecnt[8];    char    _bjandatecnt;    // [long  ,    8] 잔여일(영업일)                  StartPos 416, Length 8
	char    focode[8];    char    _focode;    // [string,    8] 종목코드                        StartPos 425, Length 8
	char    dy_gubun[1];    char    _dy_gubun;    // [string,    1] 실시간가격제한여부(0:대상아님1: StartPos 434, Length 1
	char    dy_uplmtprice[6];    char    _dy_uplmtprice;    // [float ,  6.2] 실시간상한가                    StartPos 436, Length 6
	char    dy_dnlmtprice[6];    char    _dy_dnlmtprice;    // [float ,  6.2] 실시간하한가                    StartPos 443, Length 6
	char    updnstep_gubun[1];    char    _updnstep_gubun;    // [string,    1] 가격제한폭확대(0:미확대1:확대2: StartPos 450, Length 1
	char    upstep[2];    char    _upstep;    // [string,    2] 상한적용단계                    StartPos 452, Length 2
	char    dnstep[2];    char    _dnstep;    // [string,    2] 하한적용단계                    StartPos 455, Length 2
	char    uplmtprice_3rd[6];    char    _uplmtprice_3rd;    // [float ,  6.2] 3단계상한가                     StartPos 458, Length 6
	char    dnlmtprice_3rd[6];    char    _dnlmtprice_3rd;    // [float ,  6.2] 3단계하한가                     StartPos 465, Length 6
} t2101OutBlock, * LPt2101OutBlock;
#define NAME_t2101OutBlock     "t2101OutBlock"


///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 계좌예탁금증거금조회 ( ENCRYPT,SERVICE=CFOBQ10500,HEADTYPE=B,CREATOR=정명기,CREDATE=2012/03/12 15:03:11 )


#define NAME_CFOBQ10500     "CFOBQ10500"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500InBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
} CFOBQ10500InBlock1, * LPCFOBQ10500InBlock1;
#define NAME_CFOBQ10500InBlock1     "CFOBQ10500InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
} CFOBQ10500OutBlock1, * LPCFOBQ10500OutBlock1;
#define NAME_CFOBQ10500OutBlock1     "CFOBQ10500OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOBQ10500OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] 계좌명                          StartPos 5, Length 40
	char    DpsamtTotamt[16];    // [long  ,   16] 예탁금총액                      StartPos 45, Length 16 //
	char    Dps[16];    // [long  ,   16] 예수금                          StartPos 61, Length 16
	char    SubstAmt[16];    // [long  ,   16] 대용금액                        StartPos 77, Length 16
	char    FilupDpsamtTotamt[16];    // [long  ,   16] 충당예탁금총액                  StartPos 93, Length 16
	char    FilupDps[16];    // [long  ,   16] 충당예수금                      StartPos 109, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] 선물손익금액                    StartPos 125, Length 16 //
	char    WthdwAbleAmt[16];    // [long  ,   16] 인출가능금액                    StartPos 141, Length 16
	char    PsnOutAbleCurAmt[16];    // [long  ,   16] 인출가능현금액                  StartPos 157, Length 16
	char    PsnOutAbleSubstAmt[16];    // [long  ,   16] 인출가능대용금액                StartPos 173, Length 16
	char    Mgn[16];    // [long  ,   16] 증거금액                        StartPos 189, Length 16
	char    MnyMgn[16];    // [long  ,   16] 현금증거금액                    StartPos 205, Length 16
	char    OrdAbleAmt[16];    // [long  ,   16] 주문가능금액                    StartPos 221, Length 16 //
	char    MnyOrdAbleAmt[16];    // [long  ,   16] 현금주문가능금액                StartPos 237, Length 16
	char    AddMgn[16];    // [long  ,   16] 추가증거금액                    StartPos 253, Length 16 //
	char    MnyAddMgn[16];    // [long  ,   16] 현금추가증거금액                StartPos 269, Length 16
	char    AmtPrdayChckInAmt[16];    // [long  ,   16] 금전일수표입금액                StartPos 285, Length 16
	char    FnoPrdaySubstSellAmt[16];    // [long  ,   16] 선물옵션전일대용매도금액        StartPos 301, Length 16
	char    FnoCrdaySubstSellAmt[16];    // [long  ,   16] 선물옵션금일대용매도금액        StartPos 317, Length 16
	char    FnoPrdayFdamt[16];    // [long  ,   16] 선물옵션전일가입금액            StartPos 333, Length 16
	char    FnoCrdayFdamt[16];    // [long  ,   16] 선물옵션금일가입금액            StartPos 349, Length 16
	char    FcurrSubstAmt[16];    // [long  ,   16] 외화대용금액                    StartPos 365, Length 16
	char    FnoAcntAfmgnNm[20];    // [string,   20] 선물옵션계좌사후증거금명        StartPos 381, Length 20
} CFOBQ10500OutBlock2, * LPCFOBQ10500OutBlock2;
#define NAME_CFOBQ10500OutBlock2     "CFOBQ10500OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CFOBQ10500OutBlock3
{
	char    PdGrpCodeNm[20];    // [string,   20] 상품군코드명                    StartPos 0, Length 20
	char    NetRiskMgn[16];    // [long  ,   16] 순위험증거금액                  StartPos 20, Length 16
	char    PrcMgn[16];    // [long  ,   16] 가격증거금액                    StartPos 36, Length 16
	char    SprdMgn[16];    // [long  ,   16] 스프레드증거금액                StartPos 52, Length 16
	char    PrcFlctMgn[16];    // [long  ,   16] 가격변동증거금액                StartPos 68, Length 16
	char    MinMgn[16];    // [long  ,   16] 최소증거금액                    StartPos 84, Length 16
	char    OrdMgn[16];    // [long  ,   16] 주문증거금액                    StartPos 100, Length 16
	char    OptNetBuyAmt[16];    // [long  ,   16] 옵션순매수금액                  StartPos 116, Length 16
	char    CsgnMgn[16];    // [long  ,   16] 위탁증거금액                    StartPos 132, Length 16 //
	char    MaintMgn[16];    // [long  ,   16] 유지증거금액                    StartPos 148, Length 16 //
	char    FutsBuyExecAmt[16];    // [long  ,   16] 선물매수체결금액                StartPos 164, Length 16
	char    FutsSellExecAmt[16];    // [long  ,   16] 선물매도체결금액                StartPos 180, Length 16
	char    OptBuyExecAmt[16];    // [long  ,   16] 옵션매수체결금액                StartPos 196, Length 16
	char    OptSellExecAmt[16];    // [long  ,   16] 옵션매도체결금액                StartPos 212, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] 선물손익금액                    StartPos 228, Length 16
	char    TotRiskCsgnMgn[16];    // [long  ,   16] 총위험위탁증거금                StartPos 244, Length 16
	char    UndCsgnMgn[16];    // [long  ,   16] 인수도위탁증거금                StartPos 260, Length 16
	char    MgnRdctAmt[16];    // [long  ,   16] 증거금감면금액                  StartPos 276, Length 16
} CFOBQ10500OutBlock3, * LPCFOBQ10500OutBlock3;
#define NAME_CFOBQ10500OutBlock3     "CFOBQ10500OutBlock3"



///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션가정산예탁금상세 ( SERVICE=CFOEQ11100,HEADTYPE=B,CREATOR=김정현,CREDATE=2012/03/16 14:04:41 )

#define NAME_CFOEQ11100     "CFOEQ11100"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100InBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
	char    BnsDt[8];    // [string,    8] 매매일                          StartPos 33, Length 8
} CFOEQ11100InBlock1, * LPCFOEQ11100InBlock1;
#define NAME_CFOEQ11100InBlock1     "CFOEQ11100InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
	char    BnsDt[8];    // [string,    8] 매매일                          StartPos 33, Length 8
} CFOEQ11100OutBlock1, * LPCFOEQ11100OutBlock1;
#define NAME_CFOEQ11100OutBlock1     "CFOEQ11100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ11100OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] 계좌명                          StartPos 5, Length 40
	char    OpnmkDpsamtTotamt[16];    // [long  ,   16] 개장시예탁금총액                StartPos 45, Length 16
	char    OpnmkDps[16];    // [long  ,   16] 개장시예수금                    StartPos 61, Length 16
	char    OpnmkMnyrclAmt[16];    // [long  ,   16] 개장시현금미수금                StartPos 77, Length 16
	char    OpnmkSubstAmt[16];    // [long  ,   16] 개장시대용금액                  StartPos 93, Length 16
	char    TotAmt[16];    // [long  ,   16] 총금액                          StartPos 109, Length 16
	char    Dps[16];    // [long  ,   16] 예수금                          StartPos 125, Length 16
	char    MnyrclAmt[16];    // [long  ,   16] 현금미수금액                    StartPos 141, Length 16
	char    SubstDsgnAmt[16];    // [long  ,   16] 대용지정금액                    StartPos 157, Length 16
	char    CsgnMgn[16];    // [long  ,   16] 위탁증거금액                    StartPos 173, Length 16
	char    MnyCsgnMgn[16];    // [long  ,   16] 현금위탁증거금액                StartPos 189, Length 16
	char    MaintMgn[16];    // [long  ,   16] 유지증거금액                    StartPos 205, Length 16
	char    MnyMaintMgn[16];    // [long  ,   16] 현금유지증거금액                StartPos 221, Length 16
	char    OutAbleAmt[16];    // [long  ,   16] 출금가능총액                    StartPos 237, Length 16
	char    MnyoutAbleAmt[16];    // [long  ,   16] 출금가능금액                    StartPos 253, Length 16
	char    SubstOutAbleAmt[16];    // [long  ,   16] 출금가능대용                    StartPos 269, Length 16
	char    OrdAbleAmt[16];    // [long  ,   16] 주문가능금액                    StartPos 285, Length 16
	char    MnyOrdAbleAmt[16];    // [long  ,   16] 현금주문가능금액                StartPos 301, Length 16
	char    AddMgnOcrTpCode[1];    // [string,    1] 추가증거금구분                  StartPos 317, Length 1
	char    AddMgn[16];    // [long  ,   16] 추가증거금액                    StartPos 318, Length 16
	char    MnyAddMgn[16];    // [long  ,   16] 현금추가증거금액                StartPos 334, Length 16
	char    NtdayTotAmt[16];    // [long  ,   16] 익일예탁총액                    StartPos 350, Length 16
	char    NtdayDps[16];    // [long  ,   16] 익일예탁현금                    StartPos 366, Length 16
	char    NtdayMnyrclAmt[16];    // [long  ,   16] 익일미수금                      StartPos 382, Length 16
	char    NtdaySubstAmt[16];    // [long  ,   16] 익일예탁대용                    StartPos 398, Length 16
	char    NtdayCsgnMgn[16];    // [long  ,   16] 익일위탁증거금                  StartPos 414, Length 16
	char    NtdayMnyCsgnMgn[16];    // [long  ,   16] 익일위탁증거금현금              StartPos 430, Length 16
	char    NtdayMaintMgn[16];    // [long  ,   16] 익일유지증거금                  StartPos 446, Length 16
	char    NtdayMnyMaintMgn[16];    // [long  ,   16] 익일유지증거금현금              StartPos 462, Length 16
	char    NtdayOutAbleAmt[16];    // [long  ,   16] 익일인출가능금액                StartPos 478, Length 16
	char    NtdayMnyoutAbleAmt[16];    // [long  ,   16] 익일인출가능금액                StartPos 494, Length 16
	char    NtdaySubstOutAbleAmt[16];    // [long  ,   16] 익일인출가능대용                StartPos 510, Length 16
	char    NtdayOrdAbleAmt[16];    // [long  ,   16] 익일주문가능금액                StartPos 526, Length 16
	char    NtdayMnyOrdAbleAmt[16];    // [long  ,   16] 익일주문가능현금                StartPos 542, Length 16
	char    NtdayAddMgnTp[1];    // [string,    1] 익일추가증거금구분              StartPos 558, Length 1
	char    NtdayAddMgn[16];    // [long  ,   16] 익일추가증거금                  StartPos 559, Length 16
	char    NtdayMnyAddMgn[16];    // [long  ,   16] 익일추가증거금현금              StartPos 575, Length 16
	char    NtdaySettAmt[16];    // [long  ,   16] 익일결제금액                    StartPos 591, Length 16
	char    EvalDpsamtTotamt[15];    // [long  ,   15] 평가예탁금총액                  StartPos 607, Length 15
	char    MnyEvalDpstgAmt[15];    // [long  ,   15] 현금평가예탁금액                StartPos 622, Length 15
	char    DpsamtUtlfeeGivPrergAmt[16];    // [long  ,   16] 예탁금이용료지급예정금액        StartPos 637, Length 16
	char    TaxAmt[16];    // [long  ,   16] 세금                            StartPos 653, Length 16
	char    CsgnMgnrat[7];    // [double,  7.2] 위탁증거금 비율                 StartPos 669, Length 7
	char    CsgnMnyMgnrat[7];    // [double,  7.2] 위탁증거금현금비율              StartPos 676, Length 7
	char    DpstgTotamtLackAmt[16];    // [long  ,   16] 예탁총액부족금액(위탁증거금기준 StartPos 683, Length 16
	char    DpstgMnyLackAmt[16];    // [long  ,   16] 예탁현금부족금액(위탁증거금기준 StartPos 699, Length 16
	char    RealInAmt[16];    // [long  ,   16] 실입금액                        StartPos 715, Length 16
	char    InAmt[16];    // [long  ,   16] 입금액                          StartPos 731, Length 16
	char    OutAmt[16];    // [long  ,   16] 출금액                          StartPos 747, Length 16
	char    FutsAdjstDfamt[16];    // [long  ,   16] 선물정산차금                    StartPos 763, Length 16
	char    FutsThdayDfamt[16];    // [long  ,   16] 선물당일차금                    StartPos 779, Length 16
	char    FutsUpdtDfamt[16];    // [long  ,   16] 선물갱신차금                    StartPos 795, Length 16
	char    FutsLastSettDfamt[16];    // [long  ,   16] 선물최종결제차금                StartPos 811, Length 16
	char    OptSettDfamt[16];    // [long  ,   16] 옵션결제차금                    StartPos 827, Length 16
	char    OptBuyAmt[16];    // [long  ,   16] 옵션매수금액                    StartPos 843, Length 16
	char    OptSellAmt[16];    // [long  ,   16] 옵션매도금액                    StartPos 859, Length 16
	char    OptXrcDfamt[16];    // [long  ,   16] 옵션행사차금                    StartPos 875, Length 16
	char    OptAsgnDfamt[16];    // [long  ,   16] 옵션배정차금                    StartPos 891, Length 16
	char    RealGdsUndAmt[16];    // [long  ,   16] 실물인수도금액                  StartPos 907, Length 16
	char    RealGdsUndAsgnAmt[16];    // [long  ,   16] 실물인수도배정대금              StartPos 923, Length 16
	char    RealGdsUndXrcAmt[16];    // [long  ,   16] 실물인수도행사대금              StartPos 939, Length 16
	char    CmsnAmt[16];    // [long  ,   16] 수수료                          StartPos 955, Length 16
	char    FutsCmsn[16];    // [long  ,   16] 선물수수료                      StartPos 971, Length 16
	char    OptCmsn[16];    // [long  ,   16] 옵션수수료                      StartPos 987, Length 16
	char    FutsCtrctQty[16];    // [long  ,   16] 선물약정수량                    StartPos 1003, Length 16
	char    FutsCtrctAmt[16];    // [long  ,   16] 선물약정금액                    StartPos 1019, Length 16
	char    OptCtrctQty[16];    // [long  ,   16] 옵션약정수량                    StartPos 1035, Length 16
	char    OptCtrctAmt[16];    // [long  ,   16] 옵션약정금액                    StartPos 1051, Length 16
	char    FutsUnsttQty[16];    // [long  ,   16] 선물미결제수량                  StartPos 1067, Length 16
	char    FutsUnsttAmt[16];    // [long  ,   16] 선물미결제금액                  StartPos 1083, Length 16
	char    OptUnsttQty[16];    // [long  ,   16] 옵션미결제수량                  StartPos 1099, Length 16
	char    OptUnsttAmt[16];    // [long  ,   16] 옵션미결제금액                  StartPos 1115, Length 16
	char    FutsBuyUnsttQty[16];    // [long  ,   16] 선물매수미결제수량              StartPos 1131, Length 16
	char    FutsBuyUnsttAmt[16];    // [long  ,   16] 선물매수미결제금액              StartPos 1147, Length 16
	char    FutsSellUnsttQty[16];    // [long  ,   16] 선물매도미결제수량              StartPos 1163, Length 16
	char    FutsSellUnsttAmt[16];    // [long  ,   16] 선물매도미결제금액              StartPos 1179, Length 16
	char    OptBuyUnsttQty[16];    // [long  ,   16] 옵션매수미결제수량              StartPos 1195, Length 16
	char    OptBuyUnsttAmt[16];    // [long  ,   16] 옵션매수미결제금액              StartPos 1211, Length 16
	char    OptSellUnsttQty[16];    // [long  ,   16] 옵션매도미결제수량              StartPos 1227, Length 16
	char    OptSellUnsttAmt[16];    // [long  ,   16] 옵션매도미결제금액              StartPos 1243, Length 16
	char    FutsBuyctrQty[16];    // [long  ,   16] 선물매수약정수량                StartPos 1259, Length 16
	char    FutsBuyctrAmt[16];    // [long  ,   16] 선물매수약정금액                StartPos 1275, Length 16
	char    FutsSlctrQty[16];    // [long  ,   16] 선물매도약정수량                StartPos 1291, Length 16
	char    FutsSlctrAmt[16];    // [long  ,   16] 선물매도약정금액                StartPos 1307, Length 16
	char    OptBuyctrQty[16];    // [long  ,   16] 옵션매수약정수량                StartPos 1323, Length 16
	char    OptBuyctrAmt[16];    // [long  ,   16] 옵션매수약정금액                StartPos 1339, Length 16
	char    OptSlctrQty[16];    // [long  ,   16] 옵션매도약정수량                StartPos 1355, Length 16
	char    OptSlctrAmt[16];    // [long  ,   16] 옵션매도약정금액                StartPos 1371, Length 16
	char    FutsBnsplAmt[16];    // [long  ,   16] 선물매매손익금액                StartPos 1387, Length 16
	char    OptBnsplAmt[16];    // [long  ,   16] 옵션매매손익금액                StartPos 1403, Length 16
	char    FutsEvalPnlAmt[16];    // [long  ,   16] 선물평가손익금액                StartPos 1419, Length 16
	char    OptEvalPnlAmt[16];    // [long  ,   16] 옵션평가손익금액                StartPos 1435, Length 16
	char    FutsEvalAmt[16];    // [long  ,   16] 선물평가금액                    StartPos 1451, Length 16
	char    OptEvalAmt[16];    // [long  ,   16] 옵션평가금액                    StartPos 1467, Length 16
	char    MktEndAfMnyInAmt[16];    // [long  ,   16] 장종료후현금입금금액            StartPos 1483, Length 16
	char    MktEndAfMnyOutAmt[16];    // [long  ,   16] 장종료후현금출금금액            StartPos 1499, Length 16
	char    MktEndAfSubstDsgnAmt[16];    // [long  ,   16] 장종료후대용지정금액            StartPos 1515, Length 16
	char    MktEndAfSubstAbndAmt[16];    // [long  ,   16] 장종료후대용해지금액            StartPos 1531, Length 16
} CFOEQ11100OutBlock2, * LPCFOEQ11100OutBlock2;
#define NAME_CFOEQ11100OutBlock2     "CFOEQ11100OutBlock2"


///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션 잔고평가(이동평균) ( ATTR,TUXCODE=T0441,HEADTYPE=D )


#define NAME_t0441     "t0441"

// 기본입력                       
typedef struct _t0441InBlock
{
    char    accno               [  11];    char    _accno               ;    // [string,   11] 계좌번호                        StartPos 0, Length 11
    char    passwd              [   8];    char    _passwd              ;    // [string,    8] 비밀번호                        StartPos 12, Length 8
    char    cts_expcode         [   8];    char    _cts_expcode         ;    // [string,    8] CTS_종목번호                    StartPos 21, Length 8
    char    cts_medocd          [   1];    char    _cts_medocd          ;    // [string,    1] CTS_매매구분                    StartPos 30, Length 1
} t0441InBlock, *LPt0441InBlock;
#define NAME_t0441InBlock     "t0441InBlock"

// 출력                           
typedef struct _t0441OutBlock
{
    char    tdtsunik            [  18];    char    _tdtsunik            ;    // [long  ,   18] 매매손익합계                    StartPos 0, Length 18
    char    cts_expcode         [   8];    char    _cts_expcode         ;    // [string,    8] CTS_종목번호                    StartPos 19, Length 8
    char    cts_medocd          [   1];    char    _cts_medocd          ;    // [string,    1] CTS_매매구분                    StartPos 28, Length 1
    char    tappamt             [  18];    char    _tappamt             ;    // [long  ,   18] 평가금액                        StartPos 30, Length 18
    char    tsunik              [  18];    char    _tsunik              ;    // [long  ,   18] 평가손익                        StartPos 49, Length 18
} t0441OutBlock, *LPt0441OutBlock;
#define NAME_t0441OutBlock     "t0441OutBlock"

// 출력1                          , occurs
typedef struct _t0441OutBlock1
{
    char    expcode             [   8];    char    _expcode             ;    // [string,    8] 종목번호                        StartPos 0, Length 8
    char    medosu              [   4];    char    _medosu              ;    // [string,    4] 구분                            StartPos 9, Length 4
    char    jqty                [  10];    char    _jqty                ;    // [long  ,   10] 잔고수량                        StartPos 14, Length 10
    char    cqty                [  10];    char    _cqty                ;    // [long  ,   10] 청산가능수량                    StartPos 25, Length 10
    char    pamt                [  10];    char    _pamt                ;    // [float , 10.2] 평균단가                        StartPos 36, Length 10
    char    mamt                [  18];    char    _mamt                ;    // [long  ,   18] 총매입금액                      StartPos 47, Length 18
    char    medocd              [   1];    char    _medocd              ;    // [string,    1] 매매구분                        StartPos 66, Length 1
    char    dtsunik             [  18];    char    _dtsunik             ;    // [long  ,   18] 매매손익                        StartPos 68, Length 18
    char    sysprocseq          [  10];    char    _sysprocseq          ;    // [long  ,   10] 처리순번                        StartPos 87, Length 10
    char    price               [   9];    char    _price               ;    // [float ,  9.2] 현재가                          StartPos 98, Length 9
    char    appamt              [  18];    char    _appamt              ;    // [long  ,   18] 평가금액                        StartPos 108, Length 18
    char    dtsunik1            [  18];    char    _dtsunik1            ;    // [long  ,   18] 평가손익                        StartPos 127, Length 18
    char    sunikrt             [  10];    char    _sunikrt             ;    // [float , 10.2] 수익율                          StartPos 146, Length 10
} t0441OutBlock1, *LPt0441OutBlock1;
#define NAME_t0441OutBlock1     "t0441OutBlock1"


///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션 체결/미체결 ( TUXCODE=T0434,HEADTYPE=D )

#define NAME_t0434     "t0434"

// 기본입력                       
typedef struct _t0434InBlock
{
	char    accno[11];    // [string,   11] 계좌번호                        StartPos 0, Length 11
	char    passwd[8];    // [string,    8] 비밀번호                        StartPos 11, Length 8
	char    expcode[8];    // [string,    8] 종목번호                        StartPos 19, Length 8
	char    chegb[1];    // [string,    1] 체결구분                        StartPos 27, Length 1
	char    sortgb[1];    // [string,    1] 정렬순서                        StartPos 28, Length 1
	char    cts_ordno[7];    // [string,    7] CTS_주문번호                    StartPos 29, Length 7
} t0434InBlock, * LPt0434InBlock;
#define NAME_t0434InBlock     "t0434InBlock"

// 출력                           
typedef struct _t0434OutBlock
{
	char    cts_ordno[7];    // [string,    7] CTS_주문번호                    StartPos 0, Length 7
} t0434OutBlock, * LPt0434OutBlock;
#define NAME_t0434OutBlock     "t0434OutBlock"

// 출력1                          , occurs
typedef struct _t0434OutBlock1
{
	char    ordno[7];    // [long  ,    7] 주문번호                        StartPos 0, Length 7
	char    orgordno[7];    // [long  ,    7] 원주문번호                      StartPos 7, Length 7
	char    medosu[10];    // [string,   10] 구분                            StartPos 14, Length 10
	char    ordgb[20];    // [string,   20] 유형                            StartPos 24, Length 20
	char    qty[9];    // [long  ,    9] 주문수량                        StartPos 44, Length 9
	char    price[9];    // [float ,  9.2] 주문가격                        StartPos 53, Length 9
	char    cheqty[9];    // [long  ,    9] 체결수량                        StartPos 62, Length 9
	char    cheprice[9];    // [float ,  9.2] 체결가격                        StartPos 71, Length 9
	char    ordrem[9];    // [long  ,    9] 미체결잔량                      StartPos 80, Length 9
	char    status[10];    // [string,   10] 상태                            StartPos 89, Length 10
	char    ordtime[8];    // [string,    8] 주문시간                        StartPos 99, Length 8
	char    ordermtd[10];    // [string,   10] 주문매체                        StartPos 107, Length 10
	char    expcode[8];    // [string,    8] 종목번호                        StartPos 117, Length 8
	char    rtcode[3];    // [string,    3] 사유코드                        StartPos 125, Length 3
	char    sysprocseq[10];    // [long  ,   10] 처리순번                        StartPos 128, Length 10
	char    hogatype[1];    // [string,    1] 호가타입                        StartPos 138, Length 1
} t0434OutBlock1, * LPt0434OutBlock1;
#define NAME_t0434OutBlock1     "t0434OutBlock1"


///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 계좌주문체결내역 조회 ( ENCRYPT,SERVICE=CFOAQ00600,HEADTYPE=B,CREATOR=정명기,CREDATE=2012/03/12 16:35:20 )


#define NAME_CFOAQ00600     "CFOAQ00600"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600InBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    InptPwd[8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
	char    FnoClssCode[2];    // [string,    2] 선물옵션분류코드                StartPos 49, Length 2
	char    PrdgrpCode[2];    // [string,    2] 상품군코드                      StartPos 51, Length 2
	char    PrdtExecTpCode[1];    // [string,    1] 체결구분                        StartPos 53, Length 1
	char    StnlnSeqTp[1];    // [string,    1] 정렬순서구분                    StartPos 54, Length 1
	char    CommdaCode[2];    // [string,    2] 통신매체코드                    StartPos 55, Length 2
} CFOAQ00600InBlock1, * LPCFOAQ00600InBlock1;
#define NAME_CFOAQ00600InBlock1     "CFOAQ00600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    InptPwd[8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
	char    FnoClssCode[2];    // [string,    2] 선물옵션분류코드                StartPos 49, Length 2
	char    PrdgrpCode[2];    // [string,    2] 상품군코드                      StartPos 51, Length 2
	char    PrdtExecTpCode[1];    // [string,    1] 체결구분                        StartPos 53, Length 1
	char    StnlnSeqTp[1];    // [string,    1] 정렬순서구분                    StartPos 54, Length 1
	char    CommdaCode[2];    // [string,    2] 통신매체코드                    StartPos 55, Length 2
} CFOAQ00600OutBlock1, * LPCFOAQ00600OutBlock1;
#define NAME_CFOAQ00600OutBlock1     "CFOAQ00600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAQ00600OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNm[40];    // [string,   40] 계좌명                          StartPos 5, Length 40
	char    FutsOrdQty[16];    // [long  ,   16] 선물주문수량                    StartPos 45, Length 16
	char    FutsExecQty[16];    // [long  ,   16] 선물체결수량                    StartPos 61, Length 16
	char    OptOrdQty[16];    // [long  ,   16] 옵션주문수량                    StartPos 77, Length 16
	char    OptExecQty[16];    // [long  ,   16] 옵션체결수량                    StartPos 93, Length 16
} CFOAQ00600OutBlock2, * LPCFOAQ00600OutBlock2;
#define NAME_CFOAQ00600OutBlock2     "CFOAQ00600OutBlock2"

// Out1(*EMPTY*)                  , occurs
typedef struct _CFOAQ00600OutBlock3
{
	char    OrdDt[8];    // [string,    8] 주문일                          StartPos 0, Length 8
	char    OrdNo[10];    // [long  ,   10] 주문번호                        StartPos 8, Length 10
	char    OrgOrdNo[10];    // [long  ,   10] 원주문번호                      StartPos 18, Length 10
	char    OrdTime[9];    // [string,    9] 주문시각                        StartPos 28, Length 9
	char    FnoIsuNo[12];    // [string,   12] 선물옵션종목번호                StartPos 37, Length 12
	char    IsuNm[40];    // [string,   40] 종목명                          StartPos 49, Length 40
	char    BnsTpNm[10];    // [string,   10] 매매구분                        StartPos 89, Length 10
	char    MrcTpNm[10];    // [string,   10] 정정취소구분명                  StartPos 99, Length 10
	char    FnoOrdprcPtnCode[2];    // [string,    2] 선물옵션호가유형코드            StartPos 109, Length 2
	char    FnoOrdprcPtnNm[40];    // [string,   40] 선물옵션호가유형명              StartPos 111, Length 40
	char    OrdPrc[13];    // [double, 13.2] 주문가                          StartPos 151, Length 13
	char    OrdQty[16];    // [long  ,   16] 주문수량                        StartPos 164, Length 16
	char    OrdTpNm[10];    // [string,   10] 주문구분명                      StartPos 180, Length 10
	char    ExecTpNm[10];    // [string,   10] 체결구분명                      StartPos 190, Length 10
	char    ExecPrc[13];    // [double, 13.2] 체결가                          StartPos 200, Length 13
	char    ExecQty[16];    // [long  ,   16] 체결수량                        StartPos 213, Length 16
	char    CtrctTime[9];    // [string,    9] 약정시각                        StartPos 229, Length 9
	char    CtrctNo[10];    // [long  ,   10] 약정번호                        StartPos 238, Length 10
	char    ExecNo[10];    // [long  ,   10] 체결번호                        StartPos 248, Length 10
	char    BnsplAmt[16];    // [long  ,   16] 매매손익금액                    StartPos 258, Length 16
	char    UnercQty[16];    // [long  ,   16] 미체결수량                      StartPos 274, Length 16
	char    UserId[16];    // [string,   16] 사용자ID                        StartPos 290, Length 16
	char    CommdaCode[2];    // [string,    2] 통신매체코드                    StartPos 306, Length 2
	char    CommdaCodeNm[40];    // [string,   40] 통신매체코드명                  StartPos 308, Length 40
} CFOAQ00600OutBlock3, * LPCFOAQ00600OutBlock3;
#define NAME_CFOAQ00600OutBlock3     "CFOAQ00600OutBlock3"


///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 일별 계좌손익내역 ( SERVICE=CFOEQ82600,HEADTYPE=B,CREATOR=황규석,CREDATE=2013/01/06 17:48:51 )


#define NAME_CFOEQ82600     "CFOEQ82600"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600InBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
	char    QryTp[1];    // [string,    1] 조회구분                        StartPos 49, Length 1
	char    StnlnSeqTp[1];    // [string,    1] 정렬순서구분                    StartPos 50, Length 1
	char    FnoBalEvalTpCode[1];    // [string,    1] 선물옵션잔고평가구분코드        StartPos 51, Length 1
} CFOEQ82600InBlock1, * LPCFOEQ82600InBlock1;
#define NAME_CFOEQ82600InBlock1     "CFOEQ82600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600OutBlock1
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    AcntNo[20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
	char    Pwd[8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
	char    QrySrtDt[8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
	char    QryEndDt[8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
	char    QryTp[1];    // [string,    1] 조회구분                        StartPos 49, Length 1
	char    StnlnSeqTp[1];    // [string,    1] 정렬순서구분                    StartPos 50, Length 1
	char    FnoBalEvalTpCode[1];    // [string,    1] 선물옵션잔고평가구분코드        StartPos 51, Length 1
} CFOEQ82600OutBlock1, * LPCFOEQ82600OutBlock1;
#define NAME_CFOEQ82600OutBlock1     "CFOEQ82600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ82600OutBlock2
{
	char    RecCnt[5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
	char    FutsAdjstDfamt[16];    // [long  ,   16] 선물정산차금                    StartPos 5, Length 16
	char    OptBnsplAmt[16];    // [long  ,   16] 옵션매매손익금액                StartPos 21, Length 16
	char    FnoCmsnAmt[16];    // [long  ,   16] 선물옵션수수료                  StartPos 37, Length 16
	char    PnlSumAmt[16];    // [long  ,   16] 손익합계금액                    StartPos 53, Length 16
	char    MnyinSumAmt[16];    // [long  ,   16] 입금합계금액                    StartPos 69, Length 16
	char    MnyoutSumAmt[16];    // [long  ,   16] 출금합계금액                    StartPos 85, Length 16
	char    AcntNm[40];    // [string,   40] 계좌명                          StartPos 101, Length 40
} CFOEQ82600OutBlock2, * LPCFOEQ82600OutBlock2;
#define NAME_CFOEQ82600OutBlock2     "CFOEQ82600OutBlock2"

// OutList(*EMPTY*)               , occurs
typedef struct _CFOEQ82600OutBlock3
{
	char    QryDt[8];    // [string,    8] 조회일                          StartPos 0, Length 8
	char    DpstgTotamt[16];    // [long  ,   16] 예탁총액                        StartPos 8, Length 16
	char    DpstgMny[16];    // [long  ,   16] 예탁현금                        StartPos 24, Length 16
	char    FnoMgn[16];    // [long  ,   16] 선물옵션증거금액                StartPos 40, Length 16
	char    FutsPnlAmt[16];    // [long  ,   16] 선물손익금액                    StartPos 56, Length 16
	char    OptBsnPnlAmt[16];    // [long  ,   16] 옵션매매손익금액                StartPos 72, Length 16
	char    OptEvalPnlAmt[16];    // [long  ,   16] 옵션평가손익금액                StartPos 88, Length 16
	char    CmsnAmt[16];    // [long  ,   16] 수수료                          StartPos 104, Length 16
	char    SumAmt1[16];    // [long  ,   16] 합계금액1                       StartPos 120, Length 16
	char    SumAmt2[16];    // [long  ,   16] 합계금액                        StartPos 136, Length 16
	char    PnlSumAmt[16];    // [long  ,   16] 손익합계금액                    StartPos 152, Length 16
	char    FutsBuyAmt[16];    // [long  ,   16] 선물매수금액                    StartPos 168, Length 16
	char    FutsSellAmt[16];    // [long  ,   16] 선물매도금액                    StartPos 184, Length 16
	char    OptBuyAmt[16];    // [long  ,   16] 옵션매수금액                    StartPos 200, Length 16
	char    OptSellAmt[16];    // [long  ,   16] 옵션매도금액                    StartPos 216, Length 16
	char    InAmt[16];    // [long  ,   16] 입금액                          StartPos 232, Length 16
	char    OutAmt[16];    // [long  ,   16] 출금액                          StartPos 248, Length 16
	char    EvalAmt[16];    // [long  ,   16] 평가금액                        StartPos 264, Length 16
	char    AddupEvalAmt[16];    // [long  ,   16] 합산평가금액                    StartPos 280, Length 16
	char    Amt2[16];    // [long  ,   16] 금액2                           StartPos 296, Length 16
} CFOEQ82600OutBlock3, * LPCFOEQ82600OutBlock3;
#define NAME_CFOEQ82600OutBlock3     "CFOEQ82600OutBlock3"


#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

