/*
 * FUN_0040b820 at 0040b820
 * PCNZCH __register FUN_0040b820(byte * param_1, char * param_2)
 * Address ranges: 0040b820-0040b8be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

PCNZCH FUN_0040b820(byte *param_1,char *param_2)

{
  int iVar1;
  uint cchCount1;
  char *lpString1;
  undefined4 uVar2;
  int iVar3;
  
  if ((((param_1 != (byte *)0x0) && (*param_1 != 0)) && (param_2 != (char *)0x0)) &&
     (*param_2 != '\0')) {
    iVar1 = FUN_00408340((char *)param_1);
    cchCount1 = FUN_00408340(param_2);
    for (lpString1 = FUN_004084d4((char *)param_1,param_2);
        (lpString1 != (PCNZCH)0x0 && (cchCount1 <= (uint)(iVar1 - ((int)lpString1 - (int)param_1))))
        ; lpString1 = FUN_004084d4(lpString1 + 1,param_2)) {
      uVar2 = FUN_0040b594(param_1,(int)lpString1 - (int)param_1);
      if (((char)uVar2 != '\x02') &&
         (iVar3 = CompareStringA(0x400,0,lpString1,cchCount1,param_2,cchCount1), iVar3 == 2)) {
        return lpString1;
      }
      if ((char)uVar2 == '\x01') {
        lpString1 = lpString1 + 1;
      }
    }
  }
  return (PCNZCH)0x0;
}

