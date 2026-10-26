/*
 * FUN_004102f4 at 004102f4
 * undefined __register FUN_004102f4(int * param_1, int * param_2)
 * Address ranges: 004102f4-004103f0;00410406-0041040c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004102f4(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  
  puStack_24 = (undefined1 *)0x410311;
  FUN_00403ba4(param_2,(undefined4 *)param_1[5]);
  puStack_24 = (undefined1 *)0x41031d;
  piVar2 = (int *)FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  if ((*param_2 == 0) && (piVar2 != (int *)0x0)) {
    puStack_24 = (undefined1 *)0x410340;
    iVar3 = FUN_004030cc(*piVar2);
    if (iVar3 != 0) {
      puStack_24 = (undefined1 *)0x410352;
      iVar3 = FUN_004030cc(*piVar2);
      puStack_24 = (undefined1 *)0x410357;
      iVar3 = FUN_0040d254(iVar3);
      if ((iVar3 != 0) && (*(short *)(iVar3 + 8) != 0)) {
        puStack_24 = (undefined1 *)0x410378;
        puVar4 = (undefined4 *)FUN_00402714((int)*(short *)(iVar3 + 8) << 2);
        puStack_28 = &LAB_004103f1;
        uStack_2c = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_2c;
        puStack_24 = &stack0xfffffffc;
        iVar5 = FUN_004030cc(*piVar2);
        FUN_0040d32c(iVar5,puVar4);
        iVar3 = (int)*(short *)(iVar3 + 8);
        if (-1 < iVar3 + -1) {
          iVar5 = 0;
          do {
            puVar1 = (undefined4 *)puVar4[iVar5];
            if (**(char **)*puVar1 == '\a') {
              piVar6 = (int *)FUN_0040d380(piVar2,(undefined4 *)puVar4[iVar5]);
              if (piVar6 == param_1) {
                FUN_00403d74(param_1 + 5,(byte *)((int)puVar1 + 0x1a));
              }
            }
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        *in_FS_OFFSET = uStack_2c;
        puStack_24 = &DAT_004103f8;
        puStack_28 = (undefined1 *)0x4103f0;
        FUN_0040272c((int)puVar4);
        return;
      }
    }
  }
  return;
}

