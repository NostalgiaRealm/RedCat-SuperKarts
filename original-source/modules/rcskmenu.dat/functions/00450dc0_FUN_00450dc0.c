/*
 * FUN_00450dc0 at 00450dc0
 * undefined __register FUN_00450dc0(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 00450dc0-00450e63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450dc0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_2 + 0x474) == 0) {
    FUN_004507f8(param_1,-1,param_3);
    *(char *)(param_1 + 0x10b) = (char)param_3;
  }
  else {
    FUN_004508a8(param_1,*(int *)(param_2 + 0x47c),*(undefined4 *)(param_2 + 0x428),
                 *(char *)(param_2 + 0x41c),(char)param_3,(undefined4 *)(param_2 + 0x15),
                 (int *)(param_2 + 0x444),*(int *)(param_2 + 8));
    if ((char)param_1[0x107] == '\0') {
      FUN_0040282c(*(undefined4 **)(param_2 + 0x440),(undefined4 *)param_1[0x110],
                   *(uint *)(param_1[3] + 0x14));
    }
    else {
      iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x14);
      *(int *)(param_1[3] + 0x14) = iVar1;
      puVar2 = (undefined4 *)FUN_00402714(iVar1);
      param_1[0x110] = (int)puVar2;
      FUN_0040282c(*(undefined4 **)(param_2 + 0x440),puVar2,*(uint *)(param_1[3] + 0x14));
    }
  }
  return;
}

