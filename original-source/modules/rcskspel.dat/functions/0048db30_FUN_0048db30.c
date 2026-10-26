/*
 * FUN_0048db30 at 0048db30
 * undefined FUN_0048db30(void)
 * Address ranges: 0048db30-0048dc2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0048dbd3) */
/* WARNING: Removing unreachable block (ram,0x0048dbd9) */
/* WARNING: Removing unreachable block (ram,0x0048dbef) */
/* WARNING: Removing unreachable block (ram,0x0048dbf1) */
/* WARNING: Removing unreachable block (ram,0x0048dbf3) */

void __fastcall FUN_0048db30(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iStack_8;
  
  iStack_8 = (**(code **)*param_1)();
  iVar3 = iStack_8;
  if (0 < iStack_8) {
    do {
      FUN_0048d460();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_1[1] + 4) + iVar3;
      if (*(char *)(iVar1 + 0x11a0) != '\0') {
        (&DAT_00504000)[*(int *)(*(int *)(iVar1 + 0x1180) * 0xd0 + 0x10 + DAT_0067ee20) * 0x11c] = 0
        ;
        puVar2 = (undefined4 *)(**(code **)(*param_1 + 8))();
        puVar4 = (undefined4 *)(*(int *)(param_1[1] + 4) + iVar3);
        for (iVar1 = 0x46c; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar4 = puVar4 + 1;
        }
        *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x11b0;
      }
      iVar3 = iVar3 + 0x11b0;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
  }
  return;
}

