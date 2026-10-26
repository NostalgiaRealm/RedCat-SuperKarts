/*
 * __strcmpi at 00427c90
 * int __cdecl __strcmpi(char * _Str1, char * _Str2)
 * Address ranges: 00427c90-00427d1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __strcmpi  Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release
 */

/* Library Function - Single Match
    __strcmpi
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl __strcmpi(char *_Str1,char *_Str2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar7;
  void *in_ECX;
  void *this;
  void *extraout_ECX;
  uint uVar8;
  int iVar6;
  
  if (DAT_0043e588 == 0) {
    bVar4 = 0xff;
    do {
      do {
        cVar5 = '\0';
        if (bVar4 == 0) goto LAB_00427cde;
        bVar4 = *_Str2;
        _Str2 = _Str2 + 1;
        bVar3 = *_Str1;
        _Str1 = _Str1 + 1;
      } while (bVar3 == bVar4);
      bVar2 = bVar4 + 0xbf + (-((byte)(bVar4 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar3 = bVar3 + 0xbf;
      bVar4 = bVar3 + (-(bVar3 < 0x1a) & 0x20U) + 0x41;
    } while (bVar4 == bVar2);
    cVar5 = (bVar4 < bVar2) * -2 + '\x01';
LAB_00427cde:
    iVar6 = (int)cVar5;
  }
  else {
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') {
          return uVar7;
        }
        cVar5 = *_Str2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),cVar5);
        _Str2 = _Str2 + 1;
        cVar1 = *_Str1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),cVar1);
        _Str1 = _Str1 + 1;
      } while (cVar5 == cVar1);
      uVar8 = FUN_004255e3(in_ECX,uVar8);
      uVar7 = FUN_004255e3(this,uVar7);
      in_ECX = extraout_ECX;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar7 = (uint)((byte)uVar8 < (byte)uVar7);
    iVar6 = (1 - uVar7) - (uint)(uVar7 != 0);
  }
  return iVar6;
}

