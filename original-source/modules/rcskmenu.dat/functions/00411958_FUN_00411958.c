/*
 * FUN_00411958 at 00411958
 * undefined __register FUN_00411958(int * param_1, int * param_2, int param_3)
 * Address ranges: 00411958-004119fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411958(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int local_14;
  
  if (param_3 == 0) {
    puStack_28 = (undefined1 *)0x411977;
    FUN_004118a4(param_2,0);
    puStack_28 = (undefined1 *)0x41197f;
    param_3 = FUN_004118b0(param_2);
  }
  local_14 = param_3;
  if (0xf000 < param_3) {
    local_14 = 0xf000;
  }
  puStack_28 = (undefined1 *)0x4119a0;
  iVar1 = FUN_00402714(local_14);
  puStack_2c = &LAB_004119fb;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  for (; param_3 != 0; param_3 = param_3 - iVar2) {
    iVar2 = param_3;
    if (local_14 < param_3) {
      iVar2 = local_14;
    }
    FUN_004118e8(param_2,iVar1,iVar2);
    FUN_00411920(param_1,iVar1,iVar2);
  }
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_00411a02;
  puStack_2c = (undefined1 *)0x4119fa;
  FUN_0040272c(iVar1);
  return;
}

