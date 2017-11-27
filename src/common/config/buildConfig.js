/**
 * Build-time configuration. End-users can't change these parameters.
 * @prop {Object[]} defaultTeams
 * @prop {string} defaultTeams[].name - The tab name for default team.
 * @prop {string} defaultTeams[].url - The URL for default team.
 * @prop {string} helpLink - The URL for "Help->Learn More..." menu item.
 *                           If null is specified, the menu disappears.
 * @prop {boolean} enableServerManagement - Whether users can edit servers configuration.
 *                                          Specify at least one server for "defaultTeams"
 *                                          when "enableServerManagement is set to false
 */
const buildConfig = {
  defaultTeams: [
    {
      name: 'uChat',
      url: 'https://uchatx.uberinternal.com'
    }
  ],
  helpLink: 'https://team.uberinternal.com/pages/viewpage.action?pageId=123151892',
  enableServerManagement: false
};

module.exports = buildConfig;
