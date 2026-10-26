/*
 * FUN_00402770 at 00402770
 * undefined FUN_00402770(void)
 * Address ranges: 00402770-00402893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_00402770(HWND param_1,UINT param_2,ushort param_3,LPARAM param_4)

{
  int *piVar1;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_2 == 6) {
    SendMessageA(*(HWND *)(DAT_00410440 + 0x464),0x5a78,(uint)param_3,param_4);
    iVar3 = DAT_00410440;
    if (param_3 != 0) {
      puVar5 = (undefined4 *)(DAT_00410440 + 0x46c);
      *(undefined4 *)(DAT_00410440 + 0x460) = 1;
      LVar2 = CallWindowProcA((WNDPROC)*puVar5,param_1,6,(uint)param_3,param_4);
      if (*(int *)(DAT_00410440 + 8) == 2) {
        puVar5 = *(undefined4 **)(DAT_00410440 + 0x44c);
        puVar6 = *(undefined4 **)(DAT_00410440 + 0x448);
        for (iVar3 = 16000; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      else {
        FUN_00402be0(*(int *)(DAT_00410440 + 0x10) * *(int *)(DAT_00410440 + 0x14),0);
      }
      return LVar2;
    }
    piVar1 = (int *)(DAT_00410440 + 8);
    *(undefined4 *)(DAT_00410440 + 0x460) = 0;
    if (*piVar1 == 2) {
      puVar5 = *(undefined4 **)(iVar3 + 0x448);
      puVar6 = *(undefined4 **)(iVar3 + 0x44c);
      for (iVar4 = 16000; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
    }
  }
  LVar2 = CallWindowProcA(*(WNDPROC *)(DAT_00410440 + 0x46c),param_1,param_2,(uint)param_3,param_4);
  return LVar2;
}

