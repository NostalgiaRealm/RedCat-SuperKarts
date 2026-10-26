/*
 * _TimerFunc@20 at 00407020
 * undefined __stdcall _TimerFunc@20(void)
 * Address ranges: 00407020-00407125
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _TimerFunc_20(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 local_18 [4];
  uint local_14;
  
                    /* 0x7020  35  _TimerFunc@20 */
  DAT_0040e884 = DAT_0040e884 + 1;
  iVar1 = DAT_0040e874;
  if (DAT_0040e884 == 1) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (*(char *)(iVar1 + 0x28) != '\0') {
        (**(code **)(**(int **)(iVar1 + 4) + 0x10))(*(int **)(iVar1 + 4),&local_14,local_18);
        if (((local_14 <= *(uint *)(iVar1 + 0x14)) ||
            (*(uint *)(iVar1 + 0x14) + *(int *)(iVar1 + 0xc) <= local_14)) &&
           (iVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x2c))
                              (*(int **)(iVar1 + 4),*(undefined4 *)(iVar1 + 0x14),
                               *(undefined4 *)(iVar1 + 0xc),&iStack_1c,&uStack_24,&iStack_20,
                               &uStack_28,0), iVar2 == 0)) {
          *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0xc);
          uVar3 = extraout_ECX;
          if (iStack_1c != 0) {
            FUN_00407130(extraout_ECX,uStack_24);
            uVar3 = extraout_ECX_00;
          }
          if (iStack_20 != 0) {
            FUN_00407130(uVar3,uStack_28);
          }
          uVar4 = *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0xc);
          *(uint *)(iVar1 + 0x14) = uVar4;
          if (*(uint *)(iVar1 + 0x10) <= uVar4) {
            *(uint *)(iVar1 + 0x14) = uVar4 - *(uint *)(iVar1 + 0x10);
          }
          (**(code **)(**(int **)(iVar1 + 4) + 0x4c))
                    (*(int **)(iVar1 + 4),iStack_1c,uStack_24,iStack_20,uStack_28);
        }
      }
    }
  }
  DAT_0040e884 = DAT_0040e884 + -1;
  return;
}

