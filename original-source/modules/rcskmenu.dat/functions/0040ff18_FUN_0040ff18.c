/*
 * FUN_0040ff18 at 0040ff18
 * undefined __register FUN_0040ff18(int * param_1, int * param_2)
 * Address ranges: 0040ff18-0040ffac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ff18(int *param_1,int *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_130;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  byte local_118 [256];
  int local_18;
  int local_14;
  undefined1 local_10;
  int local_c;
  undefined1 local_8;
  
  puStack_128 = &stack0xfffffffc;
  local_18 = 0;
  puStack_12c = &LAB_0040ffad;
  uStack_130 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_130;
  if (param_1[1] == 0) {
    FUN_00402df8(*param_1,local_118);
    FUN_00403d74(param_2,local_118);
  }
  else {
    puStack_128 = &stack0xfffffffc;
    FUN_00403088((int *)param_1[1],&local_18,0);
    local_14 = local_18;
    local_10 = 0xb;
    local_c = FUN_0040fed8((int)param_1);
    local_8 = 0;
    FUN_00408a5c((byte *)"%s[%d]",&local_14,1,param_2);
  }
  *in_FS_OFFSET = uStack_130;
  puStack_128 = &LAB_0040ffb4;
  puStack_12c = (undefined1 *)0x40ffac;
  FUN_00403b50(&local_18);
  return;
}

