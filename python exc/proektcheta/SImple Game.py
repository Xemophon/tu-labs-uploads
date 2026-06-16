#Simple Game

#Libs
from random import randint
from time import sleep
#Colors
RED = '\033[91m'
GREEN = '\033[92m'
ORANGE = '\033[93m'
BLUE = '\033[94m'
MAGENTA = '\033[95m' 
CYAN = '\033[96m'
BOLD = '\033[1m'
RESET = '\033[0m'
#Monster art
MONSTER_ART = r"""
    __/\__
   ( O  O )
  ( \ -- / )
  \ \__/\ / /
   \ )  ( /
   /______\
  |________|         
"""

#Controllable template
class Cont():
    def __init__(self, health, damage, shield, mana):
         self.health = health
         self.damage = damage
         self.shield = shield
         self.mana = mana

    def _tdamage(self, attack, isSpell = False):
        if self.shield == 0 or isSpell == True:
            self.health -= attack
            print(f"  {RED}💥 Direct Hit! Took {round(attack)} damage.{RESET}")
        else:
            self.health -= attack * 0.4
            self.shield -= 1
            print(f"  {CYAN}🛡️ Shield Active! Took {round(attack * 0.4)} damage. Shield: {self.shield}{RESET}")

    def heal(self, potion):
        self.health += potion.heal
    
    def remana(self,potion):
        self.mana += potion.remana
    
    def shielding(self, shielding):
        self.shield += shielding.armor
    
    def equip(self, itemj):
        if itemj.power > 0:
            self.damage += itemj.power
        elif itemj.armor > 0:
            self.shield += itemj.armor

#Player
class Player(Cont):
    def __init__(self, health, damage, shield, mana):
        super().__init__(health, damage, shield, mana)
        self.max_health = 100

    def attack(self):
        attack = randint(self.damage - 15, self.damage)
        monster._tdamage(attack)
        print(f"  {GREEN}⚔️ You dealt {attack} damage.{RESET}")
    
    def spell(self, spell):
        mattack = randint(spell.atpower - 10, spell.atpower)
        monster._tdamage(mattack, isSpell = True)
        player.mana -= spell.exhaust
        print(f"{BLUE}✨ {spell.name} CAST!{RESET} The monster is struck by arcane energy!")
        print(f"  {RED}⚡ Damage Dealt: {mattack}{RESET} | Cost: {BLUE}{spell.exhaust} Mana{RESET}")

player = Player(100, 20, 10, 200)

#Monster
class Monster(Cont):
    def __init__(self, health, damage, shield, mana):
        super().__init__(health, damage, shield, mana)
        self.max_health = 150
    
    def attack(self):
        attack = randint(self.damage - 15, self.damage)
        player._tdamage(attack)
        print(f"  {RED}⚔️ Monster dealt {attack} damage.{RESET}")

monster = Monster(150, 30, 10, 200)

#Item templates
class Item():
    def __init__(self, name, power, quantity, heal, armor, remana):
         self.name = name
         self.power = power
         self.heal = heal
         self.armor = armor
         self.remana = remana
         self.quantity = quantity

class Weapon(Item):
    def __init__(self,name, power, quantity, heal = 0, armor = 0, remana = 0):
        super().__init__(name, power, quantity, heal, armor, remana)
        self.durability = 50

class Potions(Item):
    def __init__(self, name, heal, remana, quantity = 10, power = 0, armor = 0):
        super().__init__(name, power, quantity, heal, armor, remana)

class Armor(Item):
    def __init__(self, name, armor, quantity, remana = 0, power = 0, heal = 0):
        super().__init__(name, power, quantity, heal, armor, remana)

class Spell():
    def __init__(self,name, atpower, exhaust):
        self.atpower = atpower
        self.exhaust = exhaust
        self.name = name

#Objects of game
bround = 1   
sword = Weapon("GodSword", 20, 2)
potion1 = Potions("Balanced Rejuvenation", 10, 10, 15)
potion2 = Potions("FulHeal", 25, 0, 5)
potion3 = Potions("Remana", 0, 25, 5)
shield = Armor("Shield of Paladin", 15, 1)
armor = Armor("Yielding Armor", 40, 5)
fblas = Spell("Blast", 40, 30)
iblas = Spell("Icicle", 25, 10)
maxdop = Spell("Meteo Strike", 100, 150)

#Assigning Inventories
potions = [potion1, potion2, potion3]
global_potions = {}
for potion in potions:
    global_potions.update({potion.name : potion.quantity})

items_u = [shield, armor, sword]
global_items_dic = {}
for item in items_u:
    global_items_dic.update({item.name : item.quantity})

spells = [fblas, iblas, maxdop]
global_spells_l = []
for spell in spells:
    global_spells_l.append(spell.name)


#In-game funcs
def choice_f(cont, choice_f):
        if choice_f == 1:
            atks_func(cont)
        elif choice_f == 2:
            potion_func(cont)
        elif choice_f == 3:
            item_func(cont)

def atks_func(cont):
    if cont == player:
        print_banner("PLAYER ATTACK", color=GREEN, separator='-')
        print(f"  {RED}1. ⚔️ PHYSICAL ATTACK{RESET}")
        print(f"  {BLUE}2. ✨ MAGICAL SPELL{RESET}")
        atks = int(input("Select type (1 or 2): "))
        if atks == 1 or cont.mana <= 0:
            cont.attack()
        elif atks == 2 and cont.mana > 0:
            spells_l = global_spells_l
            for spell in spells:
                print(
                f"{MAGENTA}{BOLD}✧ Arcane Spell:{RESET} {MAGENTA}{spell.name}{RESET} "
                f"(Use {BLUE}{spell.exhaust}{RESET} Mana) — "
                f"Hits for {ORANGE}{spell.atpower} Damage{RESET}"
                    )
            spellc = int(input("Choose spell: "))
            cont.spell(spells[spellc - 1])
    elif cont == monster:
        print_banner("MONSTER SLASH", color=RED, separator='-')
        cont.attack()

def potion_func(cont):
    potions = [potion1, potion2, potion3]
    potion_l = global_potions
    if cont == player:
        print_banner("POTION INVENTORY", color=CYAN, separator='*')
        ind = 0
        for potion in potion_l.keys():
            print(
                f"{CYAN}{BOLD}✧ Potion :{RESET} {CYAN}{potion}{RESET} | {potion_l[potion]} left | "
                f"Returns {BLUE}{potions[ind].remana}{RESET} Mana | "
                f"Rejuvanates {GREEN}{potions[ind].heal} Health{RESET} |"
                )
            ind += 1
        potionc = int(input("Choose potion with number: "))
        print_banner("HEAL ACTION", color=GREEN, separator='-')
        (potions[potionc - 1]).quantity -= 1
        potion_l[(potions[potionc - 1]).name] -= 1
    elif cont == monster:
        print_banner("HEAL ACTION", color=GREEN, separator='-')
        potionc = randint(1,3)
    cont.heal(potions[potionc - 1])
    print(f"{GREEN}💚 REGENERATION SUCCESS!{RESET}")
    print(f"  {potions[potionc - 1].name} restored:")
    print(f"  ✨ {GREEN}+{potions[potionc - 1].heal} Health{RESET} | {BLUE}💧 +{potions[potionc - 1].remana} Mana{RESET}")
    if cont.health >= cont.max_health:
        cont.health = cont.max_health
        print(f"{ORANGE}🛡️ Health already MAXED ({int(cont.max_health)} HP)! Regeneration capped.{RESET}")
    for name in potion_l.keys():
        if potion_l[name] == 0:
            potion_l.pop(name)
            potions.pop(potionc - 1)
            break

def item_func(cont):
    print_banner("EQUIPMENT/ITEM USE", color=MAGENTA, separator='^')
    items_dic = global_items_dic
    for item in items_dic.keys():
        print(f"{ORANGE}{BOLD}✧ Item :{RESET} {ORANGE}{item}{RESET} | {items_dic[item]} left |")
    itemsc = int(input("Choose item with number: "))
    cont.equip(items_u[itemsc - 1])
    (items_u[itemsc - 1]).quantity -= 1
    items_dic[(items_u[itemsc - 1]).name] -= 1
    print(f"{GREEN}Equipped!{RESET}")
    for name in items_dic.keys():
        if items_dic[name] == 0:
            items_dic.pop(name)
            items_u.pop(itemsc - 1)
            break

def _generate_stat_line(cont):
    health_coef = cont.health / cont.max_health
    mana_coef = cont.mana / 200
    bar_length = 20
    if cont == player:
        pl_label = f"{GREEN}Player{RESET} " 
        health_color = GREEN if health_coef > 0.5 else ORANGE if health_coef > 0.25 else RED
        mana_color = BLUE
    else: # Monster
        pl_label = f"{RED}Monster{RESET}"
        health_color = GREEN if health_coef > 0.5 else ORANGE if health_coef > 0.25 else RED
        mana_color = BLUE
    # 1. Health Bar
    health_bar_filled = health_color + '█' * int(bar_length * health_coef) + RESET
    health_bar_empty = '░' * (bar_length - int(bar_length * health_coef))
    health_part = (
        f"{pl_label} Health: "
        f"{health_bar_filled}{health_bar_empty} "
        f"{int(cont.health):>3}/{cont.max_health:<3}"
    )
    # 2. Mana Bar
    mana_bar_filled = mana_color + '█' * int(bar_length * mana_coef) + RESET
    mana_bar_empty = '░' * (bar_length - int(bar_length * mana_coef))
    mana_part = (
        f"| Mana: {mana_bar_filled}{mana_bar_empty} "
        f"{int(cont.mana):>3}/200"
    )
    return health_part + " " + mana_part

def display_battle_status():
    print(MONSTER_ART) 
    print_banner("BATTLE STATS", color=BLUE, separator='~')
    monster_line = _generate_stat_line(monster)
    player_line = _generate_stat_line(player)
    monster_extra_stats = f"{RED}Damage: {monster.damage:<4} | Shield: {CYAN}{monster.shield}{RESET}"
    player_extra_stats = f"{GREEN}Damage: {player.damage:<4} | Shield: {CYAN}{player.shield}{RESET}"
    print(monster_line + f" {monster_extra_stats}")
    print(player_line + f" {player_extra_stats}")
    
    print(CYAN + "=" * 90 + RESET)

def print_banner(text, color=BLUE, separator="="):
    """Prints a centered, colorized banner."""
    length = 45
    fill = separator * ((length - len(text) - 2) // 2)
    print(f"{color}{fill} {text} {fill}{RESET}")

def print_splash_screen():
    print(CYAN + "=" * 50 + RESET)
    print(f"{CYAN}       {MAGENTA}SIMPLE CONSOLE RPG - BATTLE COMMENCE!{RESET}")
    print(CYAN + "=" * 50 + RESET)
    print(f"{RED}Your enemy appears...{RESET}")
    print(MONSTER_ART)
    sleep(1)

#Game Loop
print_splash_screen()
while player.health > 0 and monster.health > 0:
    try:
        print_banner(f"BATTLE ROUND {bround}", color=BLUE, separator='=')
        print_banner("ACTION PHASE", color=BLUE, separator='-')
        print(
            f"1. {RED}⚔️ ATTACK{RESET}     — Deal Damage\n"
            f"2. {GREEN}🧪 HEAL{RESET}       — Restore HP/Mana\n"
            f"3. {MAGENTA}🛡️ EQUIP/ITEM{RESET} — Gain Stats/Shield\n"
            f"4. {ORANGE}🏳️ SURRENDER{RESET}  — End Game"
        )
        print("-" * 45)
        choice_p = int(input("Choose action: "))
        if choice_p not in [1, 2, 3] :
            print_banner("ACTION: SURRENDERED", color=ORANGE, separator='~')
            break
        else:
            choice_f(player, choice_p)
            sleep(2)
            if monster.health <= 0:
                print_banner("YOU WON", color=GREEN, separator='*')
                break
            print_banner("MONSTER TURN", color=RED, separator='#') 
            choice_m = randint(1, 2)
            choice_f(monster, choice_m)
            display_battle_status()
            sleep(2)
            if player.health <= 0:
                print_banner("YOU LOST", color=RED, separator='*')
                break
            bround += 1 

    #Error Handling
    except ValueError:
        print("Inputted wrong number, retard")
    except TypeError:
        print("The dev butchered the code")
    except IndexError:
        print("Naughty naughty, no such item there")

#TODO Spell Rework with afflictions