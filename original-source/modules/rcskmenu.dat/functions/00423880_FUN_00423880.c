/*
 * FUN_00423880 at 00423880
 * undefined FUN_00423880(void)
 * Address ranges: 00423880-0042390c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423880(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_1c = &LAB_0042390d;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (param_1[0x4a] != 0) {
    cVar2 = (**(code **)(*param_1 + 0x4c))();
    if ((cVar2 != '\0') && ((char)param_1[0x4c] != '\0')) {
      FUN_0043f64c((int)param_1,&iStack_8);
      cVar2 = FUN_0042984c(CONCAT22(extraout_var,*(undefined2 *)(param_2 + 4)),iStack_8);
      if (cVar2 != '\0') {
        piVar1 = (int *)param_1[0x4a];
        cVar2 = FUN_00403088(piVar1,extraout_EDX,extraout_ECX);
        if (cVar2 != '\0') {
          (**(code **)(*piVar1 + 0xb0))();
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
      }
    }
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00423914;
  puStack_1c = (undefined1 *)0x42390c;
  FUN_00403b50(&iStack_8);
  return;
}

