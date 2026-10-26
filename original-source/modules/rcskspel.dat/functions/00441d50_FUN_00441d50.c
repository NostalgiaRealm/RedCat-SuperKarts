/*
 * FUN_00441d50 at 00441d50
 * undefined FUN_00441d50(void)
 * Address ranges: 00441d50-00441e4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00441d50(float param_1,float param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar4 = (int)param_2 * 0xd0;
  if (*(int *)(*(int *)(iVar4 + 0x24 + DAT_0067ee20) * 0x50 + 4 + DAT_00680ae0) == 0x34) {
    cVar1 = FUN_00415be0(param_2);
    if (cVar1 == '\0') {
      iVar3 = *(int *)(DAT_00680b28 + 0xf0 + *(int *)(iVar4 + 0x1c + DAT_0067ee20) * 0x984);
      if (iVar3 == 0x3d) {
        local_4 = DAT_0053d2a8;
        param_2 = DAT_0053d2ac;
      }
      else if (iVar3 == 0x3e) {
        local_4 = DAT_0053d2a0;
        param_2 = DAT_0053d2a4;
      }
      else {
        local_4 = param_1;
        if (iVar3 == 0x3f) {
          local_4 = DAT_0053d298;
          param_2 = DAT_0053d29c;
        }
      }
      iVar3 = 0;
      do {
        iVar2 = FUN_004906b0(iVar3);
        iVar3 = iVar3 + 1;
        *(float *)(DAT_006a5c38 + iVar2 + 0x60 + iVar2 * 0xa8) =
             param_2 + *(float *)(DAT_006a5c38 + iVar2 + 0x60 + iVar2 * 0xa8);
      } while (iVar3 < 4);
      *(float *)(iVar4 + 0xa4 + DAT_0067ee20) = local_4 * *(float *)(iVar4 + 0xa4 + DAT_0067ee20);
    }
  }
  return;
}

