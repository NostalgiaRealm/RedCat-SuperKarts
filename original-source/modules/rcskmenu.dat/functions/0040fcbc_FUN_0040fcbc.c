/*
 * FUN_0040fcbc at 0040fcbc
 * undefined __register FUN_0040fcbc(int * param_1, int * param_2)
 * Address ranges: 0040fcbc-0040fd71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fcbc(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  undefined1 *puStack_124;
  int local_118;
  undefined1 local_114;
  byte *local_110;
  undefined1 local_10c;
  byte local_108 [256];
  int local_8;
  
  puStack_124 = &stack0xfffffffc;
  local_8 = 0;
  puStack_128 = &LAB_0040fd72;
  puStack_12c = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_12c;
  if (param_2 == (int *)0x0) {
    FUN_00403be8(&local_8,0x40fd88);
  }
  else {
    puStack_124 = &stack0xfffffffc;
    FUN_00402df8(*param_2,local_108);
    FUN_00403d74(&local_8,local_108);
  }
  local_118 = local_8;
  local_114 = 0xb;
  FUN_00402df8(*param_1,local_108);
  local_110 = local_108;
  local_10c = 4;
  uVar2 = 1;
  uVar1 = FUN_0040ad5c((int)&DAT_0040774c,'\x01',(undefined4 *)PTR_PTR_0047c7a8,1,&local_118);
  FUN_00403604(uVar1);
  *in_FS_OFFSET = uVar2;
  puStack_12c = &LAB_0040fd79;
  FUN_00403b50(&local_8);
  return;
}

