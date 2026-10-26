/*
 * FUN_004015a6 at 004015a6
 * undefined __cdecl FUN_004015a6(byte * param_1)
 * Address ranges: 004015a6-0040166d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004015a6(byte *param_1)

{
  FILE *pFVar1;
  byte local_324 [800];
  
  if (DAT_0043846c == 1) {
    if (DAT_00438470 == 0) {
      pFVar1 = (FILE *)FUN_0041f4c6(s_debug_txt_0042c4d8,&DAT_0042c4d4);
      if (pFVar1 != (FILE *)0x0) {
        FUN_0041f64a(local_324,param_1,(undefined4 *)&stack0x00000008);
        FUN_0041f618((int *)pFVar1,local_324);
        FUN_0041f368(pFVar1);
      }
    }
    else if (DAT_00438470 == 1) {
      OutputDebugStringA((LPCSTR)local_324);
    }
  }
  return;
}

