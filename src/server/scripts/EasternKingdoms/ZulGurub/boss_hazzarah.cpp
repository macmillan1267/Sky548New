/*
 * Copyright (C) 2011-2015 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2015 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "instance_zulgurub.h"

enum Yells
{
};

enum Spells
{
};

enum Events
{
};

class boss_hazzarah : public CreatureScript
{
    public:
        boss_hazzarah() : CreatureScript("boss_hazzarah") { }

        struct boss_hazzarahAI : public BossAI
        {
            boss_hazzarahAI(Creature* creature) : BossAI(creature, DATA_HAZZARAH)
            {
            }

            void Reset() override
            {
            }

            void EnterCombat(Unit* /*who*/) override
            {
            }

            void JustDied(Unit* /*killer*/) override
            {
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
                */

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_hazzarahAI(creature);
        }
};

void AddSC_boss_hazzarah()
{
    new boss_hazzarah();
}
