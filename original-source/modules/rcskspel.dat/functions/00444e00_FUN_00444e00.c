/*
 * FUN_00444e00 at 00444e00
 * undefined FUN_00444e00(void)
 * Address ranges: 00444e00-00445031
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444e00(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int local_40;
  int *local_3c;
  int local_34;
  int local_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd650;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00444bd0();
  FUN_00446170();
  FUN_004463b0();
  FUN_004afce0(s____counting_paths_004ef290);
  puVar2 = &DAT_0053f4f8;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 0x24;
  } while ((int)puVar2 < 0x53f660);
  FUN_004afce0(s____inactivate_them_004ef2a4);
  local_40 = 0;
  if (0 < DAT_00543760) {
    local_3c = &DAT_0053f668;
    do {
      iVar3 = FUN_00444ba0(local_40);
      (&DAT_0053f998)[iVar3 * 0xd0] = 0;
      local_3c[0xcd] = -1;
      iVar3 = *local_3c;
      cVar1 = FUN_00446b80(iVar3);
      if (cVar1 == '\0') {
        if (*(code **)(&DAT_004ef048 + iVar3 * 0x14) != (code *)0x0) {
          (**(code **)(&DAT_004ef048 + iVar3 * 0x14))(local_40);
        }
      }
      else {
        iVar4 = iVar3;
        FUN_00446170(iVar3);
        iVar4 = FUN_004461e0(iVar4);
        FUN_0040b4f0(0);
        FUN_00412870(iVar4,0,0xffffffff);
        local_4 = 0;
        FUN_0040b4f0(0);
        FUN_00412870(iVar4 + 0x10,0,0xffffffff);
        local_4 = 1;
        iVar4 = FUN_00445e00();
        puVar2 = &DAT_004d2404;
        if (*(undefined1 **)(iVar4 + 4) != (undefined1 *)0x0) {
          puVar2 = *(undefined1 **)(iVar4 + 4);
        }
        iVar4 = FUN_00445df0();
        puVar5 = *(undefined1 **)(iVar4 + 4);
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_004d2404;
        }
        FUN_004afce0(s___pathtype__d___s___s__is_dynami_004ef2b8,iVar3,puVar5,puVar2);
        local_4 = 0xffffffff;
        if (local_24 != 0) {
          cVar1 = *(char *)(local_24 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)(local_24 + -1));
          }
          else {
            *(char *)(local_24 + -1) = cVar1 + -1;
          }
        }
        local_24 = 0;
        if (local_34 != 0) {
          cVar1 = *(char *)(local_34 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150(local_34 + -1);
          }
          else {
            *(char *)(local_34 + -1) = cVar1 + -1;
          }
        }
        local_34 = 0;
        FUN_00446bf0(local_40);
      }
      local_40 = local_40 + 1;
      local_3c = local_3c + 0xd0;
    } while (local_40 < DAT_00543760);
  }
  FUN_004afce0(s____done_initializing_3d_paths_004ef2dc);
  ExceptionList = local_c;
  return;
}

