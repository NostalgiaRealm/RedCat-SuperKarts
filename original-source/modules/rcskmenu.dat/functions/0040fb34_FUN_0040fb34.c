/*
 * FUN_0040fb34 at 0040fb34
 * undefined __register FUN_0040fb34(int param_1, int param_2)
 * Address ranges: 0040fb34-0040fbd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fb34(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_14;
  
  if (param_2 != *(int *)(param_1 + 4)) {
    if (param_2 < 0) {
      FUN_0040fb10();
    }
    iVar1 = param_2 + 0x1f;
    if (iVar1 < 0) {
      iVar1 = param_2 + 0x3e;
    }
    uVar3 = (iVar1 >> 5) << 2;
    iVar1 = *(int *)(param_1 + 4) + 0x1f;
    if (iVar1 < 0) {
      iVar1 = *(int *)(param_1 + 4) + 0x3e;
    }
    uVar2 = (iVar1 >> 5) << 2;
    if (uVar2 != uVar3) {
      local_14 = (undefined4 *)0x0;
      if (uVar3 != 0) {
        local_14 = (undefined4 *)FUN_00402714(uVar3);
        FUN_00402b54(local_14,uVar3,0);
      }
      if (uVar2 != 0) {
        if (local_14 != (undefined4 *)0x0) {
          uVar3 = FUN_0040fb28(uVar2,uVar3);
          FUN_0040282c(*(undefined4 **)(param_1 + 8),local_14,uVar3);
        }
        FUN_0040272c(*(int *)(param_1 + 8));
      }
      *(undefined4 **)(param_1 + 8) = local_14;
    }
    *(int *)(param_1 + 4) = param_2;
  }
  return;
}

