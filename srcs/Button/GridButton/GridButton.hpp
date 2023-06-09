/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   GridButton.hpp                                        by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef GRIDBUTTON_HPP
# define GRIDBUTTON_HPP

# include "../Button.hpp"
# include "../../Texture/Texture.hpp"
# include "../../Editor/Editor.hpp"

class	GridButton : public Button
{
	public:
				GridButton(void);
				~GridButton(void);
				GridButton(Texture *texture);
				GridButton(Texture *texture, SDL_Color &color);
				GridButton(GridButton &toCopy);
		GridButton	&operator=(GridButton &toCopy);
		bool		&getPlayer(void);
		SDL_Color	&getColor(void);
		void		setColor(SDL_Color &color);
		void		unsetPlayer(void);
		void		activate(void);
		void		render(void);
	
	private:
		SDL_Color	_color;
		bool		_player;
		Texture		*_playerTexture;
};

#endif
