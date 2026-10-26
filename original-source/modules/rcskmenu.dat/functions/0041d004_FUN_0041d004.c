/*
 * FUN_0041d004 at 0041d004
 * undefined __register FUN_0041d004(int * param_1)
 * Address ranges: 0041d004-0041d060
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d004(int *param_1)

{
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  
  if ((*(char *)((int)param_1 + 0x2a) == '\0') || (*(char *)((int)param_1 + 0x29) == '\0')) {
    iVar1 = param_1[8];
    if (*(int *)(iVar1 + 0xc) != 0) {
      FUN_0041bae0(*(int *)(iVar1 + 0xc));
      DeleteObject(*(HGDIOBJ *)(iVar1 + 0xc));
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    FUN_0041cf04((int)param_1);
    FUN_0041cf14((int)param_1);
    uVar2 = FUN_0041ce40(param_1);
    BVar3 = FUN_0041c5e4(*(HPALETTE *)(iVar1 + 8),*(HPALETTE *)(iVar1 + 0x10),uVar2);
    *(BOOL *)(iVar1 + 0xc) = BVar3;
    *(undefined1 *)((int)param_1 + 0x2a) = 1;
    *(undefined1 *)((int)param_1 + 0x29) = 1;
  }
  return;
}

