/*
 * FUN_0044f4e8 at 0044f4e8
 * undefined FUN_0044f4e8(void)
 * Address ranges: 0044f4e8-0044f58b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f4e8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar2;
  int *in_FS_OFFSET;
  byte **ppbVar3;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *puStack_10;
  byte *pbStack_c;
  undefined4 uStack_8;
  
  puStack_1c = &stack0xfffffffc;
  pbStack_c = (byte *)0x0;
  puStack_10 = (undefined4 *)0x0;
  puStack_20 = &LAB_0044f58c;
  puStack_24 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&puStack_24;
  ppbVar3 = &pbStack_c;
  uStack_8 = param_3;
  (**(code **)*param_1)(param_1,param_2,param_3,ppbVar3,0);
  iVar1 = FUN_00403dd0((int)pbStack_c);
  iVar2 = extraout_ECX;
  if (((2 < iVar1) && (*pbStack_c == 0x30)) && ((pbStack_c[1] == 0x58 || (pbStack_c[1] == 0x78)))) {
    FUN_00403fd8((int)pbStack_c,3,0x7fffffff,(int *)&puStack_10);
    FUN_00403e1c((int *)&pbStack_c,(undefined4 *)&DAT_0044f5a8,puStack_10);
    iVar2 = extraout_ECX_00;
  }
  FUN_00407fcc(pbStack_c,param_4,iVar2);
  *in_FS_OFFSET = (int)ppbVar3;
  puStack_24 = &LAB_0044f593;
  FUN_00403b74((int *)&puStack_10,2);
  return;
}

