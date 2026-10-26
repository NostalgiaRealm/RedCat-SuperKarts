/*
 * FUN_004b3560 at 004b3560
 * undefined FUN_004b3560(void)
 * Address ranges: 004b3560-004b3636
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004b3560(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_4;
  
  uVar3 = 0;
  FUN_004afce0(s__s__d__004fffc4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x3de);
  FUN_004afce0(s_y____d___xsize____d___pitch____d_004fffa0,param_3,param_4,param_5);
  do {
    bVar1 = *(byte *)(param_3 * param_5 + param_2 + uVar3);
    uStack_4._0_3_ = CONCAT12(bVar1,(undefined2)uStack_4);
    if ((bVar1 & 0xc0) == 0xc0) {
      iVar2 = FUN_004b34c0(param_2,uVar3,param_3,param_4 - uVar3,param_4);
      uStack_4 = CONCAT13((char)iVar2,(undefined3)uStack_4) | 0xc0000000;
      FUN_004bf31b((int)&uStack_4 + 3,1,1,param_1);
      FUN_004bf31b((int)&uStack_4 + 2,1,1,param_1);
      uVar3 = uVar3 + iVar2;
    }
    else {
      FUN_004bf31b((int)&uStack_4 + 2,1,1,param_1);
      uVar3 = uVar3 + 1;
    }
  } while (uVar3 < param_4);
  FUN_004afce0(s__s__d__004fffc4,s_C__libraries_dxdraw_Rcpcx_cpp_004fff00,0x3ee);
  return uVar3;
}

