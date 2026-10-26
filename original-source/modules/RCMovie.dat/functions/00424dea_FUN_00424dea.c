/*
 * FUN_00424dea at 00424dea
 * undefined __stdcall FUN_00424dea(void)
 * Address ranges: 00424dea-00425047
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424dea(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_4;
  
  DAT_0043e480 = 0;
  DAT_00437a38 = 0xffffffff;
  DAT_00437a28 = 0xffffffff;
  _Str1 = (uint *)FUN_00426550("TZ");
  if (_Str1 == (uint *)0x0) {
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_0043e488);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_00437990 = (void *)(DAT_0043e488 * 0x3c);
    DAT_0043e480 = 1;
    if (DAT_0043e4ce != 0) {
      DAT_00437990 = (void *)((int)DAT_00437990 + DAT_0043e4dc * 0x3c);
    }
    if ((DAT_0043e522 == 0) || (DAT_0043e530 == 0)) {
      DAT_00437994 = 0;
      _DAT_00437998 = 0;
    }
    else {
      DAT_00437994 = 1;
      _DAT_00437998 = (DAT_0043e530 - DAT_0043e4dc) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_0043e598,0x220,(LPCWSTR)&DAT_0043e48c,-1,PTR_DAT_00437a1c,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 == 0) || (local_4 != 0)) {
      *PTR_DAT_00437a1c = 0;
    }
    else {
      PTR_DAT_00437a1c[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_0043e598,0x220,(LPCWSTR)&DAT_0043e4e0,-1,PTR_DAT_00437a20,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 != 0) && (local_4 == 0)) {
      PTR_DAT_00437a20[0x3f] = 0;
      return;
    }
  }
  else {
    if ((char)*_Str1 == '\0') {
      return;
    }
    if ((DAT_0043e534 != (uint *)0x0) &&
       (iVar4 = _strcmp((char *)_Str1,(char *)DAT_0043e534), iVar4 == 0)) {
      return;
    }
    FUN_0041fd93(DAT_0043e534);
    sVar5 = _strlen((char *)_Str1);
    DAT_0043e534 = _malloc(sVar5 + 1);
    if (DAT_0043e534 == (uint *)0x0) {
      return;
    }
    FUN_0041f7a0(DAT_0043e534,_Str1);
    _strncpy(PTR_DAT_00437a1c,(char *)_Str1,3);
    _Source = (uint *)((int)_Str1 + 3);
    PTR_DAT_00437a1c[3] = 0;
    cVar1 = *(char *)_Source;
    if (cVar1 == '-') {
      _Source = _Str1 + 1;
    }
    iVar4 = FUN_0041fbf0(this,(byte *)_Source);
    DAT_00437990 = (void *)(iVar4 * 0xe10);
    for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        _Source = (uint *)((int)_Source + 1)) {
    }
    if ((char)*_Source == ':') {
      _Source = (uint *)((int)_Source + 1);
      iVar4 = FUN_0041fbf0(DAT_00437990,(byte *)_Source);
      DAT_00437990 = (void *)((int)DAT_00437990 + iVar4 * 0x3c);
      for (; ('/' < (char)*_Source && ((char)*_Source < ':')); _Source = (uint *)((int)_Source + 1))
      {
      }
      if ((char)*_Source == ':') {
        _Source = (uint *)((int)_Source + 1);
        iVar4 = FUN_0041fbf0(DAT_00437990,(byte *)_Source);
        DAT_00437990 = (void *)((int)DAT_00437990 + iVar4);
        for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
            _Source = (uint *)((int)_Source + 1)) {
        }
      }
    }
    if (cVar1 == '-') {
      DAT_00437990 = (void *)-(int)DAT_00437990;
    }
    DAT_00437994 = (int)(char)*_Source;
    if (DAT_00437994 != 0) {
      _strncpy(PTR_DAT_00437a20,(char *)_Source,3);
      PTR_DAT_00437a20[3] = 0;
      return;
    }
  }
  *PTR_DAT_00437a20 = 0;
  return;
}

