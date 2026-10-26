/*
 * FUN_0046daa4 at 0046daa4
 * undefined __register FUN_0046daa4(int * param_1)
 * Address ranges: 0046daa4-0046dc31
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046daa4(int *param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  MCIERROR MVar8;
  int local_14;
  undefined4 local_10;
  
  FUN_0046d260((int)param_1);
  param_1[0xb4] = 0;
  if (*(char *)((int)param_1 + 0x2d6) == '\0') {
    param_1[0xb4] = 2;
  }
  else {
    if ((char)param_1[0xb5] != '\0') {
      param_1[0xb4] = 2;
    }
    *(undefined1 *)((int)param_1 + 0x2d6) = 0;
  }
  if (*(char *)((int)param_1 + 0x2d7) != '\0') {
    if (*(char *)((int)param_1 + 0x2d5) != '\0') {
      param_1[0xb4] = param_1[0xb4] | 1;
    }
    *(undefined1 *)((int)param_1 + 0x2d7) = 0;
  }
  uVar3 = param_1[0xb4];
  cVar1 = FUN_0046e5d8((int)param_1);
  if (cVar1 == '\n') {
    cVar1 = FUN_0046e554((int)param_1);
    if (cVar1 == '\x02') {
      FUN_0046e598((int)param_1);
      uVar3 = FUN_00455928();
      uVar4 = FUN_0046e50c((int)param_1);
      if ((uVar3 & 0xff) == uVar4) {
        uVar5 = FUN_0046e50c((int)param_1);
        iVar6 = FUN_0046e068((int)param_1,uVar5);
        FUN_0046e0b8((int)param_1,iVar6);
      }
      else {
        FUN_0046e598((int)param_1);
        bVar2 = FUN_00455928();
        iVar6 = FUN_0046e068((int)param_1,bVar2 + 1);
        FUN_0046e0b8((int)param_1,iVar6);
      }
      FUN_0046d694(param_1);
      *(undefined1 *)((int)param_1 + 0x292) = 0;
      return;
    }
    FUN_0046e598((int)param_1);
    uVar4 = FUN_00455928();
    uVar7 = FUN_0046e50c((int)param_1);
    if ((uVar4 & 0xff) == uVar7) {
      uVar5 = FUN_0046e50c((int)param_1);
      local_10 = FUN_0046e068((int)param_1,uVar5);
    }
    else {
      FUN_0046e598((int)param_1);
      bVar2 = FUN_00455928();
      local_10 = FUN_0046e068((int)param_1,bVar2 + 1);
    }
    param_1[0xb4] = uVar3 | 8;
  }
  else {
    param_1[0xb4] = uVar3 | 0x200;
  }
  local_14 = FUN_00445724(param_1);
  MVar8 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 0x2da),0x807,param_1[0xb4],
                          (DWORD_PTR)&local_14);
  param_1[0xbb] = MVar8;
  return;
}

