/*
 * FUN_004ca7b6 at 004ca7b6
 * undefined FUN_004ca7b6(void)
 * Address ranges: 004ca7b6-004ca80d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004ca7b6(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_006b6710;
  piVar2 = DAT_006b6710;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_006b6710 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_006b6710 >> 2;
}

