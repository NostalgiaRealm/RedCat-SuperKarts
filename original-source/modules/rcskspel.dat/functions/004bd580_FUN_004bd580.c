/*
 * FUN_004bd580 at 004bd580
 * undefined FUN_004bd580(void)
 * Address ranges: 004bd580-004bd606
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bd580(int *param_1,short *param_2,int param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    while( true ) {
      if (param_3 < 1) {
        return local_8;
      }
      psVar5 = *(short **)param_1[7];
      if ((psVar5 == (short *)0x0) || (iVar3 = (*(int *)param_1[0xb] << 1) >> 1, iVar3 < 1)) break;
      psVar1 = param_2;
      iVar4 = iVar3;
      if (param_3 < iVar3) {
        iVar3 = param_3;
        iVar4 = param_3;
      }
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *psVar1 = *psVar5;
        psVar5 = psVar5 + 1;
        psVar1 = psVar1 + 1;
      }
      local_8 = local_8 + iVar4;
      param_3 = param_3 - iVar4;
      param_2 = param_2 + iVar4;
      FUN_004bdca8(iVar4);
    }
    sVar2 = (**(code **)(*param_1 + 0x14))();
    if (sVar2 == -1) break;
    *param_2 = sVar2;
    param_2 = param_2 + 1;
    local_8 = local_8 + 1;
    param_3 = param_3 + -1;
  }
  return local_8;
}

