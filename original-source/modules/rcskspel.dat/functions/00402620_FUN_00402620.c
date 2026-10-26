/*
 * FUN_00402620 at 00402620
 * undefined FUN_00402620(void)
 * Address ranges: 00402620-00402794
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402620(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00505048;
  if ((param_2 == DAT_0053be28) && (iVar2 = DAT_00505044, DAT_0053b9f4 == 0)) {
    iVar2 = DAT_00505040;
  }
  iVar3 = DAT_00508610;
  if (DAT_00508610 < 0xf) {
    piVar1 = &DAT_00503ef0 + DAT_00508610 * 0x47;
    do {
      if (*piVar1 == -1) break;
      piVar1 = piVar1 + 0x47;
      iVar3 = iVar3 + 1;
    } while ((int)piVar1 < 0x504f94);
  }
  if ((&DAT_00503ef0)[iVar3 * 0x47] == -1) {
    iVar4 = 0;
    if (DAT_00508610 < 0xf) {
      piVar1 = (int *)(&DAT_00503ef8 + DAT_00508610 * 0x11c);
      do {
        if (*piVar1 == param_2) {
          iVar4 = iVar4 + 1;
        }
        piVar1 = piVar1 + 0x47;
      } while ((int)piVar1 < 0x504f9c);
    }
    if (iVar4 < iVar2) {
      (&DAT_00503ef0)[iVar3 * 0x47] = param_1;
      (&DAT_00503ef4)[iVar3 * 0x47] = 3;
      *(int *)(&DAT_00503ef8 + iVar3 * 0x11c) = param_2;
      *(undefined4 *)(&DAT_00503f24 + iVar3 * 0x11c) = 6;
      FUN_0041f7e0(param_2);
      iVar3 = param_1 * 0xd0;
      *(uint *)(iVar3 + 4 + DAT_0067ee20) = *(uint *)(iVar3 + 4 + DAT_0067ee20) | 3;
      *(undefined4 *)(iVar3 + 0x38 + DAT_0067ee20) =
           *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x38 + DAT_0067ee20);
      FUN_00412c50(param_1,1);
      iVar2 = FUN_00407cb0(param_1);
      if (-1 < iVar2) {
        iVar2 = FUN_00407cb0(param_1);
        *(uint *)(&DAT_00505114 + iVar2 * 0x24) = *(uint *)(&DAT_00505114 + iVar2 * 0x24) | 0x4000;
      }
      *(code **)(iVar3 + 0x54 + DAT_0067ee20) = FUN_00402260;
      *(undefined4 *)(iVar3 + 0x48 + DAT_0067ee20) = 0;
      *(code **)(iVar3 + 0x58 + DAT_0067ee20) = FUN_004170a0;
      return 1;
    }
  }
  return 0;
}

