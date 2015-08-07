#ifndef __SESSION_OBJ_HPP__
#define __SESSION_OBJ_HPP__

#include "ObjAllocator.hpp"
#include "Public.hpp"
#include "CacheTime.hpp"

using namespace ServerLib;

class CSessionObj : public CCacheTime
{
private:
    TNetHead_V2 m_stNetHead; // ���Կͻ��˵�socket������Ϣ��ע�����е���Ч�ֶζ��������ֽ����
    unsigned short m_unValue; // �������ݣ���NetHead�е�sockfdһ���ʶ���session
    bool m_bActive; // ��session����Ƿ���active״̬���������ʱ��Ϊactive״̬���ͷŽ��ʱ��Ϊ��active״̬
    int m_uiUin;

public:
    CSessionObj();
    virtual ~CSessionObj();

public:
    int Create(TNetHead_V2& stNetHead, const unsigned short unValue);
    void SetActive(bool bActive);

public:
    void SetUin(const unsigned int uiUin) {m_uiUin = uiUin;};
    unsigned int GetUin() {return m_uiUin;};

public:
    TNetHead_V2* GetNetHead();
    bool IsActive();
    unsigned int GetSessionFD() const;
    unsigned short GetValue() const;
    void GetSockCreatedTime(char* pszTime, unsigned int uiBufLen);
    void GetMsgCreatedTime(char* pszTime, unsigned int uiBufLen);

    const char* GetClientIP();
};

#endif // __SESSION_OBJ_HPP__
