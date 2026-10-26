/*
 * FUN_00409b30 at 00409b30
 * undefined FUN_00409b30(void)
 * Address ranges: 00409b30-00409c36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00409b30(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_c [2];
  undefined4 local_4;
  
  iVar1 = FUN_00411410(param_1,&DAT_00505904);
  if ((0 < iVar1) && (iVar5 = 0, 0 < iVar1)) {
    piVar4 = &DAT_00505904;
    iVar3 = DAT_0067ee20;
    do {
      if (*piVar4 != param_2) {
        iVar2 = *piVar4 * 0xd0;
        local_c[0] = *(undefined4 *)(*(int *)(iVar2 + 0xc + iVar3) * 0xa9 + DAT_006a5c38 + 0x50);
        local_4 = *(undefined4 *)(DAT_006a5c38 + *(int *)(iVar2 + 0xc + iVar3) * 0xa9 + 0x58);
        iVar2 = FUN_00401320(param_2,local_c);
        iVar3 = DAT_0067ee20;
        if (((iVar2 < 0x400) || (0xc00 < iVar2)) &&
           (*(float *)(*piVar4 * 0xd0 + 0xa4 + DAT_0067ee20) <
            *(float *)(param_2 * 0xd0 + 0xa4 + DAT_0067ee20))) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < iVar1);
  }
  return 0;
}

